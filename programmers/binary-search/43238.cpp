// 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges/43238
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    ll st = 1;
    ll ed = (ll) times[times.size()-1] * n;
    
    while(st <= ed) {
        ll mid = (st + ed)/2;
        
        ll cnt = 0;
        for(int t :  times) {
            cnt += mid/t;
        }
        
        if(cnt < n) {
            st = mid + 1;
        } else {
            if(mid <= ed) {
                answer = mid;
            }
            ed = mid - 1;
        }
        
    }
    
    return answer;
}