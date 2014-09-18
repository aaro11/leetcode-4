%%%----FILE mess_server.erl----%%%This is the serverprocessofthemessneger service
-module(mess_server).
-export([start_server/0, server/0]).
-include("mess_interface.hrl").

server() ->
	process_flag(trap_exit,true),
	server([]).
%%%the user listhastheformat [{ClientPid1, Name1},{ClientPid22,Name2},...]

server(User_List)->
	io:format("User list = ~p~n",[User_List]),
	receive
		#logon{client_pid=From,username=Name}->
			New_User_List =server_logon(From, Name, User_List),
			server(New_User_List);
		{'EXIT', From,_}->
			New_User_List =server_logoff(From, User_List),
			server(New_User_List);
		#message{client_pid=From,to_name=To,message=Message}->
			server_transfer(From,To,Message, User_List),
			server(User_List)
	end.

%%%Starttheserver
start_server()->
	register(messenger,spawn(?MODULE,server,[])).

%%%Serveradds anewusertotheuserlist
server_logon(From, Name, User_List) ->
%%check if loggedonanywhereelse
	case lists:keymember(Name,2, User_List) of
		true ->
			From !#abort_client{message=user_exists_at_other_node},
			User_List;
		false->
			From !#server_reply{message=logged_on},
			link(From),
			[{From, Name} | User_List]     %adduser tothelist
	end.
%%%Serverdeletesa userfromtheuser list
server_logoff(From, User_List)->
	lists:keydelete(From,1, User_List).

%%%Servertransfers a messagebetweenuser
server_transfer(From,To,Message, User_List)->
%%check thattheuserislogged on and who heis
	case lists:keysearch(From,1, User_List) of
		false->
			From !#abort_client{message=you_are_not_logged_on};
		{value, {_, Name}}->
			server_transfer(From, Name,To,Message, User_List)
	end.

%%%Iftheuser exists,send the message
server_transfer(From, Name,To,Message, User_List) ->
	%%Find the receiver and sendthemessage
	case lists:keysearch(To, 2, User_List)of
		false->
			From !#server_reply{message=receiver_not_found};
		{value, {ToPid,To}} ->
			ToPid !#message_from{from_name=Name,message=Message},
			From !#server_reply{message=sent}
	end.
%%%----ENDFILE---