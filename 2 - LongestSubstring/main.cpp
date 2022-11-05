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
    int lengthOfLongestSubstring(string s) {            
        
        // Return var
        if(s.length() < 2) return s.length();
        
        
        std::map<char,int> prev_chars = {};
        unsigned i_start = 0;
        unsigned i_end = 1;
        
        prev_chars[s[0]] = 0;
        int max_len = 1;
        while(i_end < s.length()){
            const char c_end = s[i_end];
            
            if(prev_chars.find(c_end) == prev_chars.end()){
                prev_chars[c_end] = i_end;
                i_end++;
                const int curr_len = i_end - i_start;
                if(max_len < curr_len) max_len=curr_len;
            }
            else{
                const int i_dup = prev_chars[c_end];
                
                while(i_start <= i_dup){
                    prev_chars.erase(s[i_start]);
                    i_start++;
                }
                
                prev_chars[c_end] = i_end;
                i_end++;
            }
            
        }
        
        return max_len;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    std::cout << "Soln == 0" << std::endl;
    std::cout << solver.lengthOfLongestSubstring("") << std::endl;
    std::cout << std::endl;

    std::cout << "Soln == 1" << std::endl;
    std::cout << solver.lengthOfLongestSubstring("c") << std::endl;
    std::cout << solver.lengthOfLongestSubstring("aaa") << std::endl;
    std::cout << solver.lengthOfLongestSubstring("bbbbbb") << std::endl;
    std::cout << solver.lengthOfLongestSubstring("yyyyyyy") << std::endl;
    std::cout << std::endl;

    std::cout << "Soln == 2" << std::endl;
    std::cout << solver.lengthOfLongestSubstring("abbabababababbba") << std::endl;
    std::cout << solver.lengthOfLongestSubstring("aaaabbbb") << std::endl;
    std::cout << solver.lengthOfLongestSubstring("ya") << std::endl;
    std::cout << std::endl;

    std::cout << "Soln == 3" << std::endl;
    std::cout << solver.lengthOfLongestSubstring("yap") << std::endl;
    std::cout << solver.lengthOfLongestSubstring("abccccababbabacbb") << std::endl;
    std::cout << solver.lengthOfLongestSubstring("aaaabbbbca") << std::endl;
    std::cout << std::endl;

    return 0;
}
