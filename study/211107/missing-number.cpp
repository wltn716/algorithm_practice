// 문제: https://leetcode.com/problems/missing-number/
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int from = 0;
        int to = nums.size();
        int ans = to;
        for(int i = from; i < to; i++) {
            if(nums[i-from] != i) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};