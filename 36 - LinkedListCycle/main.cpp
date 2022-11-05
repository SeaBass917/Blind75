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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        
        auto *p_fast = head;
        auto *p_slow = head;        
        
        do{
            p_fast = p_fast->next;
            if(!p_fast) return false;
            p_fast = p_fast->next;
            if(!p_fast) return false;
            p_slow = p_slow->next;
        }
        while (p_fast != p_slow);
        return true;
    }
};

int main(int argc, char const *argv[]){

    auto solver = Solution();

    {
        auto node0 = new ListNode(3);
        auto node1 = new ListNode(2);
        auto node2 = new ListNode(0);
        auto node3 = new ListNode(-1);
        node0->next = node1;
        node1->next = node2;
        node2->next = node3;
        node3->next = node1;

        auto soln_str = (solver.hasCycle(node0))? "True" : "False";
        cout << "Expected TRUE, computed: " << soln_str << endl;
        
    }

    {
        auto node0 = new ListNode(3);
        auto node1 = new ListNode(2);
        auto node2 = new ListNode(0);
        auto node3 = new ListNode(-1);
        node0->next = node1;
        node1->next = node2;
        node2->next = node3;

        auto soln_str = (solver.hasCycle(node0))? "True" : "False";
        cout << "Expected FALSE, computed: " << soln_str << endl;
        
    }

    {
        auto node0 = new ListNode(3);

        auto soln_str = (solver.hasCycle(node0))? "True" : "False";
        cout << "Expected FALSE, computed: " << soln_str << endl;
        
    }

    {
        auto node0 = new ListNode(3);
        node0->next = node0;

        auto soln_str = (solver.hasCycle(node0))? "True" : "False";
        cout << "Expected TRUE, computed: " << soln_str << endl;
        
    }

    return 0;
}
