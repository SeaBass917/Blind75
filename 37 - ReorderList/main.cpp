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
    void reorderList(ListNode* head) { 
        if(!head) return;

        // Find the middle pointer
        auto slow = head;
        auto fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the last half of the linked list
        // [1] -> [2] ->... | [3] -> [4]
        auto second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(second){
            auto tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        // Finally inter-weave the reversed list into the head
        // NOTE: THe last pointer needs to go to null
        auto first = head;
        second = prev;
        while(second){
            auto next_old = first->next;
            auto next_rev_old = second->next;

            first->next = second;
            second->next = next_old;

            first = next_old;
            second = next_rev_old;
        }
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        auto nodes = makeNodeList({1,2,3});
        solver.reorderList(nodes);
        if(vecNodeCmp({1,3,2}, nodes)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }

    {
        auto nodes = makeNodeList({1,2,3,4});
        solver.reorderList(nodes);
        if(vecNodeCmp({1,4,2,3}, nodes)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }

    {
        auto nodes = makeNodeList({1,2,3,4,5});
        solver.reorderList(nodes);
        if(vecNodeCmp({1,5,2,4,3}, nodes)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }
    
    {
        auto nodes = makeNodeList({1});
        solver.reorderList(nodes);
        if(vecNodeCmp({1}, nodes)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }
    
    {
        auto nodes = makeNodeList({1,2});
        solver.reorderList(nodes);
        if(vecNodeCmp({1,2}, nodes)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }
    
    return 0;
}
