// 문제: https://www.acmicpc.net/problem/10610
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string num;
    cin >> num;
    sort(num.begin(), num.end(), greater<char>());

    if(num.back() != '0') {
        cout << -1 <<"\n";
    }
    else {
        ll sum = 0LL;

        for(char c : num) {
            sum += c - '0';
        }

        if(sum%3 == 0) cout << num << "\n";
        else cout << -1 << "\n";

    }

    return 0;
}