// 문제: https://www.acmicpc.net/problem/10799
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;
    stack<char> s;
    string str;
    char temp;
    cin >> str;

    for(char c: str){
        if(c==')') {
            s.pop();
            if(temp=='(') {
                ans += s.size();
            }
            else ans++;
        }
        else s.push(c);

        temp = c;
        
    }

    cout << ans <<"\n";
    
    return 0;
}