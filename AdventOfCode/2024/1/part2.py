import math

input_file = "input.in"

a = []
b = {}

with open(input_file, "r") as f:
	for line in f:
		c, d = map(int, line.split())
		a.append(c)
		b[d] = b.get(d, 0) + 1


ans = 0
for i in range(len(a)):
	if a[i] in b:
		ans += b[a[i]] * a[i]

print(ans)