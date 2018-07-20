/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
     unordered_map<RandomListNode *, RandomListNode *> mp;
     RandomListNode * head = A, *curr = NULL,*finalHead = NULL;
     while(head)
     {
         curr = new RandomListNode(head->label);
         mp[head] = curr;
         head = head->next;
     }
     head = A;
     while(head)
     {
         curr = mp[head];
         curr->next = mp[head->next];
         curr->random = mp[head->random];
         head = head->next;
     }
     finalHead = mp[A];
     return finalHead;

}
