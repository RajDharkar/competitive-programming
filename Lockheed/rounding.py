from decimal import Decimal, ROUND_HALF_UP
def solve():
    k = float(input())
    num = Decimal(str(k)) #You gotta convert it to string to avoid roundoff errors, ie. 2.5 = 2.49999999999999999999999999
    rounded = num.quantize(Decimal('0.01'), rounding=ROUND_HALF_UP) #The 0.01 thing is the amount of places
    print(rounded) 

t = int(input())

while t > 0:
    t-=1
    solve()
