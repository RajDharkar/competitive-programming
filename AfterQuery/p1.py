def optimize_cart_discounts(n, p, m, items):
    #checking bounds
    if n < 2 or n > 100 or p < 1 or p > 10000 or m < 1 or m > 70:
        raise ValueError("not valid input")
    
    for [price, cat, disc] in items:
        if price < 1 or price > 5000 or cat < 1 or cat > 20 or disc < 1 or disc > 50:
            raise ValueError("not valid input")
        
    #Ideally we would take the MAXIMUM_DISCOUNT of every item, although when constructing groups
    #Although, the sum of the discounts that we use has to be <= M percent. 
    #
    # Note. 70% is the max M can be, meaning the sum of the discounts that we apply is going to be <= 70.
    # Furthermore, we should apply discounts to the MOST expensive elements, to effectively remove the most cost
    # 
    # That's why, to start, we'll be sorting the elements in descending order, and 
    # 
    # Note that there is no constraint on the discount's in each zone. Now, 
    # let's consider the 4th constraint. 
    # "The total percentage discount across all zones should not be more than a limit M"
    # This is the only constraint on discounts, so we might as well consider them seperately, because it doesn't refer to indivisual zones
    # rather it refers to ALL ZONES which include all the elements. We should apply discounts to the MOST expensive elements, to effectively remove the most cost
    
    
from itertools import combinations

def solve_exact(N, P, M, items):
    """
    N: number of items
    P: max allowed price difference within a zone
    M: total % discount budget
    items: list of (price, category, max_discount)

    Returns (best_discount, best_partition) where:
      - best_partition is a list of zones (each zone is a tuple of indices)
      - best_discount is the maximum dollars saved
    """

    # Precompute all *feasible* zones (subsets of size 2–4 meeting P & category rules)
    zones = []
    for k in (2, 3, 4):
        for combo in combinations(range(N), k):
            prices  = [items[i][0] for i in combo]
            cats    = [items[i][1] for i in combo]
            if max(prices) - min(prices) > P: 
                continue
            if len(set(cats)) < k: 
                continue
            # zone_max_pct is the min of the items’ max_discounts
            zone_max_pct = min(items[i][2] for i in combo)
            total_price  = sum(prices)
            zones.append((combo, zone_max_pct, total_price))

    best_discount = 0
    best_partition = []

    def backtrack(remaining_items, remaining_pct, chosen_zones, accrued):
        nonlocal best_discount, best_partition

        # If no items left or budget exhausted, check end-value
        if remaining_pct <= 0 or not remaining_items:
            if accrued > best_discount:
                best_discount  = accrued
                best_partition = chosen_zones.copy()
            return

        # Try adding each zone in turn (note: order matters here, that's where N! arises)
        for idx, (combo, zmax, price_sum) in enumerate(zones):
            # only if all items in combo are still unused
            if any(i not in remaining_items for i in combo):
                continue

            # choose how much pct we actually apply to this zone
            pct_used = min(zmax, remaining_pct)
            gain     = price_sum * (pct_used / 100.0)

            # remove those items, recurse
            new_remain = remaining_items - set(combo)
            chosen_zones.append((combo, pct_used))
            backtrack(new_remain,
                      remaining_pct - pct_used,
                      chosen_zones,
                      accrued + gain)
            chosen_zones.pop()

        # also consider “stopping here” (i.e. no more zones)
        if accrued > best_discount:
            best_discount  = accrued
            best_partition = chosen_zones.copy()

    # start with all items available
    backtrack(set(range(N)), M, [], 0.0)
    return best_discount, best_partition

# --- example usage on tiny N ---
if __name__ == "__main__":
    # N=4 example from above
    items = [
        (100, 'A', 10),
        (90,  'B', 10),
        (20,  'C', 50),
        (19,  'D', 50),
    ]
    best_val, best_zones = solve_exact(4, P=1000, M=10, items=items)
    print(f"Max discount = ${best_val:.2f}")
    for combo, pct in best_zones:
        print(f" Zone {combo} at {pct}%")
