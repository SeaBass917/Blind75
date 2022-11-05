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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) return !p && !q;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        auto root0 = TreeNode(2);
        auto node0 = TreeNode(1);
        auto node1 = TreeNode(3);
        root0.left = &node0;
        root0.right = &node1;
        
        auto root1 = TreeNode(2);
        auto node2 = TreeNode(1);
        auto node3 = TreeNode(3);
        root1.left = &node2;
        root1.right = &node3;

        auto soln = (solver.isSameTree(&root0, &root1))? "TRUE" : "FALSE";
        cout << "Expected TRUE found: " << soln << endl;
    }

    {
        auto root0 = TreeNode(2);
        auto node0 = TreeNode(1);
        auto node1 = TreeNode(900);
        root0.left = &node0;
        root0.right = &node1;
        
        auto root1 = TreeNode(2);
        auto node2 = TreeNode(1);
        auto node3 = TreeNode(3);
        root1.left = &node2;
        root1.right = &node3;

        auto soln = (solver.isSameTree(&root0, &root1))? "TRUE" : "FALSE";
        cout << "Expected FALSE found: " << soln << endl;
    }

    return 0;
}
