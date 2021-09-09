// 문제: https://www.acmicpc.net/problem/10808
#include <iostream>
using namespace std;

int cnt[26] = {0,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    for(char c : s){
        cnt[c-'a']++;
    }

    for(int i: cnt){
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}