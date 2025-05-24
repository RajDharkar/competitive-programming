def calculate_powers(x, y, t):
    denominator = max(abs(y) + abs(x) + abs(t), 1)
    powers = []
    for i in range(4):
        x_sign = 1 if i % 3 == 0 else -1
        t_sign = 1 if i < 2 else -1
        power = (y + x * x_sign + t * t_sign) / denominator
        powers.append(power)
    return powers
