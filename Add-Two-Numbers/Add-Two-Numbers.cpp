/**
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1-&gt;val;
                l1=l1-&gt;next;
            }
            if(l2!=NULL){
                sum+=l2-&gt;val;
                l2=l2-&gt;next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp-&gt;next=newnode;
            temp=temp-&gt;next;
        }
        return dummy-&gt;next;
    }
};