from datetime import datetime, timedelta

t = int(input())

for _ in range(t):
    a, b, c = input().split()
    c = float(c)

    # Extract date and time components
    month, day, year = map(int, a.split("/"))
    hours, minutes = map(int, b.split(":"))

    # Convert fractional hours properly
    whole_hours, fractional_hours = divmod(c, 1)
    minutes_to_subtract = round(fractional_hours * 60)

    # Create datetime object
    date = datetime(year, month, day, hours, minutes)

    # Subtract time
    date -= timedelta(hours=int(whole_hours), minutes=minutes_to_subtract)

    # Format output properly
    print(date.strftime("   ))
