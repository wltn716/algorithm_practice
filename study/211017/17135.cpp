// 문제: https://www.acmicpc.net/problem/17135
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#define x first
#define y second

using namespace std;

typedef pair<int, int> pi;

int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};
int n, m, d;
vector<vector<int>> board;
vector<vector<int>> on_board;
vector<int> archers; // 궁수 위치
vector<int> pos_a;   // 궁수 위치 모음
set<pi> enemies;     // 공격당한 적
int cnt = 0; // 적의 수
int ans = -1;

// 거리 구하기
int get_dis(pi enemy, pi archer) {
    return abs(archer.x - enemy.x) + abs(archer.y - enemy.y);
}

// 가까운 적 탐색
pi bfs(pi archer) {
    if(on_board[archer.x-1][archer.y] == 1) return {archer.x-1, archer.y};

    queue<pi> q;
    vector<vector<int>> visit(n, vector<int>(m, 0));

    q.push({archer.x-1, archer.y});
    visit[archer.x-1][archer.y] = 1;

    while(!q.empty()) {
        pi top = q.front();
        q.pop();

        for(int i = 0; i < 3; i++) {
            int nx = top.x + dx[i];
            int ny = top.y + dy[i];

            if(ny >= 0 && ny < m && nx >= 0 && nx < n) {
                if(visit[nx][ny] != 1 && get_dis({nx, ny} ,archer) <= d) {
                    if(on_board[nx][ny] == 1) return {nx, ny};
                    q.push({nx, ny});
                    visit[nx][ny] = 1;
                }
            }
        }
    }

    return {-1, -1};
}

// 적 전진
int move_foward() {
    on_board.insert(on_board.begin(), vector<int>(m, 0));

    int k = 0;
    for(int i : on_board.back()) {
        if(i == 1) k++;
    }

    on_board.pop_back();
    return k;
}

void do_game() {
    // 초기화
    on_board = board;
    int on_cnt = cnt;
    int kill = 0;

    // 모든 적이 격자판에서 제외 될 까지
    while(on_cnt > 0) {
        for(int a : pos_a) { // 궁수 순회
            pi enemy = bfs({n, a});
            if(enemy.x != -1 && enemy.y != -1) {
                enemies.insert(enemy);
            }              
        }

        // 공격당한 적 처리
        for (pi e : enemies) {
            kill++;
            on_cnt--;
            on_board[e.x][e.y] = 0;
        }
        enemies.clear();

        // 전진 후 남은 적 계산
        on_cnt -= move_foward();
    }

    // cout << kill << "\n";
    ans = max(kill, ans);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m >> d;

    board.resize(n, vector<int>(m, 0));
    archers.resize(3,1);
    archers.resize(m,0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) cnt++;
        }
    }

    do {
        pos_a.clear();
        for(int i=0; i<m; i++) {
            if(archers[i] == 1) {
                pos_a.push_back(i);
                if(pos_a.size() == 3) break;
            }
        }

        // cout << "\n";
        do_game();
        // cout << "\n";

    } while(prev_permutation(archers.begin(), archers.end()));

    cout << ans << "\n";

    return 0;
} 