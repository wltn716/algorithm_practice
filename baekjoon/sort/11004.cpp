// 문제: https://www.acmicpc.net/problem/11004
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 5000000
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> v(n);

    for (int i = 0; i < n; i++){
        scanf("%d", v.begin()+i);
    }

    nth_element(v.begin(), next(v.begin(), k-1), v.end());
    
    printf("%d\n", v[k-1]);
    return 0;
}