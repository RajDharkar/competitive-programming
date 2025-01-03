from collections import deque

DX = [0, 0, -1, 1]
DY = [1, -1, 0, 0]

def solve():
    n, q = map(int, input().split())

    grid = [['?'] * n for _ in range(n)]
    fx = []
    esc = [[False] * n for _ in range(n)]
    ec =0
    qx = deque()
    for _ in range(q):
        x, y, d = input().split()
        fx.append((int(x)-1, int(y) - 1, d))
    for x, y, d in fx:
        grid[x][y] = d

    def mark(r, c):
        nonlocal ec
        if not esc[r][c]:
            esc[r][c] = True
            ec += 1
            qx.append((r, c))

    def rebuild():
        adj = [[[] for _ in range(n)] for _ in range(n)]
        for x in range(n):
            for y in range(n):
                d = grid[x][y]
                if d == '?':
                    for k in range(4):
                        nx, ny  = x   + DX[k], y + DY[k]
                        if 0 <= nx < n and 0 <= ny < n:
                            adj[nx][ny].append((x, y))
                else:
                    nx, ny = x, y #lol ny
                    if d == 'R': ny += 1
                    elif d == 'L': ny -= 1
                    elif d == 'U': nx -= 1
                    elif d == 'D': nx += 1
                    if 0 <= nx < n and 0 <= ny < n:
                        adj[nx][ny].append((x, y))
        return adj

    adj = rebuild()



    for x in range(n):
        for y in range(n):
            d = grid[x][y]
            if d == '?':
                if x == 0 or x == n - 1 or y == 0 or y == n - 1:
                    mark(x, y)
            elif (d == 'R' and y == n - 1) or (d == 'L' and y == 0) or (d == 'U' and x == 0) or (d == 'D' and x == n - 1):
                mark(x, y)

    while qx:
        cr, cc = qx.popleft()
        for nx, ny in adj[cr][cc]:
            if not esc[nx][ny]:
                mark(nx, ny)

    res = [0] * q
    res[q - 1] = n * n - ec

    for d in range(q - 1, 0, -1):
        x, y, _ = fx[d]
        grid[x][y] = '?'
        adj = rebuild()  # buillllllllllld again
        if not esc[x][y]:
            if x == 0 or x == n - 1 or y == 0 or y == n - 1:
                mark(x, y)
            else:
                for k in range(4):
                    nx, ny = x + DX[k], y + DY[k]
                    if 0 <= nx < n and 0 <= ny < n and esc[nx][ny]:
                        mark(x, y)
            while qx:
                cr, cc = qx.popleft()
                for nx, ny in adj[cr][cc]:
                    if not esc[nx][ny]:
                        mark(nx, ny)

        res[d - 1] = n * n - ec
    for ans in res:
        print(ans)
solve()
