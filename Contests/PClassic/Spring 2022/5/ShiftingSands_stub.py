def shiftingsands(board, moves):
    pass


# Do not modify below this line
if __name__ == "__main__":
    tests = int(input())
    for test in range(tests):
        board = []
        for i in range(4):
            line = input()
            board.append([])
            line = line.split(" ")
            for j in range(4):
                board[i].append(int(line[j]))

        moves = input().strip().split(" ")

        output = shiftingsands(board, moves)
        outputStr = ""
        for i in range(4):
          for j in range(4):
            outputStr += str(output[i][j])
            if j < 3:
              outputStr += ' '
          if i < 3:
            outputStr += '\n'
 
        print(outputStr)
