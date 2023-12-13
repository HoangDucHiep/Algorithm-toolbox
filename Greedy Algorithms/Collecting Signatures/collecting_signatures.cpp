#include <bits/stdc++.h>
using namespace std;

struct segment
{
    int l, r;
    bool operator < (const segment& other)
    {
        return r < other.r;
    }
};
void collecting(int n, segment *list)
{
    sort(list, list+n);
    int count = 1;
    int lastPoint = list[0].r;
    string point = to_string(list[0].r);
    for(int i = 1; i < n; i++)
    {
        if(list[i].l > lastPoint)
        {
            lastPoint = list[i].r;
            point = point + " " + to_string(lastPoint); 
            count++;
        }
    }
    cout << count << "\n" << point;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    segment *list = new segment[n];
    for(int i = 0; i < n; i++)
    {
        cin >> list[i].l >> list[i].r;
    }
    collecting(n, list);
}