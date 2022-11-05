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
    ListNode* reverseList(ListNode* head) {
        auto curr = head;
        ListNode* prev = nullptr;
        while(curr){
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        auto nodes = makeNodeList({1,2,3});
        auto soln = solver.reverseList(nodes);
        if(vecNodeCmp({3,2,1}, soln)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }

    {
        auto nodes = makeNodeList({1});
        auto soln = solver.reverseList(nodes);
        if(vecNodeCmp({1}, soln)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }

    {
        auto nodes = makeNodeList({});
        auto soln = solver.reverseList(nodes);
        if(vecNodeCmp({}, soln)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }

    {
        auto nodes = makeNodeList({1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9});
        auto soln = solver.reverseList(nodes);
        if(vecNodeCmp({9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1,9,8,7,6,5,4,3,2,1}, soln)){
            std::cout << "Passed" << std::endl;
        }
        else{
            std::cout << "Failed" << std::endl;
        }
        cleanupNodeList(nodes);
    }

    return 0;
}
