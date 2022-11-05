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

class Solution {
    using AdjMap = map<int, unordered_set<int>>;

    void dfs(const AdjMap &adj_map, vector<bool> &visited, const int k){
        visited[k] = true;
        for (const auto kk : adj_map.at(k)){
            if(!visited[kk]) dfs(adj_map, visited, kk);
        }
    }

public:
    int countComponents(int n, vector<vector<int>> edges) {

        AdjMap adj_map;

        for(const auto edge : edges){
            if(edge.size() != 2) continue;
            const auto n1 = edge[0];
            const auto n2 = edge[1];
            adj_map[n1].emplace(n2);
            adj_map[n2].emplace(n1);
        }

        int num_conn_comps = 0;
        vector<bool> visited(n, false);
        for(unsigned k = 0; k < n; k++){
            if(!visited[k]){
                num_conn_comps++;
                dfs(adj_map, visited, k);
            }
        }

        return num_conn_comps;
    }
};

int main(int argc, char const *argv[]){

    auto soln = Solution();

    {
        vector<vector<int>> edges = {{1,0}, {1,2}, {3,2}, {3,1}};
        cout << "Expected : 1  | Received : " << soln.countComponents(4, edges) << endl;
    }


    {
        vector<vector<int>> edges = {{1,2}, {1,0}, {3,4}};
        cout << "Expected : 2  | Received : " << soln.countComponents(5, edges) << endl;
    }

    return 0;
}
