c = coroutine.create(function()
        a = mysin(30 + 10);
        print(a);
end)

print(c)

coroutine.resume(c)
