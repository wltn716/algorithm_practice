// 문제: https://www.acmicpc.net/problem/9095
#include <iostream>
#define MAX 11
using namespace std;

//n[k] = k를 1,2,3의 합으로 나타내는 방법의 수
//n[k] = n[k-1] + n[k-2] + n[k-3]
int n[MAX];

int topDown(int k) {
    if(n[k] > 0) return n[k];

    n[k] = topDown(k-1) + topDown(k-2) + topDown(k-3);

    return n[k];
}

int bottomUp(int k) {
    for (int i = 4; i <= k; i++){
        n[i] = n[i-1] + n[i-2] + n[i-3];
    }

    return n[k];
    
}

int main() {
    int T;
    n[1] = 1;
    n[2] = 2;
    n[3] = 4;
    
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        int k;
        scanf("%d", &k);
        printf("%d\n", topDown(k));
    }
    
    return 0;
}