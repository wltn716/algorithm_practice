// 문제: https://www.acmicpc.net/problem/14621
// 최소 스패닝 트리 - 크루스칼/프림
// https://www.crocus.co.kr/733 참고
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define pb push_back
#define all(v) v.begin(), v.end()

using namespace std;

typedef struct edge {
    int from;
    int to;
    int val;
} E;

vector<char> school;
vector<int> parent;
bool chk;

int find(int v) {
    if(parent[v] == v) 
        return v;

    return parent[v] = find(parent[v]);
}

bool merge(int u, int v) {
    if(school[u] == school[v]) return false;

    u = find(u);
    v = find(v);

    if(u == v) return false;

    parent[u] = v;
    return true;
}

bool comp(E e1, E e2) {
    return e1.val < e2.val;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    school.resize(n);
    parent.resize(n);
    vector<E> edges(m);

    for (int i = 0; i < n; i++){
        cin >> school[i];
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].val;
    }
    
    sort(all(edges), comp);

    int ans = 0;
    int cnt = 1;
    for(E e: edges) {
        if(merge(e.from-1, e.to-1)) {
            ans += e.val;
            cnt++;
        }    
    }

    cout <<  (cnt == n ? ans : -1) << "\n";

    return 0;
} 