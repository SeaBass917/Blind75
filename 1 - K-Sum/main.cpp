#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Solution2SUM {
public:
    // [1, 2, (3), 5, (8), 19, 21]
    vector<int> twoSum(vector<int>& nums, int target) {
        //indices
        
        map<int, int> complement_index_map;
        
        int i = 0;
        for(auto num : nums){
            const int compliment = target - num;
            
            // Search in map for compliment,
            if(complement_index_map.find(num) != complement_index_map.end()){
                const int i_comp = complement_index_map[num];
                return {i_comp, i};
            }
            // else, add to the map and continue
            else{
                complement_index_map[compliment] = i;
            }
            
            i++;
        }
        
        return {};
    }
};

class SolutionKSUM {
public:

    vector<vector<int>> kSum(vector<int>& nums, int target, int k, unsigned i_start=0) {
        vector<vector<int>> k_sets;
        
        // For non-trivial case, recurse down for the array to our right
        // Do this for all values in the array
        // [X, (Y, Z, ...)]
        // [Y, (Z, ...)]
        // [Z, (...)]
        // Returning any sets that meet the (target - curr_value)
        if (2 < k){
            for (unsigned i = i_start; i < nums.size()-k+1; i++){
                int num_curr = nums[i];

                // (Skip duplicates)
                if(i_start < i && num_curr == nums[i-1]) continue;

                // Recurs to our right
                auto k_sets_tmp = kSum(nums, target - num_curr, k-1, i+1);
                
                // Caller wants this set with our current value appended to each element
                for(auto k_set_tmp : k_sets_tmp){
                    vector<int> k_set = {num_curr};
                    k_set.insert(k_set.end(), k_set_tmp.begin(), k_set_tmp.end());
                    k_sets.push_back(k_set);
                }
            }
        }
        // Base case k == 2
        // Scan through the array with a left and right pointer
        // Check the sum.
        // Because we're sorted we can move pLeft forward if we undershoot,
        // And pRight back if we overshoot
        // Return all pairs that meet the target
        else{
            int pLeft = i_start;
            int pRight = nums.size()-1;
            int numLeft;
            int numRight;
            while(pLeft < pRight){
                numLeft = nums[pLeft];
                numRight = nums[pRight];
                
                // If we hit target, save the values
                int sum = numLeft + numRight;
                if(target == sum){
                    k_sets.push_back({numLeft,numRight});
                }
                
                // Move pointers (Skip duplicates)
                if(sum <= target){
                    while(pLeft < nums.size() && nums[pLeft] == numLeft) pLeft++;
                }
                else{
                    while(0 <= pRight && nums[pRight] == numRight) pRight--;
                }
            }
        }
        
        return k_sets;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        // Sort before calling
        std::sort(nums.begin(), nums.end());

        return kSum(nums, target, 4);
    }
};

int main(int argc, char const *argv[]){

    auto solverK = SolutionKSUM();

    std::vector<int> tk1 = {1,0,-1,0,-2,2};
    for (auto set : solverK.fourSum(tk1, 0)){
        std::cout << "[";
        for(auto ele : set){
            std::cout << ele << ",";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;
    
    std::vector<int> tk2 = {2,2,2,2,2};
    for (auto set : solverK.fourSum(tk2, 8)){
        std::cout << "[";
        for(auto ele : set){
            std::cout << ele << ",";
        }
        std::cout << "] ";
    }
    std::cout << std::endl;

    return 0;
}
