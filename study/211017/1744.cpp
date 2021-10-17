// 문제: https://www.acmicpc.net/problem/1744
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    vector<int> arr(n, 0);
    vector<int> use(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    
    int ans = 0;
    for(int i = n-1; i >= 0; i--) {
        if(arr[i] < 1) break;
        if(use[i] != 1) {
            if(i == 0)
                ans += arr[i];
            else {
                if(arr[i]*arr[i-1] > arr[i] + arr[i-1]) {
                    ans += arr[i]*arr[i-1];
                    use[i] = use[i-1] = 1;
                }
                else {
                    ans += arr[i];
                    use[i] = 1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) break;
        if(use[i] != 1) {
            if(i == n-1)
                ans += arr[i];
            else {
                if(arr[i]*arr[i+1] >= 0) {
                    ans += arr[i]*arr[i+1];
                    use[i] = use[i+1] = 1;
                }
                else {
                    ans += arr[i];
                    use[i] = 1;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
} 