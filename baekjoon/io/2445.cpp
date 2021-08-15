// 문제: https://www.acmicpc.net/problem/2445
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int N;
    cin >> N;
    int n = 2*N-1;
    for(int i=1;i<=n;i++) {
        for(int j=N;j>0;j--){
            if(j>abs(N-i)) cout << "*";
            else cout << " ";
        }
        for(int j=1;j<=N;j++){
            if(j>abs(N-i)) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
    return 0;
}