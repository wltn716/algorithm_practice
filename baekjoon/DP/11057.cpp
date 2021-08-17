// 문제: https://www.acmicpc.net/problem/11057
#include <iostream>
#define MAX 1001
#define MOD 10007
typedef long long ll;
using namespace std;

//n[p][q] = 길이가 p고 마지막 자리수가 q인 오르막 수의 개수
//n[1][0~9] = 1
//n[p][q] = n[p-1][0] ( + ... + n[p-1][q]);
ll n[MAX][10];

ll bottomUp (int p) {
    for(int i = 2; i <= p; i++){
        for (int j = 0; j < 10; j++){
            n[i][j] = 0;
            for(int k = 0; k <= j; k++){
                n[i][j] += n[i-1][k];
            }
            n[i][j] %= MOD;
        }
    }

    ll result = 0LL;
    for(int i = 0; i < 10; i++) {
        result += n[p][i];
    }

    return result % MOD;
}

ll topDown(int p, int q) {
    if(n[p][q] > 0) return n[p][q];

    n[p][q] = 0;
    for (int i = 0; i <= q; i++){
        n[p][q] += topDown(p-1, i);
    }
    
    return n[p][q] % MOD;
}

ll td(int p) {
    ll result = 0LL;
    for (int i = 0; i < 10; i++){
        result += topDown(p, i);
    }

    return result % MOD;
}

void init() {
    for (int i = 0; i < 10; i++){
        n[1][i] = 1LL;
    }
}

int main() {
    int k;
    scanf("%d", &k);
    init();
    printf("%lld\n", td(k));
    return 0;
}