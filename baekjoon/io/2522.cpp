// 문제: https://www.acmicpc.net/problem/2522
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int N;
    cin >> N;
    int n = 2*N-1;
    for(int i=1;i<=n;i++){
        int k = abs(N-i);
        for(int j=0;j<N;j++){
            if(j<k) cout << " ";
            else cout << "*";
        }
        cout << "\n";
    }
    return 0;
}