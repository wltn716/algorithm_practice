// 문제: https://www.acmicpc.net/problem/1373
#include <iostream>
#include <string>
using namespace std;

string to_8 (string bn) {
    int result = 0;
    int n = bn.length()-1;
    int pw = 1;
    for (int i = n; i >= 0; i--){
        int k = bn[i] - '0';
        result += k*pw;
        pw *= 2;
    }

    return result > 0 ? to_string(result) : "";
}

string sol (string n) {
    int k = n.length()%3;
    string s = to_8(n.substr(0, k));
    for (int i = k; i < n.length(); i+=3 ){
        s += to_8(n.substr(i, 3));
    }
    
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string bn;
    cin >> bn;
    cout << sol(bn) << "\n";

    return 0;
}