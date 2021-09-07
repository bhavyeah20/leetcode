/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head, *next, *prev = NULL;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
};

//or

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode *returnsTail(ListNode *node, ListNode **head){
    
        if(node->next == NULL)
            *head = node;

        else{
            ListNode *temp = returnsTail(node->next,head);
            temp->next = node;
        }
    
        node->next = NULL;
        return node;
    }
    
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode *newTail = returnsTail(head,&head);
        return head;
    }
};