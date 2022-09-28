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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* fast;
//         ListNode* slow;

//         fast = head;
//         slow = head;

//         while(n){
//             fast = fast->next;
//             n--;
//         }

//         if(fast == NULL){
//             head = head->next;
//             return head;
//         }

//         while(fast->next){
//             slow = slow->next;
//             fast = fast->next;
//         }

//         if(slow->next && slow->next->next){
//             slow->next = slow->next->next;
//         } else {
//             slow->next = NULL;
//         }

//         return head;
//     }
// };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* cur;
        int len = 0;
        
        cur = dummy->next;
        while(cur){
            ++len;
            cur = cur->next;
        }
        
        // cout << "len: " << len << endl;
        
        cur = dummy;
        for(int i = 0; i < len; ++i, cur = cur->next){
            //i is 1-based
            // cout << i << " : " << cur->val << endl;
            if(i == len-n){
                //this is the node previous to the node to be deleted
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
                break;
            }
        }
        
        return dummy->next;
    }
};