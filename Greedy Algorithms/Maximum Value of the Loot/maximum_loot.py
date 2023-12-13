# python3

from sys import stdin


def best_item(w, v):
    max_value_per_weight = 0
    best_item = -1  # Initialize to an invalid index
    for i in range(len(w)):
        if w[i] > 0 and v[i] / w[i] > max_value_per_weight:
            max_value_per_weight = v[i] / w[i]
            best_item = i
    return best_item

def maximum_loot_value(capacity, weights, prices):
    assert 0 <= capacity <= 2 * 10 ** 6
    assert len(weights) == len(prices)
    assert 1 <= len(weights) <= 10 ** 3
    assert all(0 < w <= 2 * 10 ** 6 for w in weights)
    assert all(0 <= p <= 2 * 10 ** 6 for p in prices)
    num_of_items = len(weights)
    total_value = 0

    while capacity > 0:
        j = best_item(weights, prices)
        if j == -1:  # No more items to select
            break
        a = min(capacity, weights[j])
        total_value += a * (prices[j] / weights[j])
        weights[j] -= a
        capacity -= a

    return total_value


if __name__ == "__main__":
    data = list(map(int, stdin.read().split()))
    n, input_capacity = data[0:2]
    input_prices = data[2:(2 * n + 2):2]
    input_weights = data[3:(2 * n + 2):2]
    opt_value = maximum_loot_value(input_capacity, input_weights, input_prices)
    print("{:.10f}".format(opt_value))

