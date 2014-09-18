-module(ping_1).
-export([start/0, ping/1]).

ping(0) ->
	pong !finished,
	io:format("ping finished~n", []);

ping(N) ->
	pong ! {ping,self()},
	receive
		pong ->
		io:format("Ping received pong~n",[])
	end,
	ping(N- 1).

start() ->
	spawn(ping_1, ping, [3]).