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
    int n;
    int _rob(vector<int>& nums, const int i_beg, const int i_end) {
        
        // Store the max 1 house behind, 
        // and 2 houses behind, respectively 
        int max_1 = 0;
        int max_2 = 0;
        
        // Run through the array, 
        // Counting the maximum we can rob
        for(unsigned i = i_beg; i < i_end; i++){
            const int max_val = max(max_1, max_2 + nums[i]);
            max_2 = max_1;
            max_1 = max_val;
        }
        
        return max(max_1, max_2);
    }
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max( _rob(nums, 0, n-1), _rob(nums, 1, n) );
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<int> in = {2,3,2};
        cout << "Expected 3 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {1,2,3,1};
        cout << "Expected 4 found: " << solver.rob(in) << endl;
    }
    
    {
        vector<int> in = {};
        cout << "Expected 0 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {13};
        cout << "Expected 13 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {12,98};
        cout << "Expected 98 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {2,0,2};
        cout << "Expected 2 found: " << solver.rob(in) << endl;
    }

    {
        vector<int> in = {1,2,3};
        cout << "Expected 3 found: " << solver.rob(in) << endl;
    }

    return 0;
}
