#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000001

using namespace std;

//d[i][0] = max(d[i-1][0], d[i-2][0]+ money[i]) 
//d[i][1] = max(d[i-1][1], d[i-2][1]+ money[i]) 
int d[MAX][2];
int ans = 0;

int dp(vector<int> money) {
    int n = money.size();
    
    d[0][0] = 0;
    d[0][1] = money[0];

    d[1][0] = money[1];
    d[1][1] = max(money[0], money[1]);

    for(int i = 2; i < n; i++) {
        d[i][0] = max(d[i-1][0], d[i-2][0] + money[i]);

        if(i != n-1)
            d[i][1] = max(d[i-1][1], d[i-2][1] + money[i]);
        else
            d[i][1] = -1;

        ans = max({ans, d[i][0], d[i][1]});
    }

    return ans;
}

int solution(vector<int> money) {
    return dp(money);
}