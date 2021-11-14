// 문제: https://www.acmicpc.net/problem/15686
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

typedef long long ll;

int n, m;
int city[50][13];
int ans = 10000;
vector<pair<int, int>> house;
vector<pair<int, int>> chikens;
vector<bool> live_chiken;

int distance (pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int get_chk_dis(vector<pair<int, int>> live) {
    int sum = 0;
    for(pair<int ,int> h : house) {
        int d = 100;
        for(pair<int, int> l: live) {
            d = min(d, distance(h, l));
        }

        sum += d;
    }

    return sum;
}

void bf(int cnt, vector<pair<int, int>> live) {
    if(cnt == m) {
        ans = min(ans, get_chk_dis(live));
        return;
    }

    for(int i = 0; i < chikens.size(); i++) {
        if(!live_chiken[i]) {
            live_chiken[i] = true;
            live.push_back(chikens[i]);
            
            // 재귀 호출
            bf(cnt + 1, live);

            live_chiken[i] = false;
            live.pop_back();
        }
    }
}


int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> city[i][j];
            if(city[i][j] == 1) house.push_back({i, j});
            if(city[i][j] == 2) {
                chikens.push_back({i, j});
            }
        }
    }

    live_chiken.assign(chikens.size(), false);

    bf(0, vector<pair<int, int>>());

    cout << ans << "\n";

    return 0;
} 