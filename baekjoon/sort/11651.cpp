// 문제: https://www.acmicpc.net/problem/11651
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

int main() {
    int n;
    vector<pair<int, int>> v;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), compare);
    
    for(pair<int, int> p : v) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}

