// 문제: https://www.acmicpc.net/problem/12100
#include <iostream>
#include <cstring>

using namespace std;

int h, w, longest = 0;
int d2[500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> h >> w;

    for(int i = 0; i < w; i++) {
        cin >> d2[i];
        longest = d2[i] > d2[longest] ? i : longest;
    }

    if(d2[longest] == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int ans = 0;
    int h = 0;
    for(int i = 0; i < longest; i++) {
        if(d2[h] > d2[i]) ans += d2[h] - d2[i];
        else h = i;
    }

    h = w - 1;
    for(int i = w-1; i > longest; i--) {
        if(d2[h] > d2[i]) ans += d2[h] - d2[i];
        else h = i;
    }

    cout << ans << "\n";

    return 0;
} 