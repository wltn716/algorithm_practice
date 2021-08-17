// 문제: https://www.acmicpc.net/problem/9461
#include <iostream>
#define MAX 101
using namespace std;
typedef long long ll;

// p[i] = p[i-1] + p[i-5]
ll p[MAX];

void init() {
    p[1]=1LL;
    p[2]=1LL;
    p[3]=1LL;
    p[4]=2LL;
    p[5]=2LL;
}

ll topDown(int k) {
    if(p[k] > 0) return p[k];

    p[k] = topDown(k-1) + topDown(k-5);

    return p[k];
}

ll bottomUp(int k) {
    for(int i = 6; i <= k; i++){
        p[i] = p[i-1] + p[i-5];
    }

    return p[k];
}

int main() {
    int t;
    scanf("%d", &t);
    init();
    for (int i = 0; i < t; i++){
        int k;
        scanf("%d", &k);
        printf("%lld\n", topDown(k));
    }
    
    return 0;
}