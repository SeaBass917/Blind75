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
    bool isValidBST(TreeNode* root) {
        return dfs(root, static_cast<long long>(INT32_MIN)-1, static_cast<long long>(INT32_MAX)+1);
    }
private:
    bool dfs(const TreeNode *const node, const long long min, const long long max){
        if(!node) return true;
        const int val = node->val;
        if(min < val && val < max) return dfs(node->left, min, val) && dfs(node->right, val, max);
        return false;
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        auto root = TreeNode(2);
        auto node0 = TreeNode(1);
        auto node1 = TreeNode(3);
        root.left = &node0;
        root.right = &node1;

        auto soln = (solver.isValidBST(&root))? "TRUE" : "FALSE";
        cout << "Expected TRUE found: " << soln << endl;
    }

    {
        auto root = TreeNode(5);
        auto node0 = TreeNode(1);
        auto node1 = TreeNode(4);
        auto node4 = TreeNode(3);
        auto node5 = TreeNode(6);
        root.left = &node0;
        root.right = &node1;
        node1.left = &node4;
        node1.right = &node5;

        auto soln = (solver.isValidBST(&root))? "TRUE" : "FALSE";
        cout << "Expected FALSE found: " << soln << endl;
    }

    {
        auto root = TreeNode(2);
        auto node0 = TreeNode(2);
        auto node1 = TreeNode(2);
        root.left = &node0;
        root.right = &node1;

        auto soln = (solver.isValidBST(&root))? "TRUE" : "FALSE";
        cout << "Expected FALSE found: " << soln << endl;
    }

    {
        auto root = TreeNode(2147483647);

        auto soln = (solver.isValidBST(&root))? "TRUE" : "FALSE";
        cout << "Expected TRUE found: " << soln << endl;
    }

    {
        auto root = TreeNode(2147483647);
        auto node0 = TreeNode(2147483647);
        root.left = &node0;

        auto soln = (solver.isValidBST(&root))? "TRUE" : "FALSE";
        cout << "Expected FALSE found: " << soln << endl;
    }

    return 0;
}
