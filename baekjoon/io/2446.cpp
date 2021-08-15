// 문제: https://www.acmicpc.net/problem/2446
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int N;
    cin >> N;
    int n = 2*N-1;
    for(int i=1;i<=n;i++){
        int k = abs(N-i);
        for(int j=N-1;j>0;j--){
            if(j<=k) cout << "*";
            else cout << " ";
        }
        cout << "*";
        for(int j=1;j<N;j++){
            if(k>=j) cout << "*";
        }
        cout<<"\n";
    }
    return 0;
}