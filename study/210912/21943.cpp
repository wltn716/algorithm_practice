// 문제: https://www.acmicpc.net/problem/21943
// 최악의 경우: 17*8!
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n, p, q;
int ans = -1;
vector<int> x;
vector<int> init;
vector<int> divide;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    x.resize(n);

    for (int i = 0; i < n; i++){
        cin >> x[i];
    }

    cin >> p >> q;
    if(q==0) {
        cout << accumulate(x.begin(), x.end(), 0) << "\n";
        return 0;
    }    
    
    sort(x.begin(), x.end());
    
    init.resize(q, 1);
    init.resize(n, 0);

    int nnn = 0;
    do {
        // 부분집합 정보 초기화
        divide = init;
        
        do {    
            nnn++;
            int tmp = 1;
            int sum = 0;
            for (int i = 0; i < n; i++){
                if(divide[i]) {
                    tmp *= sum;
                    sum = x[i];
                }
                else {
                    sum += x[i];
                }
            }

            ans = max(ans, tmp*sum);

        } while(prev_permutation(divide.begin(), divide.end())); // 다른 부분집합 구하기(성공시 true, 실패시 false)

    } while (next_permutation(x.begin(), x.end()));

    cout << nnn << "\n";
    cout << ans << "\n";

    return 0;
}