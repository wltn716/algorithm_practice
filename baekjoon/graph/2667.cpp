// 문제: https://www.acmicpc.net/problem/2667
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 26
using namespace std;

int d_x[] = {-1, 0, 1, 0};
int d_y[] = {0, 1, 0, -1};
int visit[MAX][MAX];
int graph[MAX][MAX];
queue<pair<int, int>> q;
vector<int> ans;
int n;

void bfs() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(visit[i][j] != 1 && graph[i][j] == 1) {
                int cnt = 0;
                q.push({i, j});
                visit[i][j] = 1;

                while (!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();
                    cnt++;

                    for (int k = 0; k < 4; k++) {
                        int x = p.first + d_x[k];
                        int y = p.second + d_y[k];
                        if(visit[x][y] != 1 && graph[x][y] == 1) {
                            q.push({x, y});
                            visit[x][y] = 1;
                        }
                    }       
                }
                ans.push_back(cnt);
            }
        } 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    char tmp[n];

    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        for (int j = 1; j <= n; j++){
            graph[i][j] = tmp[j-1] - '0';
        }
    }

    bfs();
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int a : ans) {
        cout << a << "\n";
    }

    return 0;
}