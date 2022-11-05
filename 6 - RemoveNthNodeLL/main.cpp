#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <utility>
#include <list>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <numeric>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// NodeList factory
ListNode *makeNodeList(vector<int> vec){
    if(vec.size() == 0) return nullptr;

    auto ptr = vec.begin();

    auto list_0 = new ListNode(*ptr);
    auto curr_0 = list_0;

    ptr++;
    while(ptr != vec.end()){
        curr_0->next = new ListNode(*ptr);
        curr_0 = curr_0->next;
        ptr++;
    }

    return list_0;
}

// Vec, Node Compare
bool vecNodeCmp(const vector<int> vec, const ListNode * lis){
    if(vec.empty()){
        if(lis == nullptr) return true;
        return false;
    }

    auto ptr = lis;
    for(const auto ele : vec){
        if(!ptr) return false;
        if(ptr->val != ele) return false;
        ptr = ptr->next;
    }
    return true;
}

// For cleaning up a node list
void cleanupNodeList(ListNode *nodes){
    auto curr = nodes;
    while(curr){
        const auto next = curr->next;
        delete curr;
        curr = next;
    }
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head) return head;
        
        // Convert to a datastructure that has constant lookup time
        // O(n) | O(n)
        vector<ListNode*> v = {};
        auto node = head;
        while(node){
            v.push_back(node);
            node = node->next;
        }
        
        // Go to that location and remove the element
        // Be cautious of boundaries
        const int i_remove = v.size() - n;
        if (i_remove == 0) head = head->next;
        else        v[i_remove-1]->next = v[i_remove]->next;
        
        return head;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    auto nodes1 = makeNodeList({1,2,3,4,5});
    auto soln1 = solver.removeNthFromEnd(nodes1, 2);
    if(vecNodeCmp({1,2,3,5}, soln1)){
        std::cout << "Passed" << std::endl;
    }
    else{
        std::cout << "Failed" << std::endl;
    }

    cleanupNodeList(nodes1);
    
    return 0;
}
