// 문제: https://www.acmicpc.net/problem/4963
#include <iostream>
#include <queue>
#define MAX 51
using namespace std;

queue<pair<int, int>> q;
int visit[MAX][MAX];
int graph[MAX][MAX];
int d_x[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int d_y[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int w, h;

void bfs (int i, int j) {
    visit[i][j] = 1;
    q.push({i, j});

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int k = 0; k < 8; k++){
            int x = p.first + d_x[k];
            int y = p.second + d_y[k];

            if(!visit[x][y]& graph[x][y]) {
                visit[x][y] = 1;
                q.push({x, y});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1) {
        cin >> w >> h;
        if(w == 0 && h == 0) break;

        for (int i = 1; i <= h; i++){
            for (int j = 1; j <= w; j++){
                cin >> graph[i][j];
                visit[i][j] = 0;
            }
        }

        int cnt = 0;
        for (int i = 1; i <= h; i++){
            for (int j = 1; j <= w; j++){
                if(!visit[i][j]&& graph[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}