// 문제: https://www.acmicpc.net/problem/9465
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;

// a[p][q] = 좌표 (q,p)의 점수
ll a[MAX][2];

// n[p][q] = p열에서 q로 뜯었을 때 2*p에서 얻을 수 있는 최대 점수
// q: 0 = 안뜯음, 1 = 위에 뜯음, 2 = 아래 뜯음
// n[p][0] = max(n[p-1][0], n[p-1][1], n[p-1][2])
// n[p][1] = max(n[p-1][0], n[p-1][2]) + a[p][0]
// n[p][2] = max(n[p-1][0], n[p-1][1]) + a[p][1]
ll n[MAX][3];

void init() {
    n[1][0] = 0LL;
    n[1][1] = a[1][0];
    n[1][2] = a[1][1];
}

ll bottomUp (int p) {
    for (int i = 2; i <= p; i++){
        n[i][0] = max({n[i-1][0], n[i-1][1], n[i-1][2]});
        n[i][1] = max({n[i-1][0], n[i-1][2]}) + a[i][0];
        n[i][2] = max({n[i-1][0], n[i-1][1]}) + a[i][1];
    }

    return max({n[p][0], n[p][1], n[p][2]});
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++){
        int p;
        scanf("%d", &p);
        for (int j = 0; j < 2; j++){
            for (int k = 1; k <= p; k++){
                scanf("%lld", &a[k][j]);
            }
        }
        
        init();
        printf("%lld\n", bottomUp(p));
    }
    
    return 0;
}