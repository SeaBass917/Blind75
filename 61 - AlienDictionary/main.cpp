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

// [0, 1, 2, 4]
class Solution {
    using AdjMap = map<char, unordered_set<char>>;

    bool dfs(const char c, AdjMap &adj_map, map<char, bool> &visited, string &result){

        // Check for cycle
        if(visited.find(c) != visited.end()) return visited[c]; 

        visited[c] = true;
        for(const auto d : adj_map[c]){
            if(dfs(d, adj_map, visited, result)) return true;
        }
        visited[c] = false;
        result += c;

        return false;
    }

public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {

        const int n = words.size();
        
        // Create an adjacency map, based on all order
        // information found in the list.
        AdjMap adj_map;
        for(unsigned i = 1; i < n; i++){
            const auto word_0 = words[i-1];
            const auto word_1 = words[i];
            const int min_len = min(word_0.length(), word_1.length());

            // Get diff between the two adjacent words.
            bool no_diff = true;
            for(unsigned j = 0; j < min_len; j++){
                const char c_0 = word_0[j];
                const char c_1 = word_1[j];

                if(c_0 != c_1){
                    adj_map[c_0].emplace(c_1);
                    no_diff = false;
                }
            }
            // Edge case where words are out of order.
            if(no_diff && word_0.length() > word_1.length()) return "";
        }
        
        map<char, bool> visited;
        string result;

        // For each letter of the dictionary
        for(const auto _pair : adj_map){
            if(dfs(_pair.first, adj_map, visited, result)) return "";
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        vector<string> words = {"wrter","wrt"};
        cout << "Expected \"\" found: \"" << solver.alienOrder(words) << '"' << endl;
    }


    {
        vector<string> words = {"wrt","wrf","er","ett","rftt"};
        cout << "Expected \"wertf\" found: \"" << solver.alienOrder(words) << '"' << endl;
    }
    {
        vector<string> words = {"x", "z"};
        cout << "Expected \"xz\" found: \"" << solver.alienOrder(words) << '"' << endl;
    }

    {
        vector<string> words = {"wee", "woe", "wet"};
        cout << "Expected \"\" found: \"" << solver.alienOrder(words) << '"' << endl;
    }

    return 0;
}
