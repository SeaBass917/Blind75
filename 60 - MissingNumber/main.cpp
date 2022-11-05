#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <math.h>       /* log10 */
#include <string> 
using namespace std;

// [0, 1, 2, 4]
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int n = nums.size();
        const int oob = -1 * n - 1;
        
        bool zero = false;
        for(auto num : nums){
            const int num_abs = abs(num);
            if(num_abs == 0 || num == oob) zero = true;
            else{
                if(nums[num_abs-1]) nums[num_abs-1] *= -1;
                else nums[num_abs-1] = oob;
            }
        }

        if(!zero) return 0;

        int i = 1;
        for(auto num : nums){
            if(0 <= num) return i;
            i++;
        }

        return n;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    // {
    //     vector<int> nums = {3,0,1};
    //     cout << "Expected 2 found: " << solver.missingNumber(nums) << endl;
    // }

    {
        vector<int> nums = {2,0,5,1,3};
        cout << "Expected 4 found: " << solver.missingNumber(nums) << endl;
    }

    {
        vector<int> nums = {5,1,4,2,3};
        cout << "Expected 0 found: " << solver.missingNumber(nums) << endl;
    }

    {
        vector<int> nums = {3,4,0,1,2};
        cout << "Expected 5 found: " << solver.missingNumber(nums) << endl;
    }

    return 0;
}
