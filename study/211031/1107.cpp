// 문제: https://www.acmicpc.net/problem/1107
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

string N;
int n, m, sizeN, ans;
int chn = 100;
vector<int> broken(10, 0);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N >> m;
    n = stoi(N);
    sizeN = N.size();

    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        broken[num] = 1;
    }

    ans = abs(n - chn); 
    if(ans <= sizeN) {
        cout << ans << "\n";
        return 0;
    }

    for(int i = 0; i <= 999999; i++) {
        int cnt = 0;
        bool flag = false;
        int tmp = i;
        do {
            cnt++;
            int k = tmp%10;
            if(broken[k]) {
                flag = true;
                break;
            }

            tmp /= 10;
        } while(tmp != 0);

        if(flag) continue;

        ans = min(abs(n - i) + cnt, ans);
    }

    cout << ans << "\n";

    return 0;
} 