// 문제: https://www.acmicpc.net/problem/11656
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> v;
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++){
        v.push_back(s.substr(i));
    }

    sort(v.begin(), v.end());

    for(string str : v) {
        cout << str << "\n";
    }
    
    return 0;
}