// 문제: https://www.acmicpc.net/problem/2331
#include <iostream>
#define MAX 236197 //(9*9*9*9*9)*4+1
using namespace std;

int a, p;
int nth[MAX];

int next(int x) {
    int res = 0;
    while(x > 0) {
        int k = x%10;
        int tmp = k;
        for (int i = 0; i < p-1; i++){
            tmp *= k;
        }
        res += tmp;
        x /= 10;        
    }

    return res;
}

int dfs(int x) {
    int n = next(x);
    if(nth[n] == 0) {
        nth[n] = nth[x] + 1;
        return dfs(n);
    }

    return nth[n]-1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> p;
    nth[a] = 1;
    cout << dfs(a) << "\n";

    return 0;
}