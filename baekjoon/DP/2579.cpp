// 문제: https://www.acmicpc.net/problem/2579
#include <iostream>
#define MAX 301
using namespace std;

int a[MAX];

// d[i] = max(d[i-2]+a[i], d[i-3]+a[i-1]+a[i])
int d[MAX];

void init() {
    d[0] = 0;
    d[1] = a[1];
    d[2] = a[1] + a[2];
}

int bottomUp(int k) {
    init();
    for(int i = 3; i <= k; i++) {
        d[i] = max(d[i-2]+a[i], d[i-3]+a[i-1]+a[i]);
    }

    return d[k];
}

int main() {
    int k;
    scanf("%d", &k);
    
    for (int i = 1; i <= k; i++){
        scanf("%d", a+i);
    }
    
    printf("%d\n", bottomUp(k));
    return 0;
}