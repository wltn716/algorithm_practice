// 문제: https://www.acmicpc.net/problem/10950
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    for(int i=0;i<T;i++) {
        int A, B;
        cin >> A >> B;
        cout << A+B << '\n';
    }
    return 0;
}