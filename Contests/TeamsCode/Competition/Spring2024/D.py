n=int(input())
a=list(map(int,input().split()))
fib=[1,1]

q=0
ans=[]
cur=1
while q < n:
    print(cur)
    if a[q] > cur:
        fib.append(fib[-1]+fib[-2])
        cur+=fib[-1]
    else:
        q+=1
        ans.append('T' if len(fib) % 2 == 0 else 'K')
    print(fib)
print(''.join(ans))