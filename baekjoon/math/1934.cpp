// 문제: https://www.acmicpc.net/problem/1934
#include <iostream>
using namespace std;

int gcd (int a, int b) {
    int g;

    while(b!=0) {
        g = a%b;
        a = b;
        b = g;
    }

    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, a, b, g;

    cin >> t;
    
    while(t--) {
        cin >> a >> b;
        cout << a*b/gcd(a, b) << "\n";
    }

    return 0;
}