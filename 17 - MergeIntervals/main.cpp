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
    // n(n-1)/2 If we loop until convergence
    // Try sorting + linear scan

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Edge case where we weren't asked to do anything
        if(intervals.size() <= 1) return intervals;
        
        // Sort intervals by starts
        std::sort(intervals.begin(), intervals.end());

        // Now sorted, loop through each element and merge until all are merged
        vector<vector<int>> intervals_out = { intervals[0] };
        int i_end = 0;
        for(unsigned i = 1; i < intervals.size(); i++){

            auto &interval_curr = intervals_out[i_end];
            auto &interval_next = intervals[i];

            const int end_curr = interval_curr[1];
            const int beg_next = interval_next[0];
            const int end_next = interval_next[1];

            // Merge condition
            if(beg_next <= end_curr) {
                interval_curr[1] = max(end_curr,end_next);
            }
            else{
                intervals_out.push_back(interval_next);
                i_end++;
            }
        }

        return intervals_out;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    vector<vector<int>> tk = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> soln = solver.merge(tk);
    cout << "Expected [ (1,6) (8,10) (15,18) ] => [ ";
    for(const auto interval : soln){
        cout << "(" << interval[0] << ',' << interval[1] << ") ";
    }
    cout << "]" <<  endl;
    
    tk = {{1,4},{4,5}};
    soln = solver.merge(tk);
    cout << "Expected [ (1,5) ] => [ ";
    for(const auto interval : soln){
        cout << "(" << interval[0] << ',' << interval[1] << ") ";
    }
    cout << "]" <<  endl;
    
    tk = {{1,4},{2,3}};
    soln = solver.merge(tk);
    cout << "Expected [ (1,4) ] => [ ";
    for(const auto interval : soln){
        cout << "(" << interval[0] << ',' << interval[1] << ") ";
    }
    cout << "]" <<  endl;
    
    
    return 0;
}
