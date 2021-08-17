// 문제: https://www.acmicpc.net/problem/2225
#include <iostream>
#define MAX 201
#define MOD 1000000000
using namespace std;
typedef long long ll;

// d[k][n] = 정수 k개의 합이 n이 되는 경우의 수
// d[k][n] = sum(d[k-1][n-l]) (l<=n)
ll d[MAX][MAX];

ll bottomUp(int n, int k) {
    d[0][0] = 1LL;
    for (int i = 1; i <= k; i++){
        for(int j = 0; j<= n; j++){
            for(int l = 0; l <= j; l++){
                d[i][j] += d[i-1][j-l];
                d[i][j] %= MOD;
            }
        }
    }

    return d[k][n];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%lld\n", bottomUp(n, k));
    
    return 0;
}