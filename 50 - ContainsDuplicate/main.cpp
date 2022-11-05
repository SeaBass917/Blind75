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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        return nums_set.size() != nums.size();
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
        auto soln_str = solver.containsDuplicate(nums)? "True" : "False";
        cout << "Expected True, computed: " << soln_str << endl;
    }

    return 0;
}
