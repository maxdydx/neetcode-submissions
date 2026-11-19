/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
9101112$0 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) 
    {
        std::unordered_set<ListNode*> remember;
        ListNode* curr = head;
        bool ret = false;
        int count = 0;

        while (count <= 1000) {
            if(remember.contains(curr)) {
                ret = true;
                break;
            } else {
                if(curr == nullptr) {
                    break;
                } else {
                    remember.insert(curr);
                    curr = curr->next;
                    count++;
                } 
            }
        }
        return ret;
    }
};
