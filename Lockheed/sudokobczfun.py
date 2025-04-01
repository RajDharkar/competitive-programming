#chatgpt  sol, bit idea coo lthough

def solve():
    grid = []
    for i in range(9):
        app = []
        line = input()
        for character in line:
            if character == '_':
                app.append(0)
            else:
                app.append(int(character))
        grid.append(app)

    ans = solveSudoku(grid)
    for line in ans:
        print("".join(str(x) for x in line))

# Python Program to solve Sudoku problem

def isSafe(mat, i, j, num, row, col, box):
    if (row[i] & (1 << num)) or (col[j] & (1 << num)) or (box[i // 3 * 3 + j // 3] & (1 << num)):
        return False
    return True

def sudokuSolverRec(mat, i, j, row, col, box):
    n = len(mat)

    # base case: Reached nth column of last row
    if i == n - 1 and j == n:
        return True

    # If reached last column of the row go to next row
    if j == n:
        i += 1
        j = 0

    # If cell is already occupied then move forward
    if mat[i][j] != 0:
        return sudokuSolverRec(mat, i, j + 1, row, col, box)

    for num in range(1, n + 1):
        # If it is safe to place num at current position
        if isSafe(mat, i, j, num, row, col, box):
            mat[i][j] = num

            # Update masks for the corresponding row, column and box
            row[i] |= (1 << num)
            col[j] |= (1 << num)
            box[i // 3 * 3 + j // 3] |= (1 << num)

            if sudokuSolverRec(mat, i, j + 1, row, col, box):
                return True

            # Unmask the number num in the corresponding row, column and box masks
            mat[i][j] = 0
            row[i] &= ~(1 << num)
            col[j] &= ~(1 << num)
            box[i // 3 * 3 + j // 3] &= ~(1 << num)

    return False

def solveSudoku(mat):
    n = len(mat)
    row = [0] * n
    col = [0] * n
    box = [0] * n

    # Set the bits in bitmasks for values that are initially present
    for i in range(n):
        for j in range(n):
            if mat[i][j] != 0:
                row[i] |= (1 << mat[i][j])
                col[j] |= (1 << mat[i][j])
                box[(i // 3) * 3 + j // 3] |= (1 << mat[i][j])

    sudokuSolverRec(mat, 0, 0, row, col, box)
    
    return mat  # Return the solved grid

t = int(input())
for x in range(t):
    solve()
