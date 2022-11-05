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

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        
        // Sort in ascending order by start of each interval
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2){
            return v1[0] < v2[0];
        });

        int cnt_rem_min = 0;
        auto iter = intervals.begin();
        auto end_prev = (*iter)[1];
        for(iter++; iter != intervals.end(); iter++){
            auto interval = *iter;
            const int end = interval[1];

            // If the interval bleeds into the previous interval 
            // we need to remove something
            if(interval[0] < end_prev){
                cnt_rem_min++;
                // Remove whichever interval ends later
                // Which happens to mean:
                // - Move the prev pointer up if the new interval is shorter
                // - Otherwise keep prev pointer at same spot
                if(end < end_prev){
                    end_prev = end;
                }
            }
            else{
                end_prev = end;
            }
        }

        return cnt_rem_min;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
        cout << "Expected 1, computed: " << solver.eraseOverlapIntervals(intervals) << endl;
    }

    {
        vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
        cout << "Expected 2, computed: " << solver.eraseOverlapIntervals(intervals) << endl;
    }

    {
        vector<vector<int>> intervals = {{1,2},{2,3}};
        cout << "Expected 0, computed: " << solver.eraseOverlapIntervals(intervals) << endl;
    }

    return 0;
}
