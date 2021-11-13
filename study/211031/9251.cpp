// 문제: https://www.acmicpc.net/problem/9251
#include <iostream>
#define MAX 1001

using namespace std;

string str1;
string str2;
int dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> str1 >> str2;

    int n = str1.size();
    int m = str2.size();

    int ans = -1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else {
                if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

            ans = max(ans, dp[i][j]);
        }        
    }
    
    cout << ans << "\n";

    return 0;
} 