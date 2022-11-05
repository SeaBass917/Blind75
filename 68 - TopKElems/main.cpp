#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <math.h>       /* log10 */
#include <string> 
using namespace std;

class Solution {
public:
    // 1, 1, 2
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Create a histogram of the data
        // O(n)
        map<int, int> hist;
        for(const auto num : nums) hist[num]++;

        // Invert the histogram, into a map of freq -> nums @ that frequency
        // O(n)
        map<int, unordered_set<int>> hist_inv;
        for(const auto cnt_pair : hist) hist_inv[cnt_pair.second].emplace(cnt_pair.first);

        // Starting at the highest possible freq (nums.length)
        // Search backwards until we have k elements
        // O(n)
        vector<int> out;
        int i = nums.size();
        while(out.size() != k){
            if(hist_inv.find(i) != hist_inv.end()){
                for(const auto num : hist_inv[i]){
                    out.push_back(num);
                    if(out.size() == k) break;
                }
            }
            i--;
        }

        return out;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        vector<int> nums = {1,1,1,2,2,3};
        auto soln = solver.topKFrequent(nums, 2);
        cout << "Expected [1,2], computed: [";
        for(const auto s : soln){
            cout << s << ",";
        }
        cout << ']' << endl;
        soln = solver.topKFrequent(nums, 3);
        cout << "Expected [1,2,3], computed: [";
        for(const auto s : soln){
            cout << s << ",";
        }
        cout << ']' << endl;
        soln = solver.topKFrequent(nums, 1);
        cout << "Expected [1], computed: [";
        for(const auto s : soln){
            cout << s << ",";
        }
        cout << ']' << endl;
    }

    return 0;
}
