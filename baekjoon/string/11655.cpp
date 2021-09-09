// 문제: https://www.acmicpc.net/problem/11655
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    getline(cin, str);
    
    for(char c: str) {
        char encrypt = c;
        if(isalpha(c)){
            int k = c >= 97 ? 'a' : 'A';
            encrypt = (c-k+13)%26+k;
        }
        cout << encrypt;
    }

    cout << "\n";

    return 0;
}