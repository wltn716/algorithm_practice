// 문제: https://www.acmicpc.net/problem/10814
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first;
}

int main() {
    int n;
    vector<pair<int,string> > v;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int a;
        string b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    stable_sort(v.begin(), v.end(), compare);
    
    for(pair<int, string> p : v) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}

