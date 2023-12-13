#include <bits/stdc++.h>
using namespace std;

int toNum(string s1, string s2)
{
    string num = s1 + s2;
    return stoi(num);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i < n; i++)
    {
        int j = i;
        while(j>0 && toNum(a[j-1], a[j]) < toNum(a[j], a[j-1]) )
        {
            swap(a[j], a[j-1]);
            j--;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << a[i];
    }


}