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
    int characterReplacement(string s, int k) {
        const int n = s.length();

        map<char, int> hist_window;
        int true_max = 1;
        int iL = 0;
        int freq_max = 0;
        for(int iR = 0; iR < n; iR++){
            const char cR = s[iR];
            hist_window[cR]++;
            freq_max = max(freq_max, hist_window[cR]);

            // Move the left pointer forward as much as it takes to make the
            // Window legal again.
            // Which means the length of the chars minus the high freq char
            // must be less than or equal to k
            while((iR - iL + 1 - freq_max) > k){
                hist_window[s[iL++]]--;
            }

            true_max = max(true_max, iR - iL + 1);
        }

        return true_max;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        cout << "Expected 4, computed: " << solver.characterReplacement("ABAB", 2) << endl;
        cout << "Expected 4, computed: " << solver.characterReplacement("AABABBA", 1) << endl;
    }

    return 0;
}
