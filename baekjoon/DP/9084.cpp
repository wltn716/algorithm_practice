// 문제: https://www.acmicpc.net/problem/9084
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 10001
#define pb push_back
#define all(v) v.begin(), v.end()

using namespace std;

vector<int> d(MAX);

int dp(int m, vector<int> coins) {
    d[0] = 1;

    for(int c: coins) {
        for (int i = c; i <= m; i++){
            d[i] += d[i-c];
        }        
    }

    return d[m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        // inital d
        fill(all(d), 0);

        // input
        int n, m;
        cin >> n;
        vector<int> coins;
        for (int i = 0; i < n; i++){
            int k; cin >> k;
            coins.pb(k);
        }        
        cin >> m;

        // answer
        cout << dp(m, coins) << "\n";
    }

    return 0;
} 