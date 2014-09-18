-module(mth).
-export([fac/1]).
-export ([echo/2]).

fac(0) -> 1;
fac(N) -> N * fac(N - 1).

echo(N, string) -> N.