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

bool searchable (int x, int y) {
    if(x >= 0 && x < n && y >= 0 && y < m) {
        if(visit[x][y] == 0 && ground[x][y] == 1) {
            return true;
        }

        return false;
    }

    return false;
}

void solution() {
    int ans = 0;
    int grp = 0;

    while(!dq.empty()) {
        pair<int, int> p = dq.front();
        dq.pop_front();

        int x = p.first;
        int y = p.second;

        if(visit[x][y] == 0) {
            ans++;
            visit[x][y] = ++grp;
        }

        if(visit[x][y] != grp) continue;
        

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(searchable(nx, ny)) {
                visit[nx][ny] = visit[x][y];
                dq.push_front({nx, ny});
            }
        }

    }

    cout << ans << "\n";
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