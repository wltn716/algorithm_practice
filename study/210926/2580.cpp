// 문제: https://www.acmicpc.net/problem/2580
#include <iostream>
#include <string>
#include <vector>
#define all(v) v.begin(), v.end()

using namespace std;

typedef vector<int> vec;

void chg(int a[]){
    a[2] = 5;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[] = {1, 2, 3};
    chg(a);

    cout << a[2] << "\n";

    return 0;
} 