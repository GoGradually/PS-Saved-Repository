n = int(input())
listed = list(map(int, input().split()))
stack = []
now = 1
for i in listed:
    while stack and stack[-1] is now:
        now += 1
        stack.pop()
    if i is now:
        now += 1
        continue
    stack.append(i)
    
while stack and stack[-1] is now:
    now += 1
    stack.pop()

if stack :
    print("Sad")
else:
    print("Nice")
