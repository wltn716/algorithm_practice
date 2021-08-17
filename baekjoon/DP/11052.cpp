// 문제: https://www.acmicpc.net/problem/11052
#include <iostream>
#define MAX 1001
using namespace std;

int p[MAX];

//d[n] = max(d[0]+p[n], d[1]+p[n-1], d[2]+p[n-2], ... , d[n-1] + p[1])
int d[MAX];

int bottomUp (int n) {
    d[0] = 0;
    for (int i = 1; i <= n; i++){
        d[i] = 0;
        for (int j = 0; j < i; j++){
            int temp = d[j] + p[i-j];
            if(d[i] < temp) d[i] = temp;
        }
    }

    return d[n];
    
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", p + i);
    }
    
    printf("%d", bottomUp(n));

    return 0;
}