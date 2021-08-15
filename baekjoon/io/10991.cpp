// 문제: https://www.acmicpc.net/problem/10991
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int n = N*2-1;
    for(int i=0;i<N;i++){
        for(int j=i;j<N-1;j++) cout << " ";
        for(int j=0;j<(i+1)*2-1;j++){
            if(j%2) cout << " ";
            else cout << "*";
        }
        cout << "\n";
    }

    return 0;
}