// 문제: https://www.acmicpc.net/problem/2133
#include <iostream>
#include <algorithm>
#define MAX 31
using namespace std;
typedef long long ll;

// d[2] = 3
// d[i] = d[i-2] * 3 + d[i-4] * 2 + ... + d[0] * 2 (i % 2 = 0)
ll d[MAX];

ll bottomUp(int k) {
    // 짝수가 아닐경우(2로 나눈 나머지가 0 이상일경우)
    if(k%2) return 0;
    
    d[0] = 1LL;
    d[2] = 3LL;

    for (int i = 4; i <= k; i += 2){
        d[i] = d[i-2] * 3;
        for(int j = 4; i - j >= 0; j += 2){
            d[i] += d[i-j] * 2;
        }
    }

    return d[k];
}

int main() {
    int k;
    scanf("%d", &k);
    printf("%lld\n", bottomUp(k));
    return 0;
}