// 문제: https://www.acmicpc.net/problem/11721
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    char c;

    while((c=getchar())!=EOF) {
        i++;
        putchar(c);
        if(i%10 == 0) cout << '\n';
    }
    return 0;
}