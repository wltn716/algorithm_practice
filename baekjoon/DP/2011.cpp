// 문제: https://www.acmicpc.net/problem/2011
#include <iostream>
#include <cstring>
#define MAX 5001
#define MOD 1000000
using namespace std;
typedef long long ll;

char code[MAX];

// d[n] = n번째 숫자까지의 해석의 가짓수
// d[n] = d[n-1](+ d[n-2])
ll d[MAX];

ll bottomUp (int k) {
    if(code[1] == '0') return 0;

    d[0] = 1;
    d[1] = 1;
    for (int i = 2; i <= k; i++){
        int a = code[i] - '0';
        int b = code[i-1] - '0';
        
        if(a == 0) {
            if((b < 1 || b > 2)) return 0;
            else {
                d[i] = d[i-2];
            }
        }
        else {
            d[i] = d[i-1];
            if((b == 2 && a <= 6) || b == 1) {
                d[i] += d[i-2];
            }
        }

        d[i] %= MOD;
    }

    return d[k];
}

int main() {
    scanf("%s", code+1);
    int k = strlen(code+1);
    printf("%lld\n", bottomUp(k));
    return 0;
}