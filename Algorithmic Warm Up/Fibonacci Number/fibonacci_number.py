# python3


def fibonacci_number_naive(n):
    assert 0 <= n <= 45

    if n <= 1:
        return n

    return fibonacci_number_naive(n - 1) + fibonacci_number_naive(n - 2)


def fibonacci_number(n):
    assert 0 <= n <= 45

    num0 = 0
    num1 = 1
    num2 = 0
    if n == 0:
        return num0
    if n == 1:
        return num1
    i = 2
    while i <= n:
        num2 = num0 + num1
        num0 = num1
        num1 = num2
        i+=1
    return num2


if __name__ == '__main__':
    input_n = int(input())
    print(fibonacci_number(input_n))
