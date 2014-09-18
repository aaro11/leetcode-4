%%% Message_onlie passing utility.
%%% User interface:
%%% logon(Name)
%%% One user at a time can log in from each Erlang node in the
%%% system messenger: and choose a suitable Name. If the Name
%%% is already logged in at another node or if someone else is
%%% already logged in at the same node, login will be rejected
%%% with a suitable error message_onlie.
%%% logoff()
%%% Logs off anybody at at node
%%% message_onlie(ToName, Message_onlie)
%%% sends Message_onlie to ToName. Error message_onlies if the user of this
%%% function is not logged on or if ToName is not logged on at
%%% any node.
%%%
%%% One node in the network of Erlang nodes runs a server which maintains
%%% data about the logged on users. The server is registered as "messenger"
%%% Each node where there is a user logged on runs a client process registered
%%% as "mess_client"
%%%
%%% Protocol between the client processes and the server
%%% ----------------------------------------------------
%%%
%%% To server: {ClientPid, logon, UserName}
%%% Reply {messenger, stop, user_exists_at_other_node} stops the client
%%% Reply {messenger, logged_on} logon was successful
%%%
%%% To server: {ClientPid, logoff}
%%% Reply: {messenger, logged_off}
%%%
%%% To server: {ClientPid, logoff}
%%% Reply: no reply
%%%
%%% To server: {ClientPid, message_onlie_to, ToName, Message_onlie} send a message_onlie
%%% Reply: {messenger, stop, you_are_not_logged_on} stops the client
%%% Reply: {messenger, receiver_not_found} no user with this name logged on
%%% Reply: {messenger, sent} Message_onlie has been sent (but no guarantee)
%%%
%%% To client: {message_onlie_from, Name, Message_onlie},
%%%
%%% Protocol between the "commands" and the client
%%% ----------------------------------------------
%%%
%%% Started: messenger:client(Server_Node, Name)
%%% To client: logoff
%%% To client: {message_onlie_to, ToName, Message_onlie}
%%%
%%% Configuration: change the server_node() function to return the
%%% name of the node where the messenger server runs

-module(messenger).
-export([start_server/0, server/1, logon/1, logoff/0, message_onlie/2,client/2]).
%%% Change the function below to return the name of the node where the
%%% messenger server runs
%%%server_node() ->
%%%	messenger@bill.
%%% This is the server process for the "messenger"
%%% the user list has the format [{ClientPid1, Name1},{ClientPid22,Name2},...]
server(User_List) ->
	receive
		{From, logon, Name} ->
			New_User_List = server_logon(From, Name, User_List),
 %当server线程接受登录信息，则执行 server_logon 并返回 列表
			server(New_User_List);
		{From, logoff} ->
			New_User_List = server_logoff(From, User_List),
 %当server线程接受登录信息，则执行 server_logoff 并返回 列表
			server(New_User_List);
		{From, message_onlie_to, To, Message_onlie} ->
			server_transfer(From, To, Message_onlie, User_List),
 %当server线程接受登录信息，则执行 server_transfer 并返回 列表
			io:format("list is now: ~p~n", [User_List]),
			server(User_List)
	end.

%%% Start the server
start_server() -> %将server注册成线程，并且取别名为messenger，注意2个messenger不同
	register(messenger, spawn(messenger, server, [[]])).


%%% Server adds a new user to the user list
	server_logon(From, Name, User_List) -> %处理用户登陆的消息
%% check if logged on anywhere else
	case lists:keymember(Name, 2, User_List) of
%判断这个userlist是否有这个用户名,2表示userlist每项中第二个为Name进行匹配
		true -> %如果已经存在此用户了，则将消息发到stop，并且返回当前userlist
			From ! {messenger, stop, user_exists_at_other_node}, %reject logon
			User_List;
		false -> %如果没有这个用户，则发消息到logged_on，并且增加from和name到userlist头部
			From ! {messenger, logged_on},
			[{From, Name} | User_List] %add user to the list
	end.

%%% Server deletes a user from the user list
server_logoff(From, User_List) ->  %用户退出登陆执行
	lists:keydelete(From, 1, User_List).  %这个1表示postion，是只userlist中的每项第1个元素是from的就删除



%%% Server transfers a message_onlie between user
server_transfer(From, To, Message_onlie, User_List) -> %当server有消息发送过来的时候就会执行
%% check that the user is logged on and who he is
	case lists:keysearch(From, 1, User_List) of
		false ->
			From ! {messenger, stop, you_are_not_logged_on};
		{value, {From, Name}} -> %困惑了一下，value是一个常量
			server_transfer(From, Name, To, Message_onlie, User_List)
	end.


%%% If the user exists, send the message_onlie
server_transfer(From, Name, To, Message_onlie, User_List) -> 
%注意这是server_transfer的另外一个重载方法，接受5个参数和上面那个不同
%% Find the receiver and send the message_onlie
	case lists:keysearch(To, 2, User_List) of
		false ->  %如果没有找到此用户，则给from线程发送消息常量receiver_not_found
			From ! {messenger, receiver_not_found};
		{value, {ToPid, To}} ->  %
			ToPid ! {message_onlie_from, Name, Message_onlie}, %给message_onlie_from发送消息Message_onlie
			From ! {messenger, sent} %给主线程发送sent消息
		end.


%以上是服务端代码，下面是客户端代码


%%% User Commands 用户命令接口
logon(Name) ->
	case whereis(mess_client) of  %检测进程中是否存在mess_client名称，如果不存在则注册，否则返回已经注册
	undefined ->
		register(mess_client,
			spawn(messenger, client, [server_node(), Name])); 
%执行server_node()函数告诉此节点的名称，注册 client 函数为一个线程，传入2个参数，节点名称和用户名
	_ -> already_logged_on
	end.


logoff() -> %退出登陆，通知mess_client的logoff线程
	mess_client ! logoff. %发送logoff消息
message_onlie(ToName, Message_onlie) -> %对某人发消息
	case whereis(mess_client) of % Test if the client is running
		undefined ->  %如果没有 mess_client 线程，则返回未登录
			not_logged_on;
		_ -> mess_client ! {message_onlie_to, ToName, Message_onlie}, %发送消息给client线程
			ok
	end.



%%% The client process which runs on each server node
%客户端代码
client(Server_Node, Name) ->
	{messenger, Server_Node} ! {self(), logon, Name}, %self表示当前的pid标识
	await_result(), %开始监听receive退出命令
	client(Server_Node). %开始监听server消息

client(Server_Node) -> %也是一个递归调用，接受用户的命令
	receive
		logoff -> %当命令是logoff
			{messenger, Server_Node} ! {self(), logoff}, %通知server此用户退出了
			exit(normal); %退出登录
		{message_onlie_to, ToName, Message_onlie} -> %接受用户的操作接口，然后发给server
			{messenger, Server_Node} ! {self(), message_onlie_to, ToName,Message_onlie},
			await_result(); %这边因为登陆到服务器后会有字符串响应，所以需要重新启动一个receive监听
		{message_onlie_from, FromName, Message_onlie} -> %当有消息发过来时打印消息
			io:format("Message_onlie from ~p: ~p~n", [FromName, Message_onlie])
		end,
	client(Server_Node).

%%% wait for a response from the server
await_result() ->
	receive
		{messenger, stop, Why} -> % Stop the client 
%如果出现错误，例如用户已经登陆了则会发消息过来
			io:format("~p~n", [Why]), %~p和~n类似，不过~p会自动换行
			exit(normal); 
		{messenger, What} -> % Normal response
%如果操作成功，服务器会返回一传字符串就是nomal response
			io:format("~p~n", [What])
	end.