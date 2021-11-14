// 문제: https://www.acmicpc.net/problem/1715
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    
    int n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<ll>> pq;

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        pq.push(k);
    }

    ll ans = 0;
    while(pq.size() != 1) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ll c = a + b;
        ans += c;
        pq.push(a+b);
    }

    cout << ans << "\n";
    

    return 0;
} 