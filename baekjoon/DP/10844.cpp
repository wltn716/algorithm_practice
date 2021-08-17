// 문제: https://www.acmicpc.net/problem/10844
#include <iostream>
#define MAX 101
#define MOD 1000000000
using namespace std;
typedef long long ll;

//n[p][q] = 길이가 p고 마지막 자리수가 q인 계단 수의 개수
//n[1][1~9] = 1
//n[p][q] = n[p-1][q-1] + n[p-1][q+1];
ll n[MAX][10];

ll topDown(int p, int q) {
    if(n[p][q] > 0 || p==1) return n[p][q];
    
    n[p][q] = 0;
    if(q>0) n[p][q] += topDown(p-1, q-1);
    if(q<9) n[p][q] += topDown(p-1, q+1);

    return n[p][q]%MOD;
}

ll td(int p) {
    ll result=0;
    for (int i = 0; i < 10; i++){
        result += topDown(p, i); 
    }

    return result%MOD;
}

ll bottomUp(int p) {
    for(int i=2;i<=p;i++) {
        for(int j=0;j<10;j++) {
            n[i][j] = 0;
            if(j>0) n[i][j] += n[i-1][j-1];
            if(j<9) n[i][j] += n[i-1][j+1];

            n[i][j]%=MOD;
        }
    }

    ll result = 0;
    for (int i = 0; i < 10; i++) {
        result += n[p][i];
    }

    return result%MOD;
}

int main() {
    int k;
    scanf("%d", &k);

    n[1][0] = 0LL;
    for (int i = 1; i < 10; i++){
        n[1][i] = 1LL;
    }
    
    printf("%lld\n", td(k));
    return 0;
}