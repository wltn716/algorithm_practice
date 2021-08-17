// 문제: https://www.acmicpc.net/problem/1463
#include <iostream>
#include <cstdlib>
#define MAX 1000001
using namespace std;

//n[k] = k를 1로 만드는데 필요한 최소 연산 횟수
//n[k] = min(n[k-1], n[k/2], n[k/3]) + 1;
int n[MAX];

//37056kb, 40ms
int topDown(int k) {
    if(k==1) return 0;
    if(n[k] > 0) return n[k];

    n[k] = topDown(k-1)+1;
    
    if(k%2 == 0) {
        n[k] = min(n[k], topDown(k/2)+1);
    }
    
    if(k%3 == 0) {
        n[k] = min(n[k], topDown(k/3)+1);
    }

    return n[k];
}

//5928kb, 4ms
int bottomUp(int k) {
    n[1] = 0;

    for (int i = 2; i <= k; i++) {
        n[i] = n[i-1]+1;
    
        if(i%2 == 0) {
            n[i] = min(n[i], n[i/2]+1);
        }
        
        if(i%3 == 0) {
            n[i] = min(n[i], n[i/3]+1);
        }
    }

    return n[k];
}

int main() {
    int k;
    scanf("%d", &k);
    printf("%d\n",topDown(k));
    return 0;
}