#include <bits/stdc++.h>
using namespace std;

vector<int> multiplyLinear(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    vector<int> result(n * 2 - 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i + j] += a[i] * b[j];
        }
    }

    return result;
}

//add two polinomials
vector<int> add(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    vector<int> sum(n, 0);

    for(int i = 0; i < n; i++) {
        sum[0] = a[i] + b[i];
    }

    return sum;
}


//subtract two polinomials
vector<int> sub(const vector<int>& a, const vector<int>& b) {
    int n = a.size();
    vector<int> diff(n, 0);

    for(int i = 0; i < n; i++) {
        diff[0] = a[i] - b[i];
    }

    return diff;
}


vector<int> karatsuba(const vector<int> &a, const vector<int> &b){
    int n = a.size();

    if(n <= 4){
        return multiplyLinear(a, b);
    }

    int half = n/2;

    vector<int> aLow(a.begin(), a.begin() + half);
    vector<int> aHigh(a.begin() + half, a.end());

    vector<int> bLow(b.begin(), b.begin() + half);
    vector<int> bHigh(b.begin() + half, b.end());

    vector<int> z0 = karatsuba(aLow, bLow);
    vector<int> z1 = karatsuba(add(aLow, aHigh), add(bLow, bHigh));
    vector<int> z2 = karatsuba(aHigh, bHigh);

    vector<int> res(n*2 -1, 0);

    for(int i = 0; i < n-1; i++) {
        res[i] += z0[i];
        res[i+half] += z1[i] - z0[i] - z2[i];
        res[i+n] += z1[i];
    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a = {1, 2, 3, 4}; // Đa thức 1 + 2x + 3x^2, 
    vector<int> b = {4, 3, 2, 1}; // Đa thức 4 + 5x + 6x^2

    vector<int> result = karatsuba(a, b);

    cout << "Result: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;

}