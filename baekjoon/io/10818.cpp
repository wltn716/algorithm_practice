// 문제: https://www.acmicpc.net/problem/10818
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int a = 1000001;
    int b = -1000001;
    for(int i=0;i<N;i++){
        int n;
        cin >> n;
        a = min(a, n);
        b = max(b, n);
    }
    cout << a << " " << b << '\n';
    return 0;
}