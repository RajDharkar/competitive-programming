t = int(input())

def is_palindrome():
    line = input().lower()
    l = 0
    r = len(line) - 1
    while l <= r:
        if line[l] != line[r]:
            return False
        l+=1
        r-=1
    return True
for _ in range(t):
    n = int(input())
    works = True
    l = []
    for x in range(n):
        if not is_palindrome():
            works = False
            l.append(x + 1)
    if works:
        print("True")
    else:
        print(f"False - {f"{", ".join([str(token) for token in l])}"}")