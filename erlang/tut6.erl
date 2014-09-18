-module(tut6).
-export([list_max/1]).

list_max([Head|Rest]) -> 
 	list_max(Rest, Head). 


list_max([], Res) -> 
 	Res;

list_max([Head|Rest], Result_so_far) when Head > Result_so_far ->	%when这部分叫守卫如果为真执行 否则执行下面的
 	list_max(Rest, Head);

list_max([Head|Rest], Result_so_far) -> 
 	list_max(Rest, Result_so_far).

 %先把第一个拿出来 和第二个比
 %如果第一个d大 在和 第三个比
 %如果第一个比第二个大 拿出第二个 和第三个比
 %一直比较到结束 ，（表为空），打印出 拿出来比较的数 

 % ; 这说明这个函数没有结束
 % . 结束，说明本函数没有其它部分了。

 % 函数本身就存在递归
