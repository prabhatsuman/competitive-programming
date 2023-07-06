for _ in range(int(input())):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    p=1
    for i in a:
        p*=i
    if p%k==0:
        print("YES")
    else:
        print("NO")
        