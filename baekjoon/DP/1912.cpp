// 문제: https://www.acmicpc.net/problem/1912
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int a[MAX];

// d[i] = max(d[i-1]+a[i], a[i])
int d[MAX];

int bottomUp(int k) {
    d[1] = a[1];
    for(int i = 2; i <= k; i++) {
        d[i] = max(d[i-1]+a[i], a[i]);
    }

    return *max_element(d+1, d+k+1);
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