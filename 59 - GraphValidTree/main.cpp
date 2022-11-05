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
    using AdjMap = map<int, unordered_set<int>>;
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     * 
     * [0, (1, 2, 3)], 
     * [1, (4)]
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        if(n <= 1) return false;

        // Create an adjacency map.
        // Store edges in both directions
        AdjMap adj_map;
        for(const auto edge : edges) {
            adj_map[edge[0]].emplace(edge[1]);
            adj_map[edge[1]].emplace(edge[0]);
        }

        // Initialize list of visited nodes.
        unsigned visited_cnt = 0;
        vector<bool> visited(n, false);

        // BFS using a stack. 
        // Look for cycles with the visited map, 
        // and count the visited nodes.
        stack<pair<int, int>> search_stack;
        search_stack.push({0, -1});
        while(!search_stack.empty()){
            const auto _pair = search_stack.top(); search_stack.pop();
            const auto node = _pair.first;
            const auto prev = _pair.second;
            
            // Mark the node as visited, and increment the count
            visited[node] = true; 
            visited_cnt++;
            
            for(const auto child : adj_map[node]){
                if(child == prev) continue;
                if(visited[child]) return false;
                search_stack.push({child, node});
            }
        }

        return visited_cnt == n;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
        auto result_str = solver.validTree(3, edges)? "True" : "False";
        cout << "Expected FALSE found: " << result_str << endl;
    }

    {
        vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
        auto result_str = solver.validTree(5, edges)? "True" : "False";
        cout << "Expected FALSE found: " << result_str << endl;
    }

    {
        vector<vector<int>> edges = {{0,1}};
        auto result_str = solver.validTree(2, edges)? "True" : "False";
        cout << "Expected TRUE found: " << result_str << endl;
    }

    {
        vector<vector<int>> edges = {{0,1},{2,1},{2,0}};
        auto result_str = solver.validTree(3, edges)? "True" : "False";
        cout << "Expected FALSE found: " << result_str << endl;
    }

    {
        vector<vector<int>> edges = {{1,3},{4,3},{4,5},{3,0},{3,2}};
        auto result_str = solver.validTree(6, edges)? "True" : "False";
        cout << "Expected TRUE found: " << result_str << endl;
    }

    return 0;
}
