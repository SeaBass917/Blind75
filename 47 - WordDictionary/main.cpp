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
#include <chrono>
using namespace std;

class WordDictionary {
    struct TrieNode {
        map<char, TrieNode *> children;
        bool is_eow = false;
    };
    TrieNode *root;
    
    bool search(const string &word, const TrieNode * const node, const string::const_iterator iter) {

        if(iter == word.end()) return node->is_eow;
        const char c = *iter;

        auto &children = node->children;
        if(c == '.'){
            for(const auto &pair: children){
                if(search(word, pair.second, iter+1)) return true;
            }
            return false;
        }
        else{
            if(children.find(c) == children.end()) return false;
            return search(word, children.at(c), iter+1);
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        auto node = root;
        for(const char c : word){
            auto &children = node->children;
            if(children.find(c) == children.end()){
                node = new TrieNode();
                children[c] = node;
            }
            else{
                node = children[c];
            }
        }
        node->is_eow = true;
    }
    
    bool search(string word) {
        return search(word, root, word.begin());
    }
};

vector<string> big_tc = {
    "a", "ability", "able", "about", "above", "accept", "according", 
    "account", "across", "act", "action", "activity", "actually", "add", 
    "address", "administration", "admit", "adult", "affect", "after", 
    "again", "against", "age", "agency", "agent", "ago", "agree", 
    "agreement", "ahead", "air", "all", "allow", "almost", "alone", 
    "along", "already", "also", "although", "always", "american",
    "among", "amount", "analysis", "and", "animal", "another", "answer", 
    "any", "anyone", "anything", "appear", "apply", "approach", "area", 
    "argue", "arm", "around", "arrive", "art", "article", "artist", "as",
    "ask", "assume", "at", "attack", "attention", "attorney", "audience", 
    "author", "authority", "available", "avoid", "away", "baby", "back", 
    "bad", "bag", "ball", "bank", "bar", "base", "be", "beat", "beautiful", 
    "because", "become", "bed", "before", "begin", "behavior", "behind", 
    "believe", "benefit", "best", "better", "between", "beyond", "big", "bill", 
    "billion", "bit", "black", "blood", "blue", "board", "body", "book", 
    "born", "both", "box", "boy", "break", "bring", "brother", "budget", 
    "build", "building", "business", "but", "buy", "by", "call", "camera", 
    "campaign", "can", "cancer", "candidate", "capital", "car", "card", 
    "care", "career", "carry", "case", "catch", "cause", "cell", "center", 
    "central", "century", "certain", "certainly", "chair", "challenge", 
    "chance", "change", "character", "charge", "check", "child", "choice", 
    "choose", "church", "citizen", "city", "civil", "claim", "class", 
    "clear", "clearly", "close", "coach", "cold", "collection", "college", 
    "color", "come", "commercial", "common", "community", "company", 
    "compare", "computer", "concern", "condition", "conference", "congress", 
    "consider", "consumer", "contain", "continue", "control", "cost", 
    "could", "country", "couple", "course", "court", "cover", "create", 
    "crime", "cultural", "culture", "cup", "current", "customer", "cut", 
    "dark", "data", "daughter", "day", "dead", "deal", "death", "debate", 
    "decade", "decide", "decision", "deep", "defense", "degree", "democrat", 
    "democratic", "describe", "design", "despite", "detail", "determine", 
    "develop", "development", "die", "difference", "different", "difficult", 
    "dinner", "direction", "director", "discover", "discuss", "discussion", 
    "disease", "do", "doctor", "dog", "door", "down", "draw", "dream", "drive", 
    "drop", "drug", "during", "each", "early", "east", "easy", "eat", "economic", 
    "economy", "edge", "education", "effect", "effort", "eight", "either", 
    "election", "else", "employee", "end", "energy", "enjoy", "enough", "enter", 
    "entire", "environment", "environmental", "especially", "establish", "even", 
    "evening", "event", "ever", "every", "everybody", "everyone", "everything", 
    "evidence", "exactly", "example", "executive", "exist", "expect", "experience", 
    "expert", "explain", "eye", "face", "fact", "factor", "fail", "fall", "family", 
    "far", "fast", "father", "fear", "federal", "feel", "feeling", "few", "field", 
    "fight", "figure", "fill", "film", "final", "finally", "financial", "find", "fine", 
    "finger", "finish", "fire", "firm", "first", "fish", "five", "floor", "fly", "focus", 
    "follow", "food", "foot", "for", "force", "foreign", "forget", "form", "former", 
    "forward", "four", "free", "friend", "from", "front", "full", "fund", "future", "game", 
    "garden", "gas", "general", "generation", "get", "girl", "give", "glass", "go", "goal", 
    "good", "government", "great", "green", "ground", "group", "grow", "growth", "guess", 
    "gun", "guy"};

int main(int argc, char const *argv[]){

    const auto start = chrono::high_resolution_clock::now();

    for(unsigned i = 0; i < 1234; i++){
        WordDictionary trie = WordDictionary();
        for(const auto str : big_tc){
            trie.addWord(str);
        }
        trie.search("..");
        trie.search(".......");
        trie.search("...a...");
        trie.search(".nv.ro.me.ta.");
        trie.search("a.....");
        trie.search("a..a..");
        trie.search("..uc.ation");
    }
    const auto end = chrono::high_resolution_clock::now();

    const auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time elapsed: " << duration/1000 << "ms" << endl;

    {
        WordDictionary trie = WordDictionary();
        trie.addWord("camping");
        trie.addWord("camel");
        trie.addWord("cameron");
        if(trie.search("cam") != false) cout << "Failed! 2 - 1" << endl;
        if(trie.search("camping") != true) cout << "Failed! 2 - 2" << endl;
        if(trie.search("camel") != true) cout << "Failed! 2 - 3" << endl;
        if(trie.search("cameron") != true) cout << "Failed! 2 - 4" << endl;
        if(trie.search("drcameron") != false) cout << "Failed! 2 - 5" << endl;
    }

    return 0;
}
