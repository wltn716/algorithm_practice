// 문제: https://www.acmicpc.net/problem/16362
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string exp;
    cin >> exp;
    stack<char> s;

    for(auto c : exp) {
        if(c == ' ') continue;
        if(c == ')') {
            if(s.size() < 0) {
                cout << "error" << "\n";
                return 0;
            }
        

        }
    }

    return 0;
} 