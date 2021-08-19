// 문제: https://www.acmicpc.net/problem/11652
#include <iostream>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;

ll cards[MAX];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%lld", cards+i);
    }

    sort(cards, cards+n);

    int m = 0, tmp = 1;
    ll ans;
    for (int i = 1; i < n; i++){
        if(cards[i] != cards[i-1]){
            if(m < tmp) {
                ans = cards[i-1];
                m = tmp;
            }
            tmp = 1;
        }
        else tmp++;
    }

    if(m < tmp) ans = cards[n-1];
    
    printf("%lld\n", ans);
    return 0;
}