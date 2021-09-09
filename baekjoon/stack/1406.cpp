// 문제: https://www.acmicpc.net/problem/1406
#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> left;
    stack<char> right;

    string str;
    cin >> str;

    for(char c: str){
        left.push(c);
    }

    int m;
    cin >> m;

    while(m--) {
        char ins;
        cin >> ins;
        if(ins == 'L' && !left.empty()){
            right.push(left.top());
            left.pop();
        }
        else if(ins == 'D' && !right.empty()) {
            left.push(right.top());
            right.pop();
        }
        else if(ins == 'B' && !left.empty()){
            left.pop();
        }
        else if(ins == 'P'){
            char s;
            cin >> s;
            left.push(s);
        }

    }

    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }

    while(!right.empty()){
        cout << right.top();
        right.pop();
    }
    
    cout << "\n";

    return 0;
}