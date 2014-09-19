%%%----FILE user_interface.erl----%%% User interfacetothemessenger program
%%%login(Name)
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
-module(user_interface).
-export([logon/1,logoff/0,message/2]).
-include("mess_interface.hrl").
-include("mess_config.hrl").

logon(Name) ->
	case whereis(mess_client)of 
		undefined->
			register(mess_client,
		spawn(mess_client,client,[?server_node, Name]));
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
				mess_client !#message_to{to_name=ToName,message=Message},
				ok
	end.
%%%----ENDFILE----