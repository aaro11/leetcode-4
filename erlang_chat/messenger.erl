%%%Message passing utility. 
%%% User interface:
%%%logon(Name)
%%%  One user at atimecanloginfromeach Erlangnode inthe
%%%  systemmessenger:andchoose a suitable Name.If the Name
%%%  isalreadyloggedin at another node or ifsomeoneelse is
%%%  alreadyloggedinat the samenode,loginwillberejected

%%%  with a suitable errormessage.
%%%logoff()
%%%    Logs off anybody at atnode
%%%message(ToName,Message)
%%%  sendsMessageto ToName. Errormessages iftheuser ofthis 
%%%  function is not loggedonor if ToNameisnotlogged on at
%%%  anynode.
%%%
%%%One node in the network ofErlangnodes runs a serverwhich maintains
%%%data abouttheloggedon users. The serverisregistered as "messenger"
%%%Each nodewhere thereis a user loggedonrunsa client process

%%%registered
%%%as "mess_client"
%%%
%%%Protocol between the client processesandtheserver
%%%----------------------------------------------------%%%
%%%Toserver: {ClientPid,logon, UserName}
%%%Reply {messenger,stop,user_exists_at_other_node}stops the client
%%%Reply {messenger,logged_on} logonwassuccessful
%%%
%%%Toserver: {ClientPid,logoff}
%%%Reply: {messenger,logged_off}
%%%
%%%Toserver: {ClientPid,logoff}
%%%Reply:noreply
%%%
%%%Toserver: {ClientPid,message_to,ToName,Message}send a message
%%%Reply: {messenger,stop, you_are_not_logged_on}stopstheclient
%%%Reply: {messenger,receiver_not_found}nouserwith this namelogged on
%%%Reply: {messenger,sent} Message has beensent(but noguarantee)
%%%
%%%Toclient: {message_from, Name,Message},
%%%
%%%Protocol between the "commands"and the client
%%%----------------------------------------------%%%
%%%Started: messenger:client(Server_Node, Name)
%%%Toclient:logoff
%%%Toclient: {message_to,ToName,Message}
%%%
%%%Configuration:changetheserver_node() function to returnthe
%%%name of the node wherethemessenger server runs

-module(messenger).
-export([start_server/0, server/1,logon/1,logoff/0,message/2,client/2]).
%%%Changethefunction belowto return the name of the node wherethe
%%%messengerserver runs
server_node()->
	messenger@bill.
	%%%This is the serverprocessforthe "messenger"
	%%%the user listhastheformat [{ClientPid1, Name1},{ClientPid22,
	Name2},...]
	server(User_List)->
		receive
	{From,logon, Name}->
		New_User_List =server_logon(From, Name, User_List),
		server(New_User_List);
	{From,logoff}->
		New_User_List =server_logoff(From, User_List),
		server(New_User_List);
	{From,message_to,To,Message}->
		server_transfer(From,To,Message, User_List),
		io:format("list isnow: ~p~n",[User_List]),
		server(User_List)
	end.
%%%Starttheserver
start_server()->
	register(messenger,spawn(messenger, server, [[]])).

%%%Serveradds anewusertotheuserlist
server_logon(From, Name, User_List) ->
	%%check if loggedonanywhereelse
	case lists:keymember(Name,2, User_List) of
		true ->
			From ! {messenger,stop, user_exists_at_other_node},  %reject
			logon
			User_List;
		false->
			From ! {messenger,logged_on},
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
			From ! {messenger,stop, you_are_not_logged_on};
		{value, {From, Name}}->
			server_transfer(From, Name,To,Message, User_List)
	end.

%%%Iftheuser exists,send the message
server_transfer(From, Name,To,Message, User_List) ->
	%%Find the receiver and sendthemessage
	case lists:keysearch(To, 2, User_List)of
		false->
			From ! {messenger,receiver_not_found};
		{value, {ToPid,To}} ->
			ToPid ! {message_from, Name, Message},
			From ! {messenger,sent}
	end.
%%% User Commands
logon(Name) ->
	case whereis(mess_client)of 
		undefined->
			register(mess_client,
			spawn(messenger,client,[server_node(), Name]));
		_->
			already_logged_on
	end.

logoff() ->
	mess_client !logoff.

message(ToName,Message) ->
	case whereis(mess_client)of %Test iftheclientis running
		undefined->
			not_logged_on;
		_->
			mess_client ! {message_to,ToName,Message},
			ok
	end.
%%%The clientprocesswhich runson eachserver node
client(Server_Node, Name)->
	{messenger,Server_Node} ! {self(),logon, Name},
	await_result(),
	client(Server_Node).

client(Server_Node) ->
	receive
		logoff->
			{messenger,Server_Node} ! {self(),logoff},
			exit(normal);
		{message_to, ToName, Message}->
			{messenger,Server_Node} ! {self(),message_to,ToName, Message},
			await_result();
		{message_from,FromName, Message}->
			io:format("Messagefrom ~p: ~p~n",[FromName,Message])
	end,
	client(Server_Node).
%%%wait for a response from the server
await_result()->
	receive
		{messenger,stop,Why}-> %Stop the client 
			io:format("~p~n",[Why]),
			exit(normal);
		{messenger,What}->  % Normalresponse
			io:format("~p~n",[What])
	end.