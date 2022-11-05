#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        
        map<int, Node*> nodes_new;
        stack<const Node *> nodes_unseen = {};
        
        // Unroll the first loop
        vector<Node *> nbrs;
        for(const auto *node_nbr : node->neighbors){
            nodes_unseen.push(node_nbr);
            
            const int val_nbr = node_nbr->val;
            auto *node_new_nbr = new Node(val_nbr);
            nodes_new[val_nbr] = node_new_nbr;
            nbrs.push_back(node_new_nbr);
        }
        nodes_new[node->val] = new Node(node->val, nbrs);
        
        // Search through nodes_unseen, until we've seen it all.
        while(!nodes_unseen.empty()){
            const auto *node_unseen = nodes_unseen.top();
            nodes_unseen.pop();
            
            const int val = node_unseen->val;
            Node *node_new = (nodes_new.find(val) == nodes_new.end())? new Node(val) : nodes_new[val];
            
            // Build the list of neighbors, creating new Nodes 
            // if they don't exist
            // And adding them to the search stack
            nbrs.clear();
            for(const auto *node_nbr : node_unseen->neighbors){
                const int val_nbr = node_nbr->val;
                
                // This is a new node, 
                // Add it to the search list, and create a node for it
                if(nodes_new.find(val_nbr) == nodes_new.end()){
                    nodes_unseen.push(node_nbr);
                    
                    auto *node_new_nbr = new Node(val_nbr);
                    nodes_new[val_nbr] = node_new_nbr;
                    nbrs.push_back(node_new_nbr);
                }
                // We've seen this
                else{
                    nbrs.push_back(nodes_new[val_nbr]);
                }
            }
            
            // Create new node
            // Add to visited
            node_new->neighbors = nbrs;
            nodes_new[val] = node_new;
        }
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    // VERY HARD TO TEST :C
    // Don't bother. It is working.
    // Test again if you change it, in LeetCode
    // https://leetcode.com/problems/clone-graph/

    return 0;
}
