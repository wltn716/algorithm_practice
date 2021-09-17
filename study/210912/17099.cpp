// 문제: https://www.acmicpc.net/problem/17099
#include <iostream>
#include <stack>

using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    stack<char> s;
    string k;
    cin >> k;

    char bf;

    for(char c: k) {
        if(c == ')') {
            s.pop();

            if(bf == '(')
                ans += s.size();
            else
                ans += 1;
        }
        else s.push(c);

        bf = c;
    }
    
    cout << ans << "\n";

    return 0;
}