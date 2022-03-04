/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* out = new ListNode(0);
      ListNode* res;
      res = out;
      int plus = 0;
      int extra = 0;
      int val1=0;
      int val2=0;
      while(plus||l1||l2){
        val1=l1?l1->val:0;
        val2=l2?l2->val:0;
        extra = val1+val2+plus;
        plus = extra>=10;
        extra = extra%10;
        cout<<"plus is "<<plus<<"extra is"<<extra<<endl;
        l1 = l1?l1->next:l1;
        l2 = l2?l2->next:l2;

        res->next = new ListNode(extra);
        res = res->next;
      }
      return out->next;
    }
};
