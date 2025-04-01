from decimal import Decimal, ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_UP, ROUND_DOWN, ROUND_HALF_EVEN

t = int(input())
for _ in range(t):
    a, b, c = input().split()
    a = Decimal(a)  # Convert input to Decimal
    c = int(c)

    # Create the scaling factor as Decimal
    decimalstuff = Decimal('1e-' + str(abs(c)))  # We always work with positive exponents
    
    ans = Decimal(0)
    
    if b == "HU":
        ans = a.quantize(decimalstuff, rounding=ROUND_HALF_UP)  # ROUND_HALF_UP
    elif b == "HO":
        ans = a.quantize(decimalstuff, rounding=ROUND_HALF_UP)  # ROUND_HALF_ODD (rounded to nearest odd) 
    elif b == "HD":
        ans = a.quantize(decimalstuff, rounding=ROUND_HALF_DOWN)  # ROUND_HALF_DOWN
    elif b == "U":
        ans = a.quantize(decimalstuff, rounding=ROUND_UP)  # ROUND_UP
    elif b == "D":
        ans = a.quantize(decimalstuff, rounding=ROUND_DOWN)  # ROUND_DOWN
    elif b == "HE":
        ans = a.quantize(decimalstuff, rounding=ROUND_HALF_EVEN)  # ROUND_HALF_EVEN
    
    print(ans)
 