// 문제: https://www.acmicpc.net/problem/11724
#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, m;
int visit[MAX];
int graph[MAX][MAX];

void dfs(int x) {
    visit[x] = 1;
    for (int i = 1; i <= n; i++){
        if(graph[x][i] && visit[i] != 1) {
            dfs(i);
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if(visit[i] != 1) {
            ans++;
            dfs(i);
        }
    }
    
    cout << ans << "\n";

    return 0;
}