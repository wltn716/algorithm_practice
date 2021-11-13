// https://leetcode.com/problems/clone-graph/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(3);

    cout << *(vec.end()-1) << "\n";

    // for (int i = 0; i < r; i++) {
    //     for (int j = 0; j < c; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
} 