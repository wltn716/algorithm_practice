// 문제: https://www.acmicpc.net/problem/2580
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vec;

int n, h, d, ans = -1;
char graph[500][500];
char visit[500][500];
pair<int, int> s;
queue<pair<int, int>> q;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(pair<int, int> cur, int um, int ph, int cnt) {
    visit[cur.first][cur.second] = 1;

    for(int i =0;i<4;i++){
        int x = cur.first+dx[i];
        int y = cur.second+dy[i];
        if(x>=0 && x<n && y>=0 && y<n) {
            if(visit[x][y] != 1) {
                if(graph[x][y] == 'E') {
                    if(ans != -1)
                        ans = min(ans, cnt+1);
                    else ans = cnt+1;
                }    
                else if(graph[x][y] == 'U') {
                    dfs(make_pair(x, y), d, ph, cnt+1);
                }
                else {
                    if(um == 0) {
                        if(ph-1 > 0)
                           dfs(make_pair(x, y), um, ph-1, cnt+1);
                        else return;
                    }    
                    else dfs(make_pair(x, y), um-1, ph, cnt+1);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int visit[500][500];
    memset(visit, 0, sizeof(visit));

    cin >> n >> h >> d;
    
    for (int i = 0; i < n; i++){
        cin >> graph[i];
        for (int j = 0; j < n; j++){
            if(graph[i][j] == 'S') {
                s.first = i;
                s.second = j;
            }
        }        
    }
    dfs(s, 0, h, 0);
    cout << ans << "\n";

    return 0;
} 