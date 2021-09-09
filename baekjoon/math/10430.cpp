// 문제: https://www.acmicpc.net/problem/10430
#include <iostream>
using namespace std;

// 다더하고 나머지 = '+' 연산 마다 나머지하고 최종 결과에 또 나머지
// 다곱하고 나머지 = '*' 연산 마다 나머지하고 최종 결과에 또 나머지

int a, b, c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << (a+b)%c << "\n";
    cout << (a%c+b%c)%c << "\n";
    cout << (a*b)%c << "\n";
    cout << ((a%c)*(b%c))%c << "\n";
    return 0;
}