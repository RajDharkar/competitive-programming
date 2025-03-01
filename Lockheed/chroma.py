t = int(input())

def dist(a, b, c, d, e, f):
    return (a - d) * (a - d) + (b - e) * (b - e) + (c - f) * (c - f)

for _ in range(t):
    a, b, c, t, e, d, f, g, h, i = map(int, input().split())
    # print(a, b, c, t, e, d, f, g, h, i)
    di = dist(e, d, f, a, b, c)
    # print(di)
    if di <= t*t:
        print(g, h, i)
    else:
        print(e, d, f)

