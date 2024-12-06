t = int(input())

for _ in range(t):
    x, y = map(int, input().split())
    line = list(map(str, input().split()))
    charactersUsed = 0
    lineAt = 1  
    answer = ''
    lineList = []
    will_not_fit = False
    
    for word in line:
        if charactersUsed + len(word) > x:
            if lineAt + 1 > y:
                print("WILL NOT FIT")
                will_not_fit = True
                break
            else:
                lineAt += 1
                charactersUsed = len(word) + 1
                lineList.append(answer.rstrip())
                answer = word + ' '
        else:
            charactersUsed += len(word) + 1
            answer += word + ' '
    
    if not will_not_fit:
        lineList.append(answer.rstrip())
        for line in lineList:
            print(line)
