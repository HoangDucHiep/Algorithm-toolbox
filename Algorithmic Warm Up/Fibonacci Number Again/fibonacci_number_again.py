# python3


def fibonacci_number_again_naive(n, m):
    assert 0 <= n <= 10 ** 18 and 2 <= m <= 10 ** 3

    if n <= 1:
        return n

    previous, current = 0, 1
    for _ in range(n - 1):
        previous, current = current, (previous + current) % m

    return current


def pisano_period(m):
    prev = 0
    cur = 1
    period = 1

    while True:
        prev, cur = cur, (prev + cur) % m
        if prev == 0 and cur == 1:
            break
        period += 1

    return period


def fibonacci_number_again(n, m):
    assert 0 <= n <= 10 ** 18 and 2 <= m <= 10 ** 3

    period = pisano_period(m)

    n %= period

    if n <= 1:
        return n
    prev = 0
    cur = 1
    for i in range(n - 1):
        prev, cur = cur, (prev + cur) % m
    return cur


if __name__ == '__main__':
    input_n, input_m = map(int, input().split())
    print(fibonacci_number_again(input_n, input_m))
