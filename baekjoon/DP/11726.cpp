// 문제: https://www.acmicpc.net/problem/11726
#include <iostream>
#define MAX 1001
using namespace std;

//n[k] = n*k 크기 직사각형을 1*2, 2*1 타일로 채우는 방법의 수
//n[1] = 1, n[2] = 2,
//n[k] = n[k-1] + n[k-2]
//n[k-2]에 2 안곱하는 이유: 세로로 길게 두개 붙인 경우가 n[k-1]에 길게 하나 붙인 경우에 포함되기 때문
int n[MAX];

//다 연산 후 출력 시에 10007 나머지 연산하면 오버플로우로 에러남
int topDown(int k) {
    if(k==1 || k==2) {
        n[k] = k;
        return n[k];
    }
    if(n[k]>0) {
        return n[k];
    }

    n[k] = (topDown(k-1) + topDown(k-2))%10007;

    return n[k];
}

int bottomUp(int k) {
    n[1] = 1;
    n[2] = 2;

    for (int i = 3; i <= k; i++) {
        n[i] = (n[i-1] + n[i-2])%10007;
    }

    return n[k];
}

int main() {
    int k;
    scanf("%d", &k);
    printf("%d\n", topDown(k));
    return 0;
}