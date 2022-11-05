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

class Trie {
    struct TrieNode {
        map<char, TrieNode *> children;
        bool is_eow = false;
    };
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto node = root;
        for(const char c : word){
            auto &children = node->children;
            TrieNode *c_node = nullptr;
            if(children.find(c) == children.end()){
                c_node = new TrieNode();
                children[c] = c_node;
            }
            else{
                c_node = children[c];
            }
            node = c_node;
        }
        node->is_eow = true;
    }
    
    bool search(string word) {
        auto node = root;
        for(const char c : word){
            auto &children = node->children;
            if(children.find(c) == children.end()) return false;
            node = children[c];
        }
        return node->is_eow;
    }
    
    bool startsWith(string prefix) {
        auto node = root;
        for(const char c : prefix){
            auto &children = node->children;
            if(children.find(c) == children.end()) return false;
            node = children[c];
        }
        return true;
    }
};

int main(int argc, char const *argv[]){

    {
        Trie trie = Trie();
        trie.insert("apple");
        if(trie.search("apple") != true) cout << "Failed! 1 - 1" << endl;
        if(trie.search("app") != false) cout << "Failed! 1 - 2" << endl;
        if(trie.startsWith("app") != true) cout << "Failed! 1 - 3" << endl;
        trie.insert("app");
        if(trie.search("app") != true) cout << "Failed! 1 - 4" << endl;
    }

    {
        Trie trie = Trie();
        trie.insert("camping");
        trie.insert("camel");
        trie.insert("cameron");
        if(trie.search("cam") != false) cout << "Failed! 2 - 1" << endl;
        if(trie.search("camping") != true) cout << "Failed! 2 - 2" << endl;
        if(trie.search("camel") != true) cout << "Failed! 2 - 3" << endl;
        if(trie.search("cameron") != true) cout << "Failed! 2 - 4" << endl;
        if(trie.search("drcameron") != false) cout << "Failed! 2 - 5" << endl;
    }

    return 0;
}
