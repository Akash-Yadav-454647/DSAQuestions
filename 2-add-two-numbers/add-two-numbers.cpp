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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry = 0) {
        if(l1==nullptr && l2==nullptr && carry == 0){
            return nullptr;
        }
        int l1v = (l1 != nullptr) ? l1->val:0;
        int l2v = (l2 != nullptr) ? l2->val :0;
        int sum = l1v+l2v+carry;
        int nv = sum%10;
        int ncarry = sum/10;

        ListNode * newNode = new ListNode(nv);
        newNode->next = addTwoNumbers(
        (l1 != nullptr) ? l1->next : nullptr,
        (l2 != nullptr) ? l2->next : nullptr,
        ncarry);

        return newNode;
    }
};