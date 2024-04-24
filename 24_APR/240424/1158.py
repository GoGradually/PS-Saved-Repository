from collections import deque

a, b = map(int, input().split())
queue = deque()
for i in range(1, a+1):
    queue.append(i)
list = []
for i in range(a):
    for j in range(b-1):
        temp = queue.popleft()
        queue.append(temp)
    list.append(queue.popleft())

print("<", end='')
for index, i in enumerate(list):
    print(i, end='')
    if index is a - 1 :
        print(">")
    else:
        print(", ", end='')