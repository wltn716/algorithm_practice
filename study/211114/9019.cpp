// 문제: https://www.acmicpc.net/problem/9019
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

vector<int> visit(10001);
vector<string> ins(10001);

void bfs(int a, int b) {
    fill(all(ins), "");
    fill(all(visit), 0);

    queue<int> q;
    q.push(a);
    visit[a] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        int tmp = (x*2)%10000;
        if(!visit[tmp]) {
            visit[tmp] = 1;
            ins[tmp] = ins[x] + "D";
            q.push(tmp);
        }

        tmp = x == 0 ? 9999 : x-1;
        if(!visit[tmp]) {
            visit[tmp] = 1;
            ins[tmp] = ins[x] + "S";
            q.push(tmp);
        }

        tmp = (x%1000)*10 + x/1000;
        if(!visit[tmp]) {
            visit[tmp] = 1;
            ins[tmp] = ins[x] + "L";
            q.push(tmp);
        }

        tmp = x%10*1000 + x/10;
        if(!visit[tmp]) {
            visit[tmp] = 1;
            ins[tmp] = ins[x] + "R";
            q.push(tmp);
        }

        if(visit[b]) break;
    }

    cout << ins[b] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--) {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }
    

    return 0;
} 