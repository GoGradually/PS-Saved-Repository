def solve():
    ret = True
    n, m = map(int, input().split())
    for i in range(m):
        tt = int(input())
        listed = list(map(int, input().split()))
        for j in range(tt - 1):
            if listed[j] < listed[j+1]:
                ret = False
    return ret

if solve():
    print("Yes")
else:
    print("No")