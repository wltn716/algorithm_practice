// 문제: https://www.acmicpc.net/problem/9466
#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 100001
using namespace std;

int t, n;
int s[MAX];
int visit[MAX];
queue<int> q;


int dfs(int x) {
    visit[x] = 1;
    q.push(x);

    if(!visit[s[x]]) {
        return dfs(s[x]);
    }
    
    // 사이클 끝에 도달
    while(!q.empty()) {
        int k = q.front();
        
        // 사이클 생성 확인 시(시작점 = 끝이 가리키는 점) 큐 사이즈 리턴
        if(k == s[x]) return q.size();
        
        // 사이클에 포함되지 않는 원소 제거
        q.pop();
    }
    
    // 사이클 생성에 실패했으므로 0 리턴
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n;
        
        // 배열 초기화
        fill_n(s, MAX, 0);
        fill_n(visit, MAX, 0);

        for (int i = 1; i <= n; i++){
            cin >> s[i];
        }

        int ans = n;
        for (int i = 1; i <= n ; i++){
            if(visit[i] == 0){
                // 전체 학생 수에서 사이클을 이룬 학생만큼 빼줌
                ans -= dfs(i);
                
                // 사이클 저장 큐 초기화
                queue<int> empty;
                swap(q, empty);
            }

        }

        cout << ans << "\n";
    }

    return 0;
}