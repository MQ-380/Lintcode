/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

/*
 一开始上手的时候还是没有想到可以通过next复制到已知节点来，然后删掉next节点
 
 一直纠结怎么找到上一个节点。。不过貌似无解。
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
    void deleteNode(ListNode* node){
    ListNode *tmp = node -> next;
       node->val = tmp->val;
       node->next = tmp->next;
       delete(tmp);
    }
};
