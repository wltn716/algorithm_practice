// 문제: https://www.acmicpc.net/problem/1783
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if(n == 1) cout << 1 << "\n";
    else if(n == 2) {
        cout << min(3, (m-1)/2) + 1 << "\n";
    }
    else {
        if(m < 7)
            cout << min(3, m-1) + 1 << "\n";
        else
            cout << m-2 << "\n";
    }


    return 0;
} 