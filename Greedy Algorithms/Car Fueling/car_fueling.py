# python3

def compute_min_number_of_refills(d, m, stops):
    assert 1 <= d <= 10 ** 5
    assert 1 <= m <= 400
    assert 1 <= len(stops) <= 300
    assert 0 < stops[0] and all(stops[i] < stops[i + 1] for i in range(len(stops) - 1)) and stops[-1] < d

    stops.append(d)
    refill_times = 0
    tank = m
    if stops[1] > tank:
        return -1
    i = 2
    while(i < len(stops)):
        if(stops[i] > tank):
            tank = stops[i - 1] + 1
            if(tank < stops[i]):
                return -1
            else:
                refill_times += 1
        i = i + 1

    return refill_times



if __name__ == '__main__':
    input_d = int(input())
    input_m = int(input())
    input_n = int(input())
    input_stops = list(map(int, input().split()))
    assert len(input_stops) == input_n

    print(compute_min_number_of_refills(input_d, input_m,input_stops))
