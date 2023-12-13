#include <bits/stdc++.h>
using namespace std;

double maximumValue(double *c, double *w, int n, int cap)
{
    double *costPerPound = new double[n];
    for(int i = 0; i < n; i++)
    {
        costPerPound[i] = c[i]/w[i];
    }

    double total = 0;
    int maxItem;
    double maxValue;

    int takeAmount;

    while(cap > 0)
    {
        maxItem = maxValue = -1;
        for(int i = 0; i < n; i++)
        {
            if(w[i] > 0 && costPerPound[i] > maxValue)
            {
                maxValue = costPerPound[i];
                maxItem = i;
            }
        }
        if(maxItem == -1)
            return total;
        
        takeAmount = min(double(cap), w[maxItem]);

        total += takeAmount*costPerPound[maxItem];

        cap -= takeAmount;
        w[maxItem] -= takeAmount;
    }

    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, cap;
    cin >> n >> cap;

    double *c, *w;
    c = new double[n];
    w = new double[n];
    for(int i = 0; i < n; i++)
    {
        cin >> c[i] >> w[i];
    }
    printf("%.4lf", maximumValue(c, w, n, cap));
}