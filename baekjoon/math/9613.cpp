// 문제: https://www.acmicpc.net/problem/9613
#include <iostream>
using namespace std;
typedef long long ll;

int gcd (int a, int b) {
    while(b!=0) {
        int g = a%b;
        a = b;
        b = g;
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        int a[n];
        ll sum = 0;
        
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        for (int i = 0; i < n-1; i++){
            for (int j = i+1; j < n; j++){
                sum += a[i] > a[j] ? gcd(a[i], a[j]) : gcd(a[j], a[i]);
            }
        }

        cout << sum << "\n";
        
    }

    return 0;
}