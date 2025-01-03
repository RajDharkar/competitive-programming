def solve():
    n = int(input())
    cakes = list(map(int, input().split()))
    # p = [0] * (n + 1)
    # for i in range(1, n + 1):
    #     p[i] = cakes[i - 1] + p[i - 1]

    # bessies sum will be the mminimum aximum sum of like the sums between 0 -> (n / 2) but like it will continue
    # lets call a = 0
    # b = n / 2 
    # we use our prefix sum to find the sum between a and b while they increase and maintain the minimum(cuz elsie will sabotage)


    #edit. prefix sum not needed lol might as well
    # print(p)
    totalSum = sum(cakes)
    currentSum = 0
    for i in range(0, n // 2 + 1):
        currentSum += cakes[i]
    # print(currentSum)
    #for a prefix sum, the sum between a and b(0 indexed) is pref[a + 1] - pref[b]
    ans = currentSum #cannot be this obv but its like max
    a = 0
    while a + 1 + n // 2 != n:
   #    ans = p[a + 1] - p[b] 
        a += 1
        currentSum -= cakes[a - 1]
        currentSum += cakes[a + n // 2]
        ans = min(ans, currentSum)
        # b += 1
  #  totalSum = sum(cakes)
    print(ans, totalSum - ans)


t = int(input())
for testCase in range(t):
    solve()

