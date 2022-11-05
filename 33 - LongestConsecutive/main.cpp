#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>       /* log10 */
#include <string> 
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> nums_set(nums.begin(), nums.end());
        
        int seq_cnt_max = 0;
        for(auto num : nums){
            const int num_prev = num - 1;
            // If it is the start of a seq
            if(nums_set.find(num_prev) == nums_set.end()){
                int seq_cnt = 1;
                while(nums_set.find(++num) != nums_set.end()) seq_cnt++;
                seq_cnt_max = max(seq_cnt_max, seq_cnt);
            }
        }
        
        return seq_cnt_max;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<int> in = {};
        cout << "Expected 0 found: " << solver.longestConsecutive(in) << endl;
    }
    
    {
        vector<int> in = {1};
        cout << "Expected 1 found: " << solver.longestConsecutive(in) << endl;
    }
    
    {
        vector<int> in = {100,4,200,1,3,2};
        cout << "Expected 4 found: " << solver.longestConsecutive(in) << endl;
    }
    
    {
        vector<int> in = {0,3,7,2,5,8,4,6,0,1};
        cout << "Expected 9 found: " << solver.longestConsecutive(in) << endl;
    }
    
    return 0;
}
