#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int solution(int distance, vector<int> rocks, int n) {
    ll answer = 0;
    
    sort(rocks.begin(), rocks.end());
    ll st = 0;
    ll ed = distance;
    
    while(st <= ed) {
        ll cnt = 0;
        ll mid = (st + ed)/2;
        ll prev = 0;
        
        int rs = rocks.size();
        for(int i = 0; i < rs; i++) {
            if(rocks[i] - prev < mid) cnt++;
            else prev = rocks[i];
        }
        
        if(distance - prev < mid) cnt++;
        
        if(cnt <= n) {
            answer = max(answer, mid);
            st = mid+1;
        } else {
            ed = mid-1;
        }
        
            
    }
    
    return answer;
}