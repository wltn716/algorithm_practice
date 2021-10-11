// 문제: https://www.acmicpc.net/problem/11399
#include <iostream>
#include <algorithm>

using namespace std;;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p+n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            sum += p[j];
        }        
    }
    
    cout << sum << "\n";
    

    return 0;
} 