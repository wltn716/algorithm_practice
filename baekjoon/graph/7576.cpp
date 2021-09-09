// 문제: https://www.acmicpc.net/problem/7576
#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int m, n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int box[MAX][MAX];
int days[MAX][MAX];
queue<pair<int, int>> q;
int ans = 0; // 다 익는 데 걸린 시간
int cnt = 0; // 익은 토마토의 개수
int total = 0;

void bfs() { //토마토의 위치
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int x = p.first + dx[i];
            int y = p.second + dy[i];
            if(x > 0 && x <= n && y > 0 && y <= m) {
                if(days[x][y] == -1 && box[x][y] != -1) {
                    cnt++;
                    days[x][y] = ans = days[p.first][p.second] + 1;
                    q.push({x, y});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            cin >> box[i][j];
            if(box[i][j] != -1){
                if(box[i][j] == 1) {
                    q.push({i, j});
                    days[i][j] = 0;
                    cnt++;
                }
                else days[i][j] = -1;
                total++;
            }
        }
    }
    
    bfs();
    
    ans = cnt == total ? ans : -1;
    cout << ans << "\n";

    return 0;
}