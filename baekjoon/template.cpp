// 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
// 문제: https://www.acmicpc.net/problem/12100
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<int> a(3,0);
    vector<int> b = a;
    b[0] = 1;

    cout << a[0] << " " << b[0] << "\n";

    return 0;
} 