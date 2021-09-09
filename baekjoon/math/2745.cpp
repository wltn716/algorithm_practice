// 문제: https://www.acmicpc.net/problem/2745
#include <iostream>
#include <string>
using namespace std;

int to_n (string bn, int b) {
    int result = 0;
    int n = bn.length()-1;
    int pw = 1;
    for (int i = n; i >= 0; i--){
        int k;
        if(isdigit(bn[i])) k = bn[i] - '0';
        else k = bn[i] - 'A' + 10;

        result += k*pw;
        pw *= b;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int b;
    string bn;
    cin >> bn >> b;
    cout << to_n(bn, b) << "\n";

    return 0;
}