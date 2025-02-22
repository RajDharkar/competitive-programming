t = int(input())
for _ in range(t):
    l = list(map(float, input().split()))
    for num in l:
        num -= 180
        num %= 360
    print(f'{" ".join(f"{x:06.2f}" for x in l)}')
