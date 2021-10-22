// 문제: https://www.acmicpc.net/problem/2304
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int n, lft = 1001, rgt = 0, highst = 0;
int col[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    memset(col, 0, sizeof(col));

    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int l, h;
        cin >> l >> h;
        col[l] = h;
        lft = min(lft, l);
        rgt = max(rgt, l);
        highst = col[highst] < col[l] ? l : highst;
    }

    int ans = col[highst];

    // left
    int h = col[lft];
    for(int i = lft; i < highst; i++) {
        if(h < col[i]) h = col[i];            
        ans += h;
    }

    // right
    h = col[rgt];
    for(int i = rgt; i > highst; i--) {
        if(h < col[i]) h = col[i];
        ans += h;
    }

    cout << ans << "\n";

    return 0;
} 