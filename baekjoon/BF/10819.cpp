// 문제: https://www.acmicpc.net/problem/10819
#include <iostream>
#include <algorithm>
#include <cstdlib>
#define MAX 8
using namespace std;

int n;
int arr[MAX];

int calculate() {
    int result = 0;
    for (int i = 0; i < n-1; i++) {
        result += abs(arr[i] - arr[i+1]);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    
    int ans = -1;

    do {
        ans = max(ans, calculate());
    } while (next_permutation(arr, arr + n));
    
    cout << ans << "\n";

    return 0;
}