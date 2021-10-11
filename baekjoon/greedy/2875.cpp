// 문제: https://www.acmicpc.net/problem/2875
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        if(n < 1 && m < 1) break;
        if(2*m > n) m--;
        else n--;
    }   

    cout << min(n/2, m) << "\n";

    return 0;
} 