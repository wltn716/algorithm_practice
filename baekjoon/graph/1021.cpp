// 문제: https://www.acmicpc.net/problem/1021
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int t, m, n, k;
vector<vector<int>> ground;
vector<vector<int>> visit;
deque<pair<int, int>> dq;

void solution() {
    int grp = 0;

    while(!dq.empty()) {
        pair<int, int> p = dq.front();
        dq.pop_front();

        int x = p.first;
        int y = p.second;

        // 그래프의 시작일 경우
        if(visit[x][y] == 0) {
            visit[x][y] = ++grp;
        }

        // 이미 다른 그래프를 통해 탐색된 경우
        if(visit[x][y] != grp) continue;
        

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if(visit[nx][ny] == 0 && ground[nx][ny] == 1) {
                    visit[nx][ny] = visit[x][y];
                    dq.push_front({nx, ny});
                }
            }
        }
    }

    cout << grp << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> t;

    while(t--) {
        cin >> m >> n >> k;

        ground.assign(n, vector<int>(m, 0));
        visit.assign(n, vector<int>(m, 0));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> y >> x;
            ground[x][y] = 1;
            dq.push_back({x, y});
        }

        solution();

        ground.clear();
        visit.clear();
    }

    return 0;
} 