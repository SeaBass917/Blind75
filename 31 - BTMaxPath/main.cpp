#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <string>
#include <stack>
#include <algorithm>
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
    int dfs(const TreeNode *const root, int &result){
        if(!root) return 0;
        const auto left = root->left;
        const auto right = root->right;
        const int val = root->val;
        
        // Check 2 things, 
        // 1) Condition if we can split
        const int val_left = dfs(left, result);
        const int val_right = dfs(right, result);

        int val_split = val;
        if(0 < val_left) val_split += val_left;
        if(0 < val_right) val_split += val_right;
        result = max(result, val_split);
        
        // 2) Condition if we CANNOT split
        // NOTE: If both are bad values, the best path stops at this node.
        int ret_val = val;
        if(0 < val_left || 0 < val_right){
            ret_val += max(val_left, val_right);
        }

        return ret_val;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        // Initialize result, run dfs to find max, and return it.
        if(!root) return 0;
        int result = root->val;
        dfs(root, result);
        return result;
    }
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p || !q) return !p && !q;
    return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        auto root0 = TreeNode(2);
        auto node0 = TreeNode(-1);
        root0.left = &node0;
        
        auto soln = solver.maxPathSum(&root0);
        cout << "Expected 2, computed: " << soln << endl;
    }

    {
        auto root0 = TreeNode(1);
        auto node0 = TreeNode(2);
        auto node1 = TreeNode(3);
        root0.left = &node0;
        root0.right = &node1;
        
        auto soln = solver.maxPathSum(&root0);
        cout << "Expected 6, computed: " << soln << endl;
    }

    {
        auto root0 = TreeNode(-10);
        auto node0 = TreeNode(3);
        auto node1 = TreeNode(20);
        auto node2 = TreeNode(15);
        auto node3 = TreeNode(7);
        root0.left = &node0;
        root0.right = &node1;
        node1.left = &node2;
        node1.right = &node3;
        
        auto soln = solver.maxPathSum(&root0);
        cout << "Expected 42, computed: " << soln << endl;
    }

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
        
        auto soln = solver.maxPathSum(&root0);
        cout << "Expected 47, computed: " << soln << endl;
    }
    
    {
        auto root0 = TreeNode(1);
        
        auto soln = solver.maxPathSum(&root0);
        cout << "Expected 1, computed: " << soln << endl;
    }

    {
        auto root0 = TreeNode(-3);
        
        auto soln = solver.maxPathSum(&root0);
        cout << "Expected -3, computed: " << soln << endl;
    }

    return 0;
}
