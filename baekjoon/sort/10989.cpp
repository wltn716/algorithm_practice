// 문제: https://www.acmicpc.net/problem/10989
#include <iostream>
#include <vector>
#define MAX 10001
using namespace std;

int a[MAX] = {0, };

int main() {
    int n, k;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &k);
        a[k]++; 
    }
    
    for (int i = 0; i < 10001; i++){
        for (int j = 0; j < a[i]; j++){
            printf("%d\n", i);
        }
    }
    

    return 0;
}

