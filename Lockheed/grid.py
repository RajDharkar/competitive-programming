t = int(input())

for _ in range(t):
    dir = [[-1, -1], [-1, 0], [-1, 1], [0, 1], [0, -1], [1, 1], [1, 0], [1, -1]]

    x = int(input())
    grid = []
    for i in range(10):
        grid.append(list(input()))

    for i in range(x):
        moves = [[0] * 10 for i in range(10)]
        for i in range(10):
            for j in range(10):

                count = 0
                for dx, dy in dir:
                    x = i + dx
                    y = j + dy
                    if x >= 0 and y >= 0 and x < 10 and y < 10:
                        if grid[x][y] == "1":
                            count += 1

                if count <= 1 and (grid[i][j] == "1"):
                    moves[i][j] = "0"
                elif count == 2 and (grid[i][j] == "1"):
                    moves[i][j] = "1"
                elif count == 3:
                    moves[i][j] = "1"
                elif count >= 4:
                    moves[i][j] = "0"

        for i in range(10):
            for j in range(10):
                grid[i][j] = moves[i][j]

    for line in grid:
        print("".join([str(token) for token in line]))

        # print()
        # print()
        # print()