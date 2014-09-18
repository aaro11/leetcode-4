%%%----FILE mess_interface.hrl----%%%Message interfacebetweenclient and server and clientshell for
%%%messengerprogram
%%%Messages from Client toserverreceivedinserver/1function.

% 记录(Records) 等效 {logon,{client_pid,username}}.
-record(logon,{client_pid,username}).
-record(message,{client_pid, to_name,message}).
%%% {'EXIT', ClientPid,Reason}  (client terminated orunreachable.
%%%Messages fromServer to Client,received in await_result/0function 
-record(abort_client,{message}).
%%%Messages are:user_exists_at_other_node,
%%%         you_are_not_logged_on
-record(server_reply,{message}).

%%%Messages are:logged_on
%%%        receiver_not_found
%%%        sent(Message has beensent(noguarantee)
%%%Messages fromServer to Clientreceived inclient/1 function
-record(message_from,{from_name, message}).
%%%Messages fromshell toClientreceivedinclient/1function
%%%spawn(mess_client,client,[server_node(), Name])
-record(message_to,{to_name, message}).
%%%logoff
%%%----ENDFILE----