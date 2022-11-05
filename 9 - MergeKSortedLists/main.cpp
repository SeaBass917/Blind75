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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Remove all null lists
        lists.erase(std::remove(lists.begin(), lists.end(), nullptr), lists.end());
        
        // Check that we have any lists to go through.
        if(lists.size() == 0) return nullptr;
        
        // Perform a 2 list merge in pairs until all have merged
        // O(logn)
        int iL = 0;
        int iR = lists.size()-1;
        while (iL < iR){
            while (iL < iR){
                lists[iL] = mergeTwoLists(lists[iL], lists[iR]);
                
                iL++;
                iR--;
            }
            iL = 0;
        }
        
        return lists[0];
    }
    
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* list_out;
        
        // Trivial Cases
        if (!list1) return list2;
        if (!list2) return list1;
        
        // Use the following to traverse each list
        ListNode* node_a = list1;
        ListNode* node_b = list2;
        ListNode* node_out;
        
        // Unroll the first loop, so we always have non-null list_out
        if(node_a->val < node_b->val){
            list_out = node_a;
            node_a = node_a->next;
        }
        else{
            list_out = node_b;
            node_b = node_b->next;
        }
        
        node_out = list_out;
        
        while(node_a || node_b){
            
            // Null Checks (1 can be null, but never both)
            // Consider null INTMAX so we always select the other
            const int val_a = node_a? node_a->val : INT32_MAX;
            const int val_b = node_b? node_b->val : INT32_MAX;
                        
            if(val_a < val_b){
                node_out->next = node_a;
                node_a = node_a->next;
            }
            else{
                node_out->next = node_b;
                node_b = node_b->next;
            }
            
            node_out = node_out->next;
        }
        
        return list_out;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    vector<ListNode *> vec1 = {makeNodeList({1,2,4}), makeNodeList({1,3,4}), makeNodeList({2,6,8})};
    auto soln1 = solver.mergeKLists(vec1);
    if(vecNodeCmp({1,1,2,2,3,4,4,6,8}, soln1)){
        std::cout << "Passed" << std::endl;
    }
    else{
        std::cout << "Failed" << std::endl;
    }

    cleanupNodeList(soln1);
    
    return 0;
}
