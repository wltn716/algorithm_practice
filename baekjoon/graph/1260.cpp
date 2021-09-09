// 문제: https://www.acmicpc.net/problem/1260
#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int visit[MAX];
int graph[MAX][MAX];
int n, m, v;


void dfs(int x) {
    visit[x] = 1;
    cout << x << " ";

    for (int i = 1; i <= n; i++){
        if(graph[x][i] && visit[i] != 1) {
            dfs(i);
        }
    }
}

void bfs(int x) {
    visit[x] = 1;
    cout << x << " ";

    queue<int> q;
    q.push(x);

    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (int j = 1; j <= n; j++){
            if(graph[k][j] && visit[j] != 1) {
                visit[j] = 1;
                cout << j << " ";
                q.push(j);
            }
        } 
    } 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;

    for (int i = 0; i < m; i++){
        int from, to;
        cin >> from >> to;
        graph[from][to] = graph[to][from] = 1;
    }
    
    dfs(v);
    cout << "\n";

    fill(visit, visit+n+1, 0);
    bfs(v);

    return 0;
}