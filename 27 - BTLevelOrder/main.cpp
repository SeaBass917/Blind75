#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> levels;
        
        
        vector<TreeNode *> nodes;
        if(root) nodes.push_back(root);
        
        while(!nodes.empty()){
            
            vector<int> level;
            
            vector<TreeNode *> child_nodes;
            for(const auto node : nodes){
                
                level.push_back(node->val);
                
                const auto left = node->left;
                const auto right = node->right;
                
                if(left) child_nodes.push_back(left);
                if(right) child_nodes.push_back(right);
            }
            
            nodes = child_nodes;
            levels.push_back(level);
        }
        
        return levels;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        auto root0 = TreeNode(3);
        auto node0 = TreeNode(9);
        auto node1 = TreeNode(20);
        auto node2 = TreeNode(15);
        auto node3 = TreeNode(7);
        root0.left = &node0;
        root0.right = &node1;
        node1.left = &node2;
        node1.right = &node3;

        auto soln = solver.levelOrder(&root0);
        cout << "Expected [[3] [9,20] [15,7]] found: [";
        for(const auto row : soln){
            cout << "[";
            int i = 0;
            for(const auto ele : row){
                cout << ele;
                if(i++ < row.size()-1) cout << ",";
            }
            cout << "] ";
        }
        cout << endl;
    }

    return 0;
}
