#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <utility>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <numeric>
using namespace std;

class Solution {
    
    using AdjMap = vector<unordered_set<int>>;
    
    AdjMap prereq_map;
    vector<bool> known_good;
    vector<bool> visited;

    // Helper for searching to the end of a adj map
    bool dfs(const AdjMap &prereq_map, const int i){
        if(visited[i]) return false;
        if(known_good[i]) return true;
        
        visited[i] = true;

        for(const auto & prereq : prereq_map[i]){
            if( !dfs(prereq_map, prereq) ) return false;
            visited[i] = false;
        }
        
        visited[i] = false;
        known_good[i] = true;
        return true;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Initialize datastructures
        visited = vector<bool>(numCourses, false);
        known_good = vector<bool>(numCourses, false);
        prereq_map = AdjMap(numCourses);
        
        // Populate the map with pre-requisites
        for(const auto &prerequisite : prerequisites){
            const int post = prerequisite[0];
            const int pre = prerequisite[1];
            prereq_map[post].emplace(pre);
        }
        
        // Search through each course to find an end
        for(unsigned i = 0; i < numCourses; i++){
            if( !dfs(prereq_map, i) ) return false;
        }
        
        return true;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        vector<vector<int>> prereqs = {{0,1}};
        if(solver.canFinish(2, prereqs) == true){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
    }

    {
        vector<vector<int>> prereqs = {{0,1},{1,0}};
        if(solver.canFinish(2, prereqs) == false){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
    }

    {
        vector<vector<int>> prereqs = {{0,1},{0,2}};
        if(solver.canFinish(3, prereqs) == true){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
    }

    {
        vector<vector<int>> prereqs = {{1,0},{2,0},{3,1},{3,2}};
        if(solver.canFinish(4, prereqs) == true){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
    }

    {
        vector<vector<int>> prereqs = {{0,1},{0,2},{1,2}};
        if(solver.canFinish(3, prereqs) == true){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
    }

    return 0;
}
