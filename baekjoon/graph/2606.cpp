// 문제: https://www.acmicpc.net/problem/2606
#include <iostream>

using namespace std;

int n, c;
int g[100][100];
int visit[100];
int ans = -1;

void dfs(int node) {
    visit[node] = 1;
    ans++;

    for(int i = 0; i < n; i++) {
        if(visit[i] == 0 && g[i][node] == 1) {
            dfs(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> c;

    while(c--) {
        int from, to;
        cin >> from >> to;
        g[--from][--to] = 1;
        g[to][from] = 1; 
    }

    dfs(0);

    cout << ans << "\n";


    return 0;
} 