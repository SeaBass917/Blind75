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
    int maxProduct(vector<int>& nums) {

        // Trivial case when there are 2 elements.
        const int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        // Unroll the first loop
        auto iter = nums.begin();
        auto val_0 = *iter;
        int true_max = val_0;
        int num_max = (val_0)? val_0 : 1;
        int num_min = (val_0)? val_0 : 1;
        iter++;

        // Loop through the rest and update a running min max
        // Continuously update the true max as we go along.
        for(iter; iter != nums.end(); iter++){
            auto num = *iter;
            if(0 < num){
                num_max = max(num, num_max * num);
                num_min = min(num, num_min * num);
                true_max = max(true_max, num_max);
            }
            else if(num < 0){
                const auto old_max = num_max;
                num_max = max(num, num_min * num);
                num_min = min(num, old_max * num);
                true_max = max(true_max, num_max);
            }
            // Reset min/max on 0
            // (Segmenting the list on this 0)
            else {
                true_max = max(true_max, 0);
                num_max = 1; num_min = 1;    
            }
        }
        
        return true_max;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<int> in = {2,3,-2,4};
        cout << "Expected 6 found: " << solver.maxProduct(in) << endl;
    }
    
    {
        vector<int> in = {-2,0,-1};
        cout << "Expected 0 found: " << solver.maxProduct(in) << endl;
    }
    
    {
        vector<int> in = {0,-2,-1};
        cout << "Expected 2 found: " << solver.maxProduct(in) << endl;
    }
    
    {
        vector<int> in = {3,-1,4};
        cout << "Expected 4 found: " << solver.maxProduct(in) << endl;
    }

    {
        vector<int> in = {-2,3,-4};
        cout << "Expected 24 found: " << solver.maxProduct(in) << endl;
    }

    return 0;
}
