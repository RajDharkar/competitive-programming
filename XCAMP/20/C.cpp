n = int(raw_input())  
a, b = map(int, raw_input().split())
ministers = [tuple(map(int, raw_input().split())) for _ in range(n)]
ministers.sort(key=lambda x: x[0] * x[0] - x[1] * x[1])

ans = 0
product = a

for x, y in ministers:
    assert y != 0 
    ans = max(ans, int(product / y))  #
    product *= x

print ans 
