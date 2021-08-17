// 문제: https://www.acmicpc.net/problem/2193
#include <iostream>
#define MAX 91
typedef long long ll;
using namespace std;

// m[k] = 길이가 k인 이친수의 개수
// m[k] = m[k-1] + m[k-2]
// 1로 끝나는 경우= k-2자리수 끝에 01이 오는 경우
// 0로 끝나는 경우= k-1자리수 끝에 0이 붙는 경우
ll m[MAX];

// n[p][q] = 길이가 p고 마지막 자리수가 q인 이친수의 개수
// n[p][0] = n[p-1][1] + n[p-1][0]
// n[p][1] = n[p-1][0]
ll n[MAX][2];

void init() {
    m[1] = 1LL;
    m[2] = 1LL;

    n[1][0] = 0LL;
    n[1][1] = 1LL;
}

ll bottomUpM (int k) {
    for(int i = 3; i <= k; i++) {
        m[i] = m[i-1] + m[i-2];
    }

    return m[k];
}

ll topDownM (int k) {
    if(m[k] > 0) return m[k];

    m[k] = topDownM(k-1) + topDownM(k-2);

    return m[k];
}

ll bottomUpN(int p) {
    for(int i = 2; i <= p; i++) {
        n[i][0] = n[i-1][1] + n[i-1][0];
        n[i][1] = n[i-1][0];
    }

    return n[p][0] + n[p][1];
}

ll topDownN(int p, int q) {
    if(p==1 || n[p][q] > 0) return n[p][q];
    
    n[p][q] = topDownN(p-1, 0);
    if(q==0) n[p][q] += topDownN(p-1, 1);

    return n[p][q];
}

ll td(int p) {    
    return topDownN(p, 0) + topDownN(p, 1);
}

int main() {
    int k;
    scanf("%d", &k);
    init();
    printf("%lld\n", bottomUpM(k));
    return 0;
}