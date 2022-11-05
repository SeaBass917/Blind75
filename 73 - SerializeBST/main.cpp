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
#include <queue>
#include <sstream>
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


bool do_match(TreeNode* root, TreeNode* subRoot){
    if(!root || !subRoot) return root == subRoot;
    if(root->val != subRoot->val) return false;
    return do_match(root->left, subRoot->left) && do_match(root->right, subRoot->right);
};

        
// In order traverse and stringify with
// - nums
// - 'N' for null
// - ',' delimit
class Codec {
    const char delim = ',';
    const char nullchar = 'N';

    // to string each node value, or 'N' is it is null
    // Pre-order traversal
    void dfs_encode(stringstream &serial, TreeNode *node){
        if(!node){
            serial << nullchar << delim;
            return;
        }

        serial << node->val << delim;
        dfs_encode(serial, node->left);
        dfs_encode(serial, node->right);
    }
    
    TreeNode *dfs_decode(stringstream &serial){
        string val_str;
        if(!getline(serial, val_str, delim) || (val_str == "N")) return nullptr;
        return new TreeNode(stoi(val_str), dfs_decode(serial), dfs_decode(serial));
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream serial;
        dfs_encode(serial, root);
        return serial.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream serial(data);
        return dfs_decode(serial);
    }
};

int main(int argc, char const *argv[]){

    auto codec = Codec();

    {
        auto root1 = TreeNode(2);
        auto node0 = TreeNode(1);
        auto node1 = TreeNode(3);
        root1.left = &node0;
        root1.right = &node1;

        auto tree_str = codec.serialize(&root1);
        auto root2 = codec.deserialize(tree_str);

        auto soln = (do_match(&root1, root2))? "TRUE" : "FALSE";
        cout << "Expected TRUE found: " << soln << endl;
    }

    return 0;
}

