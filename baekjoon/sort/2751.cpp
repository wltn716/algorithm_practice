// 문제: https://www.acmicpc.net/problem/2751
#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int a[MAX];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", a+i);
    }

    sort(a, a+n);
    
    for (int i = 0; i < n; i++){
        printf("%d\n", a[i]);
    }
    

    return 0;
}