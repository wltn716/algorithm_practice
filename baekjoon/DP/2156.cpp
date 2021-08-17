// 문제: https://www.acmicpc.net/problem/2156
#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

// a[i] = i번째 포도주의 양
int a[MAX];

// d[i][j] = i번째 포도주를 j했을 때의 최대 양
// j: 0 = 안마신다, 1 = 마신다
// 점화식 1 :
//  d[i][0] = max(d[i-1][0], d[i-1][1])
//  d[i][1] = max(d[i-1][0], d[i-2][0]+a[i-1]) + a[i] 
// 점화식 2:
//  d[i] = max(d[i-1], d[i-2]+a[i], d[i-3]+a[i-1]+a[i])
//  i번째 안마실 경우  vs 연속 1번으로 마실 경우 vs 연속 2번으로 마실 경우
int d[MAX];

void init() {
    d[0] = 0;
    d[1] = a[1];
    d[2] = a[1] + a[2];
}

int bottomUp(int k) {
    for (int i = 3; i <= k; i++){
        d[i] = max({d[i-1], d[i-2]+a[i], d[i-3]+a[i-1]+a[i]});
    }
    
    return d[k];
}

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++){
        scanf("%d", a+i);
    }

    init();
    printf("%d\n", bottomUp(k));
    return 0;
}