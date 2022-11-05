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
    bool canAttendMeetings(vector<Interval> &intervals) {
        if(intervals.empty()) return true;

        std::sort(
            intervals.begin(), 
            intervals.end(), 
            [](Interval i0,Interval i1){
                return i0.start < i1.start; 
            });

        auto iter = intervals.begin();
        int beg_prev = (*iter).start;
        int end_prev = (*iter).end;
        for(iter++; iter != intervals.end(); iter++){
            const int beg_curr = (*iter).start;
            const int end_curr = (*iter).end;
            if(beg_curr < end_prev) return false;
            beg_prev = beg_curr;
            end_prev = end_curr;
        }
        
        return true;
    }
};

int main(int argc, char const *argv[]){

    auto soln = Solution();

    {
        vector<Interval> intervals = {{0,30},{5,10},{15,20}};
        if(soln.canAttendMeetings(intervals) == false){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }
    
    {
        vector<Interval> intervals = {{0,30},{31,32}};
        if(soln.canAttendMeetings(intervals) == true){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }
    
    {
        vector<Interval> intervals = {{0,30},{30,32}};
        if(soln.canAttendMeetings(intervals) == true){
            cout << "Passed." << endl;
        }
        else{
            cout << "Failed!!!" << endl;
        }
    }
    
    return 0;
}
