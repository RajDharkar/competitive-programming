def pop_count(x):
    count = 0
    while x:
        count += x & 1
        x >>= 1
    return count

def ctz(x):
    count = 0
    while x and x & 1 == 0:
        count += 1
        x >>= 1
    return count

def solve():
    n, edges = map(int, input().split())
    full_mask = 1 << n

    mat = [[0] * n for _ in range(n)]
    adj_masks = [0] * n

    for _ in range(edges):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        mat[u][v] = mat[v][u] = 1
        adj_masks[u] |= (1 << v)
        adj_masks[v] |= (1 << u)

    mask_all = (1 << n) - 1
    lack = [0] * n
    for i in range(n):
        remain = mask_all ^ (1 << i)
        lack[i] = remain & ~adj_masks[i]

    pop_cnt = [0] * full_mask
    for s in range(full_mask):
        pop_cnt[s] = pop_count(s)

    sub_edges = [0] * full_mask
    for s in range(full_mask):
        cnt = 0
        for i in range(n):
            if s & (1 << i):
                for j in range(i + 1, n):
                    if s & (1 << j):
                        cnt += mat[i][j]
        sub_edges[s] = cnt

    sub_cost = [0] * full_mask
    for s in range(full_mask):
        c_pop = pop_cnt[s]
        if c_pop <= 1:
            sub_cost[s] = 0
        else:
            total_pairs = c_pop * (c_pop - 1) // 2
            used_edges = sub_edges[s]
            sub_cost[s] = min(used_edges, total_pairs - used_edges)

    INF = 1000000000
    dp_val = [INF] * full_mask
    dp_val[0] = 0

    for s in range(1, full_mask):
        t = s
        while t:
            left = s ^ t
            gap = 0
            tmp = t
            while tmp:
                idx = ctz(tmp)
                gap += pop_count(lack[idx] & left)
                tmp &= (tmp - 1)
            dp_val[s] = min(dp_val[s], dp_val[left] + sub_cost[t] + gap)
            t = (t - 1) & s

    print(dp_val[full_mask - 1])

if __name__ == "__main__":
    solve()
