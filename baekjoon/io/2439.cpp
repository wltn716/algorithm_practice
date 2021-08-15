// 문제: https://www.acmicpc.net/problem/2439
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i=N;i>0;i--){
        for(int j=1;j<=N;j++){
            if(i<=j) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
    return 0;
}