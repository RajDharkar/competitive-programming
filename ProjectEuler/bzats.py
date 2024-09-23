MOD = 10**9 + 7

def fibonacci_up_to(max_n):
    fibs = [1, 2]
    while True:
        next_fib = fibs[-1] + fibs[-2]
        if next_fib > max_n:
            break
        fibs.append(next_fib)
    return fibs

def expected_min_distance(x, fibs):
    min_distance = float('inf')
    for f in fibs:
        min_distance = min(min_distance, abs(f - x))
    return min_distance

def compute_g(N):
    print(f"Computing g({N})...")
    fibs = fibonacci_up_to(N)
    print(f"  Generated Fibonacci numbers up to {N}.")
    
    total_distance = 0
    for x in range(1, N + 1):
        if x % (N // 1) == 0:  # Print progress every 10% of N
            print(f"    Progress: {x}/{N}")
        d = expected_min_distance(x, fibs)
        total_distance += d
    
    expected_d = total_distance / N
    result = int(expected_d * N) % MOD
    print(f"  Finished computing g({N}): result = {result}")
    return result

def sum_g():
    total_sum = 0
    for i in range(1, 10**6 + 1):
        N = i * 10**12
        if i % (10**6 // 10) == 0:  # Print progress every 10% of i
            print(f"Overall Progress: {i}/{10**6}")
        total_sum = (total_sum + compute_g(N)) % MOD
    
    return total_sum

print("Starting computation...")
result = sum_g()
print(f"Final result: {result}")
