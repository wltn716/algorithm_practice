// 문제: https://leetcode.com/problems/top-k-frequent-elements/
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

// Runtime: 30 ms, faster than 12.22% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 13.7 MB, less than 41.70% of C++ online submissions for Top K Frequent Elements.

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

class Solution {
public:    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        map<int, int> cnt;
        
        for(int n : nums) {
            cnt[n]++;
        }
        
        vector<pair<int, int>> cnt_vec(cnt.begin(), cnt.end());
        sort(cnt_vec.begin(), cnt_vec.end(), cmp);
        
        for (pair<int, int> cv : cnt_vec) {
            if(ans.size() < k) ans.push_back(cv.first);
            else break;
        }
        
        return ans;
    }
};