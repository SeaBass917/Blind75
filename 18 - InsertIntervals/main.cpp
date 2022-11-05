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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        if(intervals.empty()) return {newInterval};

        int beg = newInterval[0];
        int end = newInterval[1];

        vector<vector<int>> intervals_out;

        for(auto iter = intervals.begin(); iter != intervals.end(); iter++){
            const auto &interval = *iter;
            const int beg_i = interval[0];
            const int end_i = interval[1];

            if(end_i < beg){
                intervals_out.push_back(interval);
            }
            else if(end < beg_i){
                intervals_out.push_back({beg, end});
                intervals_out.insert(intervals_out.end(), iter, intervals.end());
                return intervals_out;
            }
            else{
                beg = min(beg_i, beg);
                end = max(end_i, end);
            }
        }

        intervals_out.push_back({beg, end});

        return intervals_out;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    vector<vector<int>> tk1 = {{1,3},{4,6},{8,10},{15,18}};
    vector<int> tk2 = {2,4};
    vector<vector<int>> soln = solver.insert(tk1, tk2);
    cout << "Expected [ (1,6) (8,10) (15,18) ] => [ ";
    for(const auto interval : soln){
        cout << "(" << interval[0] << ',' << interval[1] << ") ";
    }
    cout << "]" <<  endl;
    
    tk1 = {{1,5}};
    tk2 = {2,3};
    soln = solver.insert(tk1, tk2);
    cout << "Expected [ (1,5) ] => [ ";
    for(const auto interval : soln){
        cout << "(" << interval[0] << ',' << interval[1] << ") ";
    }
    cout << "]" <<  endl;
    
    return 0;
}
