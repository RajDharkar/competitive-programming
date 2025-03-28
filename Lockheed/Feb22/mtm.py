from datetime import timedelta

cases = int(input())
for _ in range(cases):
    distance, speed = map(float, input().split())
    distance *= 1e6  # Convert million miles to miles

    total_seconds = distance / speed * 3600  # Convert hours to seconds
    time_delta = timedelta(seconds=round(total_seconds))

    days = time_delta.days
    hours, remainder = divmod(time_delta.seconds, 3600)
    minutes, seconds = divmod(remainder, 60)

    print(f"Time to Mars: {days} days, {hours} hours, {minutes} minutes, {seconds} seconds")
