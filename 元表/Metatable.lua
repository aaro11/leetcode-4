


a = {}
function a:Func()
   print("simonw")
end
c = {}
c.__call = function(t)
   print("Start")
   t.Func()
   print("End")
end
setmetatable(a, c)
a()

for k,v in pairs(a) do
	print(k,v)
end







-- local Bird = {CanFly = true}

-- function Bird:New()
--     local b = {}
--     setmetatable(b, {__index = self})
--     return b
-- end

-- local Ostrich = Bird:New() --Bird.CanFly is true, Ostrich.CanFly is true

-- for k,v in pairs(Ostrich) do
-- 	print(k,v)
-- end
-- Ostrich.CanFly = false --Bird.CanFly is true, Ostrich.CanFly is false











-- --定义2个表
-- a = {5, 6}
-- b = {7, 8}

-- --用c来做Metatable
-- c = {}


-- --重定义加法操作
-- c.__add = function(op1, op2)
-- 			   for _, item in ipairs(op2) do
-- 			      table.insert(op1, item)
-- 			   end
-- 			   return op1
-- 			end

-- --将a的Metatable设置为c
-- setmetatable(a, c)


-- --d现在的样子是{5,6,7,8}
-- d = a + b

-- for k,v in pairs(d) do
-- 	print(k,v)
-- end