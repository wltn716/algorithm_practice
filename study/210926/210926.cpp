// 문제: https://www.acmicpc.net/problem/210926
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    int visit[n];

    int sum = 0;
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // 입력
        cin >> visit[i];

        sum += visit[i];
        
        // 첫번째 구간
        if(i == x-1) {
            ans = sum;
            cnt = 1;
        }   

        // 첫번째 구간 이후    
        if(i > x-1) {
            sum -= visit[i-x];
            if(ans == sum) {
                cnt++;
            }
            else {
                if(ans < sum){
                    ans = sum;
                    cnt = 1;
                }
            }
        }
    }

    if(ans > 0)
        cout << ans << "\n" << cnt << "\n";   
    else
        cout << "SAD" << "\n";
    

    return 0;
} 