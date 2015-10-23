/*
Reverse a singly linked list.
*/

/*
看了解答才想到这样的解答，链表还是没有学好。要努力！
迭代版本的还是比递归版本的好理解。。。

不过要创建next的节点来记录head->next否则会找不到后面一个节点。
递归版的要再理解一下，这里只写出来迭代
*/

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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        while(head){
            ListNode * next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
