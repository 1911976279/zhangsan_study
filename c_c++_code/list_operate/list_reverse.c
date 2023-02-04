/*
  题目：链表反转
*/

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pHead ListNode类 
 * @return ListNode类
 */
struct ListNode* ReverseList(struct ListNode* pHead ) {
    // write code here
    if(pHead == NULL)
        return NULL;
   
    if(pHead->next == NULL)
        return pHead;
   
    struct ListNode* pre = NULL;
    struct ListNode* next = NULL;

    while(pHead != NULL)
    {
        next = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }
    return pre;
}