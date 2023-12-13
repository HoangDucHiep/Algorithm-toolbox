#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin  >> n;
    long long count = 0;
    vector<long long> num;

    for(int i = 1; n > 0; i++)
    {
        if(n <= 2*i)
        {
            num.push_back(n);
            count++;
            n=0;
        }
        else
        {
            num.push_back(i);
            count++;
            n-=i;
        }
    }
    
    cout << count << "\n";
    for(auto i : num)
    {
        cout << i << " ";
    }
    return 0;
}