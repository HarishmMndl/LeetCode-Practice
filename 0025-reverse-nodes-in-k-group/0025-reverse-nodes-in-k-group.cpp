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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        // chck count > k
        for(int i=0;i<k;i++){
         if(temp==nullptr) return head;
         temp = temp->next;
        }
        // Revering 
      ListNode* curr = head;
      ListNode* prev = nullptr;
      
      for(int i=0;i<k;i++){
        ListNode* nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
      }

      // Connect remaining list
        head->next = reverseKGroup(curr, k);

        return prev;
    }
};