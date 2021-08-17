// 문제: https://www.acmicpc.net/problem/11727
#include <iostream>
#define MAX 1001
using namespace std;

//n[k] = n*k 크기 직사각형을 1*2, 2*1 타일로 채우는 방법의 수
//n[1] = 1, n[2] = 2,
//n[k] = n[k-1] + n[k-2]*2
int n[MAX];

int topDown(int k) {
    if(n[k] > 0) return n[k];
    n[k] = (topDown(k-1) + topDown(k-2)*2)%10007;

    return n[k];
}

int bottomUp(int k) {
    for (int i = 3; i <=k ; i++){
        n[i] = (n[i-1] + n[i-2]*2)%10007;
    }

    return n[k];
}

int main() {
    int k;
    scanf("%d", &k);

    n[1] = 1;
    n[2] = 3;
    printf("%d\n", bottomUp(k));
    return 0;
}