// 문제: https://www.acmicpc.net/problem/2873
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int visit[1000][1000];
int r, c;
string ans = "";
vector<vector<int>> site;

void search(int x, int y) {
    visit[x][y] = 1;
    int xx, yy;
    int val = 0;
    char dir;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < r && ny < c) {
            if(val < site[nx][ny] && visit[nx][ny] != 1) {
                val = site[nx][ny];
                xx = nx; yy = ny;
                if(i == 0) dir = 'U';
                else if(i == 1) dir = 'R';
                else if(i == 2) dir = 'D';
                else if(i == 3) dir = 'L';
            }
        }
    }
    ans += dir;
    if(xx == r-1 && yy == c-1) return;
    search(xx, yy);    
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        vector<int> tmp;
        for (int j = 0; j < c; j++) {
            int k;
            cin >> k;
            tmp.push_back(k);
        }
        site.push_back(tmp);
    }

    if(c%2) {
        int t = c;
        char k = 'R';
        while(t--) {
            ans += string(c-1, k);
            if(t) ans += "D";
            k = k == 'R' ? 'L' : 'R';
        }
    }
    else if(r%2) {
        int t = r;
        char k = 'D';
        while(t--) {
            ans += string(c-1, k);
            if(t) ans += "R";
            k = k == 'D' ? 'U' : 'D';
        }
    }
    else {
        search(0, 0);
    }

    cout << ans << "\n";
    return 0;
} 