// 문제: https://www.acmicpc.net/problem/11047
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, total, s, ans = 0;
    cin >> n >> total;

    int coins[n];

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        if(coins[i] <= total) s = i;
    }

    int remain = total;
    while(remain != 0) {
        ans += (remain/coins[s]);
        remain %= coins[s];
        if(remain > 0) {
            for (int i = s-1; i > -1; i--) {
                if(coins[i] <= remain) {
                    s = i;
                    break;
                }    
            }
        }
    }
    
    cout << ans << "\n";

    return 0;
} 