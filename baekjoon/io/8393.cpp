// 문제: https://www.acmicpc.net/problem/8393
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    while(n) {
        sum += n;
        n--;
    }

    cout << sum << '\n';
    return 0;
}