// 문제: https://www.acmicpc.net/problem/1924
#include <iostream>
using namespace std;

int main() {
    int d[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string w[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int x, y, k = 0;
    cin >> x >> y;
    for(int i=0;i<x-1;i++){
        k += d[i];
    }
    k = (k+y)%7;

    cout << w[k] << '\n';

    return 0;
}