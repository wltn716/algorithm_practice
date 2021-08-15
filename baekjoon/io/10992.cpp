// 문제: https://www.acmicpc.net/problem/10992
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=i;j<N;j++) cout << " ";
        int n = i*2-1;
        for(int j=0;j<n;j++){
            if(j==0||j==n-1) cout << "*";
            else{
                if(i==N) cout << "*";
                else cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}