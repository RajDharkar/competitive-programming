from datetime import datetime, timedelta

def solve():
    friendly, n = input().split()
    friendly = friendly == "TRUE"
    n = int(n)

    times = []
    for _ in range(n):tye
        hours, minutes = map(int, input().split(":"))
        total_minutes = hours * 60 + minutes  
        times.append(total_minutes)

    if friendly:
        return "NONE" 
    ans = 0
    if n >= 12:
        ans = max(ans, 1)
    if n >= 24:
        ans = max(ans, 2)
    if n >= 36:
        ans = max(ans, 3)
    num_entries = 1  
    longest_streak = 1
    current_streak = 1

    for i in range(1, n):
        if times[i] - times[i - 1] > 15:  
            num_entries += 1
            current_streak = 1
        else:
            current_streak += 1
            longest_streak = max(longest_streak, current_streak)
    if num_entries >= 4:
        ans = max(ans, 2)
    if num_entries >= 8:
        ans = max(ans, 3)
    if longest_streak >= 4:
        ans = max(ans, 1)
    if longest_streak >= 8:
        ans = max(ans, 2)
    if longest_streak >= 12:
        ans = max(ans, 3)
    if ans == 0:
        return "NONE"
    elif ans == 1:
        return "LOW"
    elif ans == 2:
        return "MEDIUM"
    else:
        return "HIGH"
t = int(input())
for _ in range(t):
    print(solve())
