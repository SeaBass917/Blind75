#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
using namespace std;

class Solution {
public:
    
    std::pair<int,int> get_pal(int i_start, int i_end, string s){
        
        while(0 <= i_start && i_end < s.length()){
            
            if(s[i_start] == s[i_end]){
                i_start--;
                i_end++;
            }
            else{
                break;
            }
        }
        
        i_start++;
        i_end--;
        
        return {i_start, i_end};
    }
    
    string longestPalindrome(string s) {
        
        int i_start_max = 0;
        int i_end_max = 0;
        for(int i = 0; i < s.length(); i++){
            
            auto [i_start, i_end] = get_pal(i-1, i+1, s);
            if(i_end_max-i_start_max < i_end-i_start){
                i_start_max = i_start;
                i_end_max = i_end;
            }
            
            auto [i_start_e, i_end_e] = get_pal(i, i+1, s);
            if(i_start_e < i_end_e && i_end_max-i_start_max < i_end_e-i_start_e){
                i_start_max = i_start_e;
                i_end_max = i_end_e;
            }
        }
        
        return s.substr(i_start_max, i_end_max-i_start_max+1);
    }
};

int main(int argc, char const *argv[]){
    
    auto solver = Solution();

    std::cout << solver.longestPalindrome("cdbabd") << INT_MIN << std::endl;

    return 0;
}
