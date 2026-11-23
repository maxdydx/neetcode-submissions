/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {


        std::unordered_map<Node*, Node*> copies;
        copies[nullptr] = nullptr;

        for(Node* curr = head; curr; curr = curr->next) {
            copies[curr] = new Node(curr->val);
        }

        for(Node* curr = head; curr; curr = curr->next) {
            Node* copy = copies[curr];
            copy->next = copies[curr->next];
            copy->random = copies[curr->random];
        }
        return copies[head];


        /*
        if(head == NULL) { return NULL; } //edge case

        Node* anchor = new Node(0); // 0 placeholder
        anchor->next = new Node(0);
        Node* new_list = anchor->next;

        while(head != NULL) {
            int save_value = head->val;
            Node* save_next = new Node(0);
            save_next = head->next;

            Node* save_random = new Node(0);
            save_random = head->random;

            head = head->next;
            

            new_list->val = save_value;
            new_list->next = save_next;
            new_list->random = save_random;
            new_list = new_list->next;
        }
        Node* ret = anchor->next;
        delete anchor;
        return ret;
        */
        
    }
};
