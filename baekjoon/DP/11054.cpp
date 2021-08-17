// 문제: https://www.acmicpc.net/problem/11054
#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int a[MAX];

// d[i] = MAX(d[j]+1) (i>j, a[j] < a[i])
int d[MAX];
// r[i] = MAX(r[j]+1) (i<j, a[j] < a[i])
int r[MAX];

int bottomUp(int k) {
    for (int i = 1; i <= k; i++){
        d[i] = 1;
        for(int j = 1; j < i; j++){
            if(a[i] > a[j] && d[j]+1 > d[i]){
                d[i] = d[j]+1;
            }
        }
    }

    for (int i = k; i > 0; i--){
        r[i] = 1;
        for(int j = k; j > i; j--){
            if(a[i] > a[j] && r[j]+1 > r[i]){
                r[i] = r[j]+1;
            }
        }

        d[i] += r[i]-1;
    }
    
    return *max_element(d+1, d+k+1);
}

int main() {
    int k;
    scanf("%d", &k);
    
    d[0] = 0;
    for (int i = 1; i <= k; i++){
        scanf("%d", a+i);
    }
    
    printf("%d\n", bottomUp(k));
    return 0;
}