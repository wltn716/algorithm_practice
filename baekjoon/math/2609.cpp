// 문제: https://www.acmicpc.net/problem/2609
#include <iostream>
using namespace std;

int gcd (int a, int b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, g;

    cin >> a >> b;

    g = gcd(a, b);

    cout << g << "\n";
    cout << a*b/g << "\n";

    return 0;
}