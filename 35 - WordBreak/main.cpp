#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_set<int> failed_paths;
    int n;
    
    bool startsWith(const string &s, const string &w, int i){
        for(const auto w_c : w){
            if(n <= i || s[i] != w_c) return false;
            i++;
        }
        return true;
    }

    bool wordBreak_helper(string s, vector<string>& wordDict, const int i = 0) {
        
        // Dead ends. Either good or bad ones.
        if(i == n) return true;
        if(failed_paths.find(i) != failed_paths.end()) return false;
        
        // Loop through each word in the dicitonary and see if any are at the start
        // The recurse for the rest of the string. Returning true if any paths return true.
        for(const auto &word : wordDict){
            bool it_here = startsWith(s, word, i);
            bool it_work = it_here && wordBreak_helper(s, wordDict, i + word.length());
            if( it_here && it_work ) return true;
        }
        
        // If we reach here, no paths are an option.
        // Jot it down for future reference and return false.
        failed_paths.emplace(i);
        return false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        failed_paths.clear();
        return wordBreak_helper(s, wordDict);
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<string> in = {"leet", "code"};
        auto soln_str = (solver.wordBreak("leetcode", in))? "True" : "False";
        cout << "Expected TRUE found: " << soln_str << endl;
    }

    {
        vector<string> in = {"apple","pen"};
        auto soln_str = (solver.wordBreak("applepenapple", in))? "True" : "False";
        cout << "Expected TRUE found: " << soln_str << endl;
    }

    {
        vector<string> in = {"cats","dog","sand","and","cat"};
        auto soln_str = (solver.wordBreak("catsandog", in))? "True" : "False";
        cout << "Expected FALSE found: " << soln_str << endl;
    }

    {
        vector<string> in = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        auto soln_str = (solver.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", in))? "True" : "False";
        cout << "Expected FALSE found: " << soln_str << endl;
    }

    return 0;
}
