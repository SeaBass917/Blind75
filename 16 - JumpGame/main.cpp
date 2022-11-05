#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;
class Solution {
public:
    
    bool canJump_helper(vector<int>& nums, const int i, unordered_set<int>& dead_spot) {
        
        // If we meet or exceed the last index,
        // Then we reached, or can reach the last index
        if(nums.size()-1 <= i) return true;
        
        // If we have tried from this spot before, then don't try again
        if(dead_spot.find(i) != dead_spot.end()) return false;
        
        // Explore each possible jump from this location
        // If any return true we will set the flag high
        bool reach_end = false;
        for(int j = nums[i]; 0 < j && !reach_end; j--){
            reach_end |= canJump_helper(nums, i+j, dead_spot);
        }
        
        if(!reach_end) dead_spot.emplace(i);
        
        return reach_end;
    }
    
    bool canJump(vector<int>& nums) {
        
        // Use the recursive helper method
        // Provide a set for tracking indexes that lead to dead ends
        // Initialize to 0
        unordered_set<int> dead_spot = {};
        return canJump_helper(nums, 0, dead_spot);
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    std::vector<int> tk1 = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    auto flag_str = solver.canJump(tk1)? "True" : "False";
    std::cout << flag_str << std::endl;
    
    std::vector<int> tk2 = {1,2,5,1,2,3,9,7,4,7,0,0,1,8,1,9,9,3,5,0,7,5};
    flag_str = solver.canJump(tk2)? "True" : "False";
    std::cout << flag_str << std::endl;
    
    return 0;
}
