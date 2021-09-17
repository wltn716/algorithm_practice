// 문제: https://www.acmicpc.net/problem/2146
#include <iostream>
#include <queue>
#include <cstring>
#define MAX 102
using namespace std;

int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int graph[MAX][MAX];
int map[MAX][MAX];
int visit[MAX][MAX];
int color = 0;
int length = 200;
queue<pair<int, int>> q;

bool check_idx(int x, int y) {
    if(x > 0 && x <= n && y > 0 && y <= n)
        return true;
    
    return false;
}

void bfs_map() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(visit[i][j] != 1 && graph[i][j] == 1) {
                color++;
                q.push({i, j});
                visit[i][j] = 1;
                map[i][j] = color;

                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int x = p.first + dx[k];
                        int y = p.second + dy[k];

                        if(check_idx(x, y) && visit[x][y] != 1 && graph[x][y] == 1) {
                            q.push({x, y});
                            visit[x][y] = 1;
                            map[x][y] = color;
                        }
                    }
                }
            }
        }        
    }
}

void bfs_length(int l) {
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) {
            if(map[i][j] == l) {
                visit[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int x = p.first + dx[k];
            int y = p.second + dy[k];

            if(check_idx(x, y) && visit[x][y] == -1 ) {
                if(map[x][y] == 0) {
                    visit[x][y] = visit[p.first][p.second] + 1;
                    q.push({x, y});
                }
                else {
                    length = min(length, visit[p.first][p.second]);
                    q = queue<pair<int, int>>();
                    break;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }    

    bfs_map();

    for (int i = 1; i <= color; i++){
        memset(visit, -1, sizeof(visit));
        bfs_length(i);
    }

    cout << length << "\n";


    return 0;
}