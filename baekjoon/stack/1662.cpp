// 문제: https://www.acmicpc.net/problem/1662
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    stack<int> num;
    stack<int> str;
    string s;
    cin >> s;

    int tmp_n = -1;
    for(auto c : s) {
        if(c == ')') {
            int part = str.top();
            int repeat = num.top();
            str.pop();
            num.pop();

            str.top() += part*repeat;
            tmp_n = -1;
        } else if(c == '(') {
            if(tmp_n != -1) {
                str.top() -= 1;
                num.push(tmp_n);
                tmp_n = -1;
            }
            str.push(0);
        } else {
            if(str.empty()) str.push(0);
            str.top() += 1;
            tmp_n = c - '0';
        }
    }

    cout << str.top() << "\n";

    return 0;
} 