#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
    int m;
    int n;
    vector<vector<bool>> visited;
    unordered_set<string> found_words;
    class TrieNode;
    
    using ParentEdge = pair<TrieNode *, char>;
    
    class TrieNode {
        public:
        map<char, TrieNode *> children;
        ParentEdge parent = {nullptr, ' '};
        bool is_eow = false;
        
        TrieNode(TrieNode *p = nullptr, const char c = ' ') : parent({p, c}){};
    };
    
    class Trie {
        public:
        TrieNode *root;
        
        Trie() {
            root = new TrieNode();
        }
        
        Trie(const vector<string> words) {
            root = new TrieNode();
            for(const auto word : words){
                insert(word);
            }
        }

        const TrieNode * const get_root() const{
            return root;
        }

        void insert(string word) {
            auto node = root;
            for(const char c : word){
                auto &children = node->children;
                if(children.find(c) == children.end()){
                    node = new TrieNode(node, c);
                    children[c] = node;
                }
                else{
                    node = children[c];
                }
            }
            node->is_eow = true;
        }

        bool search(string word) const {
            auto node = root;
            for(const char c : word){
                auto &children = node->children;
                if(children.find(c) == children.end()) return false;
                node = children[c];
            }
            return node->is_eow;
        }

        bool startsWith(const char c) const {
            auto &children = root->children;
            return children.find(c) != children.end();
        }
    };
    
    void dfs(const vector<vector<char>>& grid, const int i, const int j, const TrieNode * const root, string word){
        
        if(visited[i][j]) return;

        const auto c = grid[i][j];
        const auto node = root->children.at(c);
        if(node->is_eow){
            found_words.emplace(word);
        }
        const auto &children = node->children;

        visited[i][j] = true;
        
        // North
        if(0 < i){
            const auto cN = grid[i-1][j];
            if(children.find(cN) != children.end()){
                dfs(grid, i-1, j, node, word+cN);
            }
        }
        
        // South
        if(i+1 < m){
            const auto cS = grid[i+1][j];
            if(children.find(cS) != children.end()){
                dfs(grid, i+1, j, node, word+cS);
            }
        }
        
        // West
        if(0 < j){
            const auto cW = grid[i][j-1];
            if(children.find(cW) != children.end()){
                dfs(grid, i, j-1, node, word+cW);
            }
        }
        
        // East
        if(j+1 < n){
            const auto cE = grid[i][j+1];
            if(children.find(cE) != children.end()){
                dfs(grid, i, j+1, node, word+cE);
            }
        }
        
        visited[i][j] = false;
        
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.empty()) return {};
        
        // Initialize internal members
        m = board.size();
        n = board[0].size();
        found_words.clear();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        // Construct a trie based on the dictionary of words.
        const auto trie = Trie(words);
        
        // Loop through each starting point
        // Breanch our down our trie and tag any words we find
        // in the found_words vector.
        for(unsigned i = 0; i < m; i++){
            const auto row = board[i];
            for(unsigned j = 0; j < n; j++){
                const char c = row[j];
                
                if(trie.startsWith(c)){
                    dfs(board, i, j, trie.get_root(), string(1, c));
                }
            }
        }
        
        return vector<string>(found_words.begin(), found_words.end());
    }
};

int main(int argc, char const *argv[]){
    auto solver = Solution();

    {
        vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
        vector<string> words = {"oath","pea","eat","rain"};
        auto soln = solver.findWords(board, words);
        cout << "Expected [\"oath\",\"eat\"], computed: [ ";
        for(const auto s : soln){
            cout << '"' << s << "\",";
        }
        cout << ']' << endl;
    }

    {
        vector<vector<char>> board = {{'a','a'}};
        vector<string> words = {"aaa"};
        auto soln = solver.findWords(board, words);
        cout << "Expected [], computed: [ ";
        for(const auto s : soln){
            cout << '"' << s << "\",";
        }
        cout << ']' << endl;
    }

    {
        vector<vector<char>> board = {{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'},{'a','a','a','a','a','a','a','a','a','a','a','a'}};
        vector<string> words = {"lllllll","fffffff","ssss","s","rr","xxxx","ttt","eee","ppppppp","iiiiiiiii","xxxxxxxxxx","pppppp","xxxxxx","yy","jj","ccc","zzz","ffffffff","r","mmmmmmmmm","tttttttt","mm","ttttt","qqqqqqqqqq","z","aaaaaaaa","nnnnnnnnn","v","g","ddddddd","eeeeeeeee","aaaaaaa","ee","n","kkkkkkkkk","ff","qq","vvvvv","kkkk","e","nnn","ooo","kkkkk","o","ooooooo","jjj","lll","ssssssss","mmmm","qqqqq","gggggg","rrrrrrrrrr","iiii","bbbbbbbbb","aaaaaa","hhhh","qqq","zzzzzzzzz","xxxxxxxxx","ww","iiiiiii","pp","vvvvvvvvvv","eeeee","nnnnnnn","nnnnnn","nn","nnnnnnnn","wwwwwwww","vvvvvvvv","fffffffff","aaa","p","ddd","ppppppppp","fffff","aaaaaaaaa","oooooooo","jjjj","xxx","zz","hhhhh","uuuuu","f","ddddddddd","zzzzzz","cccccc","kkkkkk","bbbbbbbb","hhhhhhhhhh","uuuuuuu","cccccccccc","jjjjj","gg","ppp","ccccccccc","rrrrrr","c","cccccccc","yyyyy","uuuu","jjjjjjjj","bb","hhh","l","u","yyyyyy","vvv","mmm","ffffff","eeeeeee","qqqqqqq","zzzzzzzzzz","ggg","zzzzzzz","dddddddddd","jjjjjjj","bbbbb","ttttttt","dddddddd","wwwwwww","vvvvvv","iii","ttttttttt","ggggggg","xx","oooooo","cc","rrrr","qqqq","sssssss","oooo","lllllllll","ii","tttttttttt","uuuuuu","kkkkkkkk","wwwwwwwwww","pppppppppp","uuuuuuuu","yyyyyyy","cccc","ggggg","ddddd","llllllllll","tttt","pppppppp","rrrrrrr","nnnn","x","yyy","iiiiiiiiii","iiiiii","llll","nnnnnnnnnn","aaaaaaaaaa","eeeeeeeeee","m","uuu","rrrrrrrr","h","b","vvvvvvv","ll","vv","mmmmmmm","zzzzz","uu","ccccccc","xxxxxxx","ss","eeeeeeee","llllllll","eeee","y","ppppp","qqqqqq","mmmmmm","gggg","yyyyyyyyy","jjjjjj","rrrrr","a","bbbb","ssssss","sss","ooooo","ffffffffff","kkk","xxxxxxxx","wwwwwwwww","w","iiiiiiii","ffff","dddddd","bbbbbb","uuuuuuuuu","kkkkkkk","gggggggggg","qqqqqqqq","vvvvvvvvv","bbbbbbbbbb","nnnnn","tt","wwww","iiiii","hhhhhhh","zzzzzzzz","ssssssssss","j","fff","bbbbbbb","aaaa","mmmmmmmmmm","jjjjjjjjjj","sssss","yyyyyyyy","hh","q","rrrrrrrrr","mmmmmmmm","wwwww","www","rrr","lllll","uuuuuuuuuu","oo","jjjjjjjjj","dddd","pppp","hhhhhhhhh","kk","gggggggg","xxxxx","vvvv","d","qqqqqqqqq","dd","ggggggggg","t","yyyy","bbb","yyyyyyyyyy","tttttt","ccccc","aa","eeeeee","llllll","kkkkkkkkkk","sssssssss","i","hhhhhh","oooooooooo","wwwwww","ooooooooo","zzzz","k","hhhhhhhh","aaaaa","mmmmm"};
        auto soln = solver.findWords(board, words);
        cout << "Expected [], computed: [ ";
        for(const auto s : soln){
            cout << '"' << s << "\",";
        }
        cout << ']' << endl;
    }

    return 0;
}
