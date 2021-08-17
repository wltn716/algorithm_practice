// 문제: https://www.acmicpc.net/problem/1699
#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

// d[i] = min(d[i-j*j])+1 (i>j*j)
int d[MAX];

int bottomUp(int k) {
    for (int i = 1; i <= k; i++){
        d[i] = i;
        for(int j = 1; j*j <= i; j++) {
            if(d[i-j*j]+1 < d[i])
                d[i] = d[i-j*j]+1;
        }
    }

    return d[k];
}

int main() {
    int k;
    scanf("%d", &k);
    printf("%d\n", bottomUp(k));
    return 0;
}