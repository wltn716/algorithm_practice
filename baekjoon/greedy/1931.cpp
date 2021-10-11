// 문제: https://www.acmicpc.net/problem/1931
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

bool comp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second != p2.second) 
        return p1.second <= p2.second;
    else 
        return p1.first <= p2.first;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int,int>> schedule;

    for (int i = 0; i < n; i++) {
        int from, to;
        cin >> from >> to;
        schedule.push_back({from, to});
    }
    
    sort(schedule.begin(), schedule.end(), comp);

    int ans = 0;
    int end = 0;
    for(pair<int, int> p : schedule) {
        if(p.first >= end) {
            ans++;
            end = p.second;
        }
    }

    cout << ans << "\n";

    return 0;
} 