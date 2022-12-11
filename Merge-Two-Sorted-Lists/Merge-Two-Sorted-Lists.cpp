class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	    // if list1 happen to be NULL
		// we will simply return list2.
        if(list1 == NULL)
            return list2;
		// if list2 happen to be NULL
		// we will simply return list1.
        if(list2 == NULL)
            return list1;
        ListNode * ptr = list1;
        if(list1 -&gt; val &gt; list2 -&gt; val)
        {
            ptr = list2;
            list2 = list2 -&gt; next;
        }
        else
        {
            list1 = list1 -&gt; next;
        }
        ListNode *curr = ptr;
		// till one of the list doesn't reaches NULL
        while(list1 &amp;&amp;  list2)
        {
            if(list1 -&gt; val &lt; list2 -&gt; val){
                curr-&gt;next = list1;
                list1 = list1 -&gt; next;
            }
            else{
                curr-&gt;next = list2;
                list2 = list2 -&gt; next;
            }
            curr = curr -&gt; next;
        }
		// adding remaining elements of bigger list.
        if(!list1)
            curr -&gt; next = list2;
        else
            curr -&gt; next = list1;
        return ptr;
    }
};