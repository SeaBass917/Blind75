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
    int dfs(const TreeNode *const node, const int level=0){
        if(!node) return level;
        return max(dfs(node->left), dfs(node->right, level))+1;
    }
public:
    int maxDepth(TreeNode* root) {
        return dfs(root);
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

        auto soln = solver.maxDepth(&root0);
        cout << "Expected 3 found: " << soln << endl;
    }

    {
        auto root0 = TreeNode(1);
        auto node0 = TreeNode(2);
        root0.right = &node0;

        auto soln = solver.maxDepth(&root0);
        cout << "Expected 2 found: " << soln << endl;
    }

    return 0;
}
