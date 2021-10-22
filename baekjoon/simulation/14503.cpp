// 문제: https://www.acmicpc.net/problem/14503
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

int n, m, r, c, d;
int rx[] = {0, -1, 0, 1};
int ry[] = {-1, 0, 1, 0};
int bx[] = {1, 0, -1, 0};
int by[] = {0, -1, 0, 1};
int clean[50][50];
int room[50][50];
int ans = 1;
int call = 0;

bool valid(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return false;

    if(room[x][y] == 1) return false;

    return clean[x][y] != 1;
}

void search(int rotate) {
    int x = r + rx[d];
    int y = c + ry[d];
    d = d == 0 ? 3 : d-1;

    if(valid(x, y)) { //청소 가능하다면
        // 회전한 다음
        // 전진하고
        r = x;
        c = y;

        // 청소한다.
        clean[x][y] = 1;
        ans++;

        // 반복
        search(0);
    }
    else {
        if(rotate < 3) {
            // 회전한 다음
            // 반복
            search(rotate + 1);
        }
        else {
            // 방향 원복
            // 후진
            x = r + bx[d];
            y = c + by[d];

            // 후진할 수 없다면 작동 중지
            if(x < 0 || x >= n || y < 0 || y >= m) return;
            if(room[x][y] == 1) return;

            // 후진할 수 있다면, 후진한 후 반복
            r = x;
            c = y;
            search(0);
        }        
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
    
    clean[r][c] = 1;

    search(0);

    cout << ans << "\n";

    return 0;
} 