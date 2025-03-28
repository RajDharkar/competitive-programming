t = int(input())

for _ in range(t):
    a, b = map(int, input().split(","))
    while True:
        if b > a: 
            a, b = b, a
        print(str(a) + "-" + str(b) + "=" + str(a-b))
        prev = a
        a=b
        b = prev-b
        if a == b:
            print(str(a) + "-" + str(b) + "=0")
            break
    if a == 1 and b == 1:
        print("COPRIME")
    else:
        print("NOT COPRIME")

        