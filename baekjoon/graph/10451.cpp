// 문제: https://www.acmicpc.net/problem/10451 
// 한번에 하나의 방향으로만 간선 연결이 가능하므로, 마지막으로 탐색되는 노드가 방문한 적이 있다면 탐색 시작점인 경우만 가능한 것.
#include <iostream>
#define MAX 1001
using namespace std;

int arr[MAX];
int visit[MAX];
int t, n;

void dfs(int x) {
    visit[x] = 1;
    if(!visit[arr[x]])
        dfs(arr[x]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n;
        fill_n(arr+1, n+1, 0);
        fill_n(visit+1, n+1, 0);

        for (int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        
        int ans = 0;
        for (int i = 1; i <= n; i++){
            if(!visit[i]) {
                ans++;
                dfs(i);
            }
        }

        cout << ans << "\n";
    }


    return 0;
}