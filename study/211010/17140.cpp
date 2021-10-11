// 문제: https://www.acmicpc.net/problem/17140
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

int r, c, k;
int rn = 3, cn = 3;
vector<vector<int>> a(3, vector<int>(3, 0));
vector<vector<int>> vec;

vector<vector<int>> rotatae_vec() {
    vector<vector<int>> result;

}

bool comp (pair<int,int> p1, pair<int, int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

vector<vector<int>> cal_r() {
    vector<pair<int, int>> vp;
    vector<vector<int>> result;
    int trn = -1;
    for (auto v: vec) {
        sort(v.begin(), v.end());
        int cnt = 1;
        for (int i = 1; i < v.size(); i++) {
            if(i==v.size()-1) {
                vp.push_back({v[i], cnt});
                break;
            }

            if(v[i] != v[i-1]) {
                vp.push_back({v[i], cnt});
                cnt = 1;
            }
            else cnt++;
        }
        sort(vp.begin(), vp.end(), comp);
        vector<int> tmp;
        for(auto p : vp) {
            tmp.push_back(p.first);
            tmp.push_back(p.second);
        }

        int k = tmp.size();
        trn = max(trn, k);
        result.push_back(tmp);
    }

    rn = trn;
    return result;    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> r >> c >> k;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < 100; i++) {
        if(rn >= cn) {
            a = cal_r();
        }
        else {
        }

        if(rn > r-1  && cn > c-1) {
            if(a[r-1][c-1] = k) {
                cout << i << "\n";
                return 0;
            }    
        }
    } 

    cout << -1 << "\n";

    return 0;
} 