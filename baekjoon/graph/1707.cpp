// 문제: https://www.acmicpc.net/problem/1707
// 각 그룹에 색을 칠한다고 가정!
// 이분 그래프이므로 가능한 그룹의 수는 2!
// 따라서 0: 아직 안칠함, 1: 1번 색깔, 2: 2번 색깔 이렇게 세가지 경우 존재!
#include <iostream>
#include <vector>
#define MAX 20001
using namespace std;

int k, v, e;
int check[MAX];
vector<int> graph[MAX];

bool dfs(int x, int color) {
    check[x] = color;
    for (int i = 0; i < graph[x].size(); i++){
        int node = graph[x][i];
        if(check[node] == 0) {
            if(dfs(node, 3-color) == false)
                return false;
        }
        else{
            if(check[node] == color)
                return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++){
        cin >> v >> e;
        for (int i=1; i<=v; i++) {
            graph[i].clear();
            check[i] = 0;
        }

        for (int j = 0; j < e; j++){
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        bool ok = true;
        for (int i = 1; i <= v; i++){
            if(check[i] == 0)
                ok = dfs(i, 1);
            if(!ok) break;
        }
        
        cout << (ok ? "YES" : "NO") << "\n";
    }
    

    return 0;
}