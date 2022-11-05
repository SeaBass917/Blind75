#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Interval {
    int start;
    int end;
};

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        if(intervals.empty()) return true;
        const int n = intervals.size();

        // Create an array of start and end times, sort them
        vector<int> start_times(n);
        vector<int> end_times(n);
        unsigned i = 0;
        for(const auto interval : intervals){
            start_times[i] = interval.start;
            end_times[i] = interval.end;
            i++;
        }
        std::sort(start_times.begin(), start_times.end());
        std::sort(end_times.begin(), end_times.end());

        unsigned rooms_in_use_max = 0;
        unsigned rooms_in_use = 0;
        unsigned i_start = 0;
        unsigned i_end = 0;
        while(i_start < n){
            const int start = start_times[i_start];
            const int end = end_times[i_end];

            if(start < end){
                rooms_in_use++;
                i_start++;
            }
            else{
                rooms_in_use--;
                i_end++;
            }

            if(rooms_in_use_max < rooms_in_use) rooms_in_use_max = rooms_in_use;
        }

        return rooms_in_use_max;
    }
};

int main(int argc, char const *argv[]){

    auto soln = Solution();

    {
        vector<Interval> intervals = {{0,30},{5,10},{15,20}};
        if(soln.minMeetingRooms(intervals) == 2){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }
    
    {
        vector<Interval> intervals = {{0,30},{31,32}};
        if(soln.minMeetingRooms(intervals) == 1){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }
    
    {
        vector<Interval> intervals = {{0,30},{30,32}};
        if(soln.minMeetingRooms(intervals) == 1){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }
    
    return 0;
}
