t = int(input())

for i in range(t):
    n = int(input())
    total = 0
    for i in range(n):
        nums = [token for token in input().split(",")]
    
        for i in range(3):
            if nums[i] == "":
                nums[i] = 0
            else:
                nums[i] = float(nums[i])
        total += nums[1]
        total -= nums[2]
    print(1)
    print((total / n) * (0.18 / 12))
                

