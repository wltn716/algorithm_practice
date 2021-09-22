// 문제: https://www.acmicpc.net/problem/2512
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 변수선언
    vector<int> req;
    int n, m, ans;

    // 입력
    cin >> n;
    req.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }
    cin >> m;
    
    // solution
    sort(req.begin(), req.end());
    for (int i = 0; i < n; i++){
        if(m/(n-i) < req[i]) {
            ans = m/(n-i);
            break;
        }
        
        ans = req[i];
        m -= req[i];
    }

    cout << ans << "\n";

    return 0;
} 