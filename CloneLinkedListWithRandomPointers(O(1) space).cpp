/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode * curr = A, *temp;
    
    //create new nodes and add them in between the original nodes.
    // for example, if original list is A->B->C the make it A->A'->B->B'->C->C'
    while(curr)
    {
        temp = curr->next;
        curr->next = new RandomListNode(curr->label);
        curr->next->next = temp;
        curr = temp;
    }
    curr = A;
    while(curr)
    {
        //curr->next->random is nothing but new inserted node's random pointer
        //curr->random->next is nothing but copy of current node's random
        
        curr->next->random = curr->random ? curr->random->next:curr->random;
        curr = curr->next ? curr->next->next : curr->next;
    }
    RandomListNode * original = A, *copy = A->next;
    RandomListNode * ansHead = copy;
    while(original and copy)
    {
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        
        original = original->next;
        copy = copy->next;
    }
    return ansHead;
}
