// 문제: https://www.acmicpc.net/problem/18405
#include <iostream>
#include <vector>
#include <queue>
#define MAX 200
#define all(v) v.begin(), v.end()

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, k, s, a, b;
int d[MAX][MAX];
int v[MAX][MAX];

typedef pair<int, int> pi;

struct comp {
    bool operator()(pi p1, pi p2) {
        if(v[p1.first][p1.second] == v[p2.first][p2.second])
            return d[p1.first][p1.second] > d[p2.first][p2.second];
        else
            return v[p1.first][p1.second] > v[p2.first][p2.second];
    }
};

priority_queue<pi, vector<pi>, comp> q;

int bfs() {
    while(!q.empty()) {
        pi xy = q.top();
        int x = xy.first;
        int y = xy.second;
        
        if(v[x][y] == s) {
            return d[a-1][b-1];        
        }

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if(v[nx][ny] == -1) {
                v[nx][ny] = v[x][y] + 1;
                d[nx][ny] = d[x][y];

                if(nx == a-1 && ny == b-1) return d[nx][ny];
                
                q.push({nx, ny});
            }
        }
    
    }

    return d[a-1][b-1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
            if(d[i][j] != 0) {
                v[i][j] = 0;
                q.push({i, j});
            }
            else {
                v[i][j] = -1;
            }
        }
    }

    cin >> s >> a >> b;
    
    if(v[a][b] < 0)
        cout << bfs() << "\n";
    else
        cout << d[a-1][b-1] << "\n";

    return 0;
} 