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

// []
// [0]
// [-1 0] | [0 1] | [0 23]
// [-1 0 1] | [0 1] | [0 23]
class MedianFinder {

    using MinHeap = priority_queue <int, vector<int>, greater<int> >;
    using MaxHeap = priority_queue <int, vector<int>, less<int> >;

    MaxHeap small_vals;
    int small_cnt;
    MinHeap large_vals;
    int large_cnt;

public:
    MedianFinder()
     : small_cnt(0)
     , large_cnt(0) {
    }
    
    // [3] [4]
    // [3] [3]
    // [4] [3]
    void addNum(int num) {

        // If the num is larger than the large min it goes in the right sector
        const int large_vals_min = (!large_vals.empty())? large_vals.top() : INT32_MIN;
        if(large_vals_min < num){
            // If we are overfilling the right sector, move it's min over to the left.
            if(small_cnt < large_cnt){
                small_vals.push(large_vals_min);
                large_vals.pop();
                small_cnt++;
                large_cnt--;
            }
            large_vals.push(num);
            large_cnt++;
        }
        // Otherwise the num is in or just past the left sector
        // Add it then determine if we need to move the max over to the right sector.
        else{
            small_vals.push(num);
            small_cnt++;
            if(small_cnt == large_cnt + 2){
                large_vals.push(small_vals.top());
                small_vals.pop();
                large_cnt++;
                small_cnt--;
            }
        }
    }
    
    double findMedian() {
        if(small_cnt > large_cnt) return small_vals.top();
        if(small_cnt < large_cnt) return large_vals.top();
        else                      return (small_vals.top() + large_vals.top()) / 2.0;
    }
};

int main(int argc, char const *argv[]){

    {
        auto med_finder = MedianFinder();
        med_finder.addNum(0);
        cout << "Expected : 0   | Received : " << med_finder.findMedian() << endl;
        med_finder.addNum(0);
        med_finder.addNum(1);
        cout << "Expected : 0   | Received : " << med_finder.findMedian() << endl;
        med_finder.addNum(2);
        med_finder.addNum(4);
        cout << "Expected : 1   | Received : " << med_finder.findMedian() << endl;
        med_finder.addNum(3);
        med_finder.addNum(4);
        med_finder.addNum(4);
        cout << "Expected : 2.5 | Received : " << med_finder.findMedian() << endl;
    }

    return 0;
}
