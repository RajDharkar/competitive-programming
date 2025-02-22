import sys

def main():
    n, m, c = map(int, sys.stdin.readline().split())
    money = list(map(int, sys.stdin.readline().split()))
    
    roads = []
    adj = [[] for _ in range(n)]
    for _ in range(n):
        u, v = map(int, sys.stdin.readline().split())
        u -= 1
        v -= 1
        roads.append((u, v))
        adj[u].append(v)
    
    dp = [[-float('inf')] * (n) for _ in range(1001)]
    dp[0][0] = 0
    
    for i in range(1000):
        for node in range(n):
            if dp[i][node] == -float('inf'):
                continue
            for x in adj[node]:
                dp[i+1][x] = max(dp[i+1][x], dp[i][node] + money[x])
    
    ans = 0
    for i in range(1000):
        ans = max(ans, dp[i][0] - c * i * i)
    
    print(ans)

if __name__ == "__main__":
    main()
