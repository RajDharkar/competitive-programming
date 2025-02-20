n = int(input())
a, b = map(int, input().split())
ministers = [tuple(map(int, input().split())) for p in range(n)]

# for i in range(n):
#     w, v = ministers[i]
#     for j in range(i+1, n):
#         x, y = ministers[j]
#         if w * v > x * y:
#             ministers[i], ministers[j] = ministers[j], ministers[i]

ministers.sort(key=lambda x: x[0] * x[1], reverse=False)

# print(ministers)

ans = 0
product = a
for x, y in ministers:
    assert(y!=0)
    # print(product, y, product // y)
    ans = max(ans, product // y)
    product *= x
print(ans)
