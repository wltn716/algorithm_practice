// 문제: https://www.acmicpc.net/problem/1850
#include <iostream>
using namespace std;
typedef long long ll;

ll gcd (ll a, ll b) {
    ll g;

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

    ll a, b, g;
    cin >> a >> b;
    g = gcd(a, b);
    while(g--) 
        cout << 1;

    cout << "\n";

    return 0;
}