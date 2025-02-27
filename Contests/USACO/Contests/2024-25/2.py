MOD = 10**9 + 7

def mod_pow(base, exp):
    result = 1
    while exp:
        if exp % 2 == 1:
            result = (result * base) % MOD
        base = (base * base) % MOD
        exp //= 2
    return result

def process_segments(segments, points):
    flip_map = {}
    for l, r in segments:
        start = lower_bound(points, l)
        end = lower_bound(points, r + 1)
        flip_map[start] = flip_map.get(start, 0) ^ 1
        flip_map[end] = flip_map.get(end, 0) ^ 1
    return flip_map

def lower_bound(arr, value):
    low, high = 0, len(arr)
    while low < high:
        mid = (low + high) // 2
        if arr[mid] < value:
            low = mid + 1
        else:
            high = mid
    return low

def calculate_prefix_sum(flip_map, points):
    prefix_sum = [0] * len(points)
    flip_state = [0] * len(points)
    for i in range(1, len(points)):
        flip_state[i] = flip_state[i - 1] ^ flip_map.get(i, 0)
    for i in range(1, len(points)):
        prefix_sum[i] = prefix_sum[i - 1] + flip_state[i] * (points[i] - points[i - 1])
    return prefix_sum, flip_state

def calculate_range_value(l, r, prefix_sum, flip_state, points, calc):
    if l >= r:
        return 0
    start_idx = lower_bound(points, l + 1) - 1
    end_idx = lower_bound(points, r)
    
    if start_idx + 1 == end_idx:
        return flip_state[start_idx + 1] * (r - l)

    mid_calc = calc[end_idx - 1] - calc[start_idx + 1] * mod_pow(2, points[end_idx - 1] - points[start_idx + 1]) % MOD
    mid_calc = mid_calc * mod_pow(2, r - points[end_idx - 1]) % MOD
    
    start = flip_state[start_idx + 1] * (mod_pow(2, points[start_idx + 1] - l) - 1) * mod_pow(2, r - points[start_idx + 1]) % MOD
    end = flip_state[end_idx] * (mod_pow(2, r - points[end_idx - 1]) - 1)

    return (start + mid_calc + end) % MOD

def process_queries(queries, prefix_sum, flip_state, points, calc):
    results = []
    for l, r, k in queries:
        r += 1
        if calculate_range_value(l, r, prefix_sum, flip_state, points, calc) >= k:
            result = mod_pow(2, k) - 1
            if result < 0:
                result += MOD
            results.append(result)
            continue
        
        le, re = l, r
        while le < re:
            mid = (le + re) // 2 + 1
            if calculate_range_value(l, mid, prefix_sum, flip_state, points, calc) + r - mid >= k:
                le = mid
            else:
                re = mid - 1

        ones = calculate_range_value(l, le, prefix_sum, flip_state, points, calc)
        result = (mod_pow(2, ones) - 1) * mod_pow(2, r - le) % MOD
        result += calculate_range_value(le, r, prefix_sum, flip_state, points, calc)
        result = (result + MOD) % MOD

        results.append(result)
    return results

def main():
    n, m, q = map(int, input().split())

    segments = []
    points = [1, n + 1]
    for _ in range(m):
        l, r = map(int, input().split())
        points.append(l)
        points.append(r + 1)
        segments.append((l, r + 1))

    points.sort()
    points = list(sorted(set(points)))  # Remove duplicates

    flip_map = process_segments(segments, points)
    prefix_sum, flip_state = calculate_prefix_sum(flip_map, points)

    calc = [0] * len(points)
    for i in range(1, len(points)):
        calc[i] = calc[i - 1] * mod_pow(2, points[i] - points[i - 1])
        calc[i] += flip_state[i] * (mod_pow(2, points[i] - points[i - 1]) - 1)
        calc[i] %= MOD

    queries = [tuple(map(int, input().split())) for _ in range(q)]
    results = process_queries(queries, prefix_sum, flip_state, points, calc)

    for result in results:
        print(result)

if __name__ == "__main__":
    main()
