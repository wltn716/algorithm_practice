// 문제: https://www.acmicpc.net/problem/10809
#include <iostream>
#include <algorithm>
using namespace std;

int cnt[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill_n(cnt, 26, -1);

    string s;
    cin >> s;

    int idx = 0;
    for(char c : s){
        if(cnt[c-'a'] == -1) cnt[c-'a'] = idx;
        idx++;
    }

    for(int i: cnt){
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}