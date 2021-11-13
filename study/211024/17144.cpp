// 문제: https://www.acmicpc.net/problem/17144
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

typedef long long ll;

int dx[] = {0, -1, 0, 1, 0, 1, 0, -1};
int dy[] = {1, 0, -1, 0, 1, 0, -1, 0};
int r, c, t;
vector<vector<int>> a;
vector<vector<int>> ta;

int upx = -1, upy = -1;
int dwx, dwy;

struct cmp {
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return a[p1.first][p1.second] > a[p2.first][p2.second];
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void mv (int x, int y, int st, int ed) {
    int nx = x, ny = y;
    int tmp1 = 0, tmp2 = 0;
    for(int i = st; i < ed; i++) {
        if(i%4 != 0) {
            nx -= dx[i-1];
            ny -= dy[i-1];
        }
        
        nx += dx[i];
        ny += dy[i];

        while(nx < r && nx >= 0 && ny < c && ny >= 0 && (nx != x || ny != y)) {
            tmp2 = a[nx][ny];
            a[nx][ny] = tmp1;
            tmp1 = tmp2;

            nx += dx[i];
            ny += dy[i];
        };
    }
}

void circle() {
    // up
    mv(upx, upy, 0, 4);
    // down
    mv(dwx, dwy, 4, 8);
}

void spread() {
    while(!pq.empty()) {
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();

        cout << x << " " << y << " " << a[x][y] << "\n";
        int k = a[x][y] / 5;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < r && nx >= 0 && ny < c && ny >= 0 && (nx != dwx || ny != dwy) && (nx != upx || ny != upy)) {
                ta[nx][ny] += k;
                ta[x][y] -= k;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }

    a = ta;
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> r >> c >> t;

    a.resize(r, vector<int>(c));
    ta.resize(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            
            if(a[i][j] == -1) {
                if(upx == -1) {
                    upx = i; upy = j;
                }
                else {
                    dwx = i; dwy = j;
                }
            }

            if(a[i][j]/5 > 0) {
                pq.push({i, j});
            }
        }
    }

    ta = a;    

    while(t--) {
        cout << "\n";
        spread();

        
        
        circle();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(a[i][j]/5 > 0) {
                    pq.push({i, j});
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(a[i][j] != -1)
                sum += a[i][j];
        }
    }

    cout << sum << "\n";

    return 0;
} 