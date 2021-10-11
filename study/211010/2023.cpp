// 문제: https://www.acmicpc.net/problem/12100
#include <iostream>
using namespace std;

int n;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i=2; i*i<=n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void dfs (int num, int cnt) {
    if(cnt == n) {
        cout << num << "\n";
        return;
    }

    for (size_t i = 0; i < 10; i++) {
        int tmp = num*10+i;
        if(is_prime(tmp)) dfs(tmp, cnt+1);
    }    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i=1; i < 10; i++) {
        if (is_prime(i)) {
            dfs(i, 1);
        }
    }

    return 0;
} 