// 문제: https://www.acmicpc.net/problem/2441
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(j<i) cout << " ";
            else cout << "*";
        }
        cout << "\n";
    }

    return 0;
}