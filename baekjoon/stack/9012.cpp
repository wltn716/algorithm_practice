// 문제: https://www.acmicpc.net/problem/9012
#include <iostream>
#include <stack>
using namespace std;

string isVps(string data) {
    stack<char> s;

    for(char c : data){
        if(c == '(') s.push('(');
        else if(c == ')'){
            if(s.empty()){
                return "NO";
            }
            else s.pop();
        }
    }

    if(s.empty()) return "YES";

    return "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++){
        string data;
        cin >> data;

        cout << isVps(data) << "\n";
    }
    
    return 0;
}