// 문제: https://www.acmicpc.net/problem/2438
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=0;j<i;j++){
            cout << "*";
        }
        cout<<'\n';
    }

    return 0;
}