// 문제: https://www.acmicpc.net/problem/2178
#include <iostream>
#include <queue>
#define MAX 102
using namespace std;

queue<pair<int, int>> q;
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int graph[MAX][MAX];
int visit[MAX][MAX];

int bfs() {
    visit[1][1] = 1;
    q.push({1, 1});

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            int x = p.first + dx[i];
            int y = p.second + dy[i];

            if(graph[x][y] && !visit[x][y]) {
                visit[x][y] = visit[p.first][p.second] + 1;
                if(x == n && y == m) return visit[x][y];
                q.push({x, y});
            }
        }
    }

    return visit[n][m];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    char tmp[m]; 
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        for (int j = 1; j <= m; j++) {
            graph[i][j] = tmp[j-1]-'0';
        }
    }
    
    cout << bfs() << "\n";

    return 0;
}