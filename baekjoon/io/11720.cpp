// 문제: https://www.acmicpc.net/problem/11720
#include <iostream>
using namespace std;

int main() {
    int N;
    int sum = 0;
    cin >> N;
    getchar();
    for(int i=0;i<N;i++){
        sum += getchar() - '0';
    }

    cout << sum << '\n';
    return 0;
}