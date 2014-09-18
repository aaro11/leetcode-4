-module(pong_1).
-export([start/0, pong/0]).

pong()->
	receive
		finished ->
			io:format("Pong finished~n", []);
		{ping,Ping_PID} ->
			io:format("Pong received ping~n",[]),
			Ping_PID !pong,
			pong()
	end.

start() ->
	register(pong,spawn(pong_1, pong, [])).
