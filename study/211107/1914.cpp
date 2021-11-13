// 문제: https://www.acmicpc.net/problem/1914
#include <iostream>
#include <cmath>

using namespace std;

typedef unsigned long long ull;

void hanoi(int n, int from, int tmp, int to) {
    if(n == 1){
        cout << from << " " << to << "\n";
    }
    else {
        hanoi(n-1, from, to, tmp);
        cout << from << " " << to << "\n";
        hanoi(n-1, tmp, from, to);
    }        
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    string k = to_string(pow(2, n));
    int idx = k.find('.');
    k = k.substr(0, idx);
    k[k.length() - 1] -= 1;
    cout << k << "\n";
    
    if(n > 20) return 0;

    hanoi(n, 1, 2, 3);

    return 0;
} 