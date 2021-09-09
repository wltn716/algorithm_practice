// 문제: https://www.acmicpc.net/problem/11005
#include <iostream>
#include <string>
using namespace std;

string chg (int k, int b) {
    if(k < b && k >= 10){
        char c = k-10+'A';
        string s = "";
        s.append(1, c);
        return s;
    }
    else
        return to_string(k);
}

string to_b (int n, int b) {
    if(n/b == 0) {
        return chg(n, b);
    }   
    
    return to_b(n/b, b) + chg(n%b, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, b;
    cin >> n >> b;
    cout << to_b(n, b) << "\n";

    return 0;
}