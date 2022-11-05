#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>       /* log10 */
#include <string> 

using namespace std;
class Solution {
    using Hist = map<char, int>;
public:
    string minWindow(string s, string t) {
        const int m = s.length();

        Hist t_hist;
        int t_cnt = 0;  // Keep count of unique chars for later
        for(const auto c : t){
            if(t_hist.find(c) == t_hist.end()){
                t_hist[c] = 1;
                t_cnt++;
            }
            else{
                t_hist[c]++;
            }
        }

        // Close the window left then right until they break the rules
        int iL_min = 0;
        int iR_min = 0;

        Hist s_hist;
        int s_cnt = 0;
        for(unsigned iR = 0, iL = 0; iR < m; iR++){

            // Update the histogram for this char
            const char c = s[iR];
            s_hist[c]++;

            // Check to see if we have hit the count 
            // needed for any target chars
            if(s_hist[c] == t_hist[c]){
                s_cnt++;
            }

            // We have the full set
            // Mark this down if it is less than current min
            // Then move the left pointer forward until it breaks
            if(s_cnt == t_cnt){
                if(iR_min == 0 || iR-iL < iR_min-iL_min){
                    iL_min = iL;
                    iR_min = iR+1;
                }
                
                // Move the left pointer up until it breaks
                // (Check to see if this point is shorter)
                while(s_cnt == t_cnt){
                    const char cL = s[iL];
                    if(--s_hist[cL] < t_hist[cL]){
                        s_cnt--;
                        if(iR-iL < iR_min-iL_min){
                            iL_min = iL;
                            iR_min = iR+1;
                        }
                    }
                    iL++;
                }
                
                // Continue moving iR forward
            }
        }
        return s.substr(iL_min, iR_min-iL_min);
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    cout << "Expected 'BANC' => " << solver.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << "Expected 'BANC' => " << solver.minWindow("ADOBECODEBANCK", "ABC") << endl;
    cout << "Expected 'cwae' => " << solver.minWindow("cabwefgewcwaefgcf", "cae") << endl;
    cout << "Expected 'a' => " << solver.minWindow("a", "a") << endl;
    cout << "Expected '' => " << solver.minWindow("b", "a") << endl;
    cout << "Expected '' => " << solver.minWindow("a", "b") << endl;
    cout << "Expected '' => " << solver.minWindow("a", "aa") << endl;
    
    return 0;
}
