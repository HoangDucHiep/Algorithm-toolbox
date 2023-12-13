#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int money;
    cin >> money;

    unsigned int temp = 0;
    unsigned int count = 0; //number of coins

    count += money/10;
    if(money % 10 == 0)
    {
        cout << count;
        return 0;
    }
    money %= 10;


    count += money/5;
    if(money % 5 == 0)
    {
        cout << count;
        return 0;
    }
    money %= 5;

    count += money/1;
    cout << count;
    return 0;
}