# python3


def money_change(money):
    assert 0 <= money <= 10 ** 3
    if money >= 10:
        return 1 + money_change(money - 10)
    elif money < 10 and money >= 5:
        return 1 + money_change(money - 5)
    elif money < 5 and money >= 1:
        return 1 + money_change(money - 1)
    elif money == 0:
        return 0


if __name__ == '__main__':
    input_money = int(input())
    print(money_change(input_money))
