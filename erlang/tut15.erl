-module(tut15).
-export([start/0,ping/2,pong/0]).

ping(0,Pong_PID)->
	Pong_PID !finished,
	io:format("ping finished~n", []);

ping(N,Pong_PID)->
	Pong_PID ! {ping,self()},
	receive
		pong ->
		io:format("Ping received pong~n",[])
	end,
	ping(N- 1,Pong_PID).	%递归


pong()->
	receive
		finished ->
			io:format("Pong finished~n", []);
		{ping,Ping_PID} ->
			io:format("Pong received ping~n",[]),
			Ping_PID !pong,		%发消息
			pong() %在在收到消息后继续递归 本函数 在receive那里等着收消息
	end.

start() ->
	Pong_PID =spawn(tut15,pong,[]),
	spawn(tut15, ping,[3,Pong_PID]).