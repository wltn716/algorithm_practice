// 문제: https://www.acmicpc.net/problem/2442
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int n = 2*N-1;
    for(int i=0;i<N;i++){
        for(int k=n/2-1;k>=0;k--){
            if(k<i) cout << "*";
            else cout << " ";
        }
        cout << "*";
        for(int k=0;k<n/2;k++){
            if(i>k) cout << "*";
        }
        cout << "\n";
    }

    return 0;
}