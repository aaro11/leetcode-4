-module(test).
-export([aa/1,fun1/0]).
-record (ok,{id, f}).

-define(MOVE_NUM,6).

aa(#ok{id = Id}) ->
	{#ok.id}.

fun1() ->
	?MOVE_NUM.
