int countCommon(Node* a, Node * b)
{
    int count = 0;
    while(a and b)
    {
        if(a->data == b->data)
            count++;
        else
            break;
        a = a->next;
        b = b->next;
    }
    return count;
}
int maxPalindrome(Node *head)
{
    int result = 0;
    Node * curr = head, *prev = NULL;
    //reverse the list and during each step,
    //check common nodes in two parts of list for palindromes.
    while(curr)
    {
        Node * next = curr->next;
        curr->next = prev;
        
        //odd length palindromes(excluding curr)
        result = max(result, 2*countCommon(prev,next)+1);
        //even length palindromes(including curr)
        result = max(result,2*countCommon(curr,next));
        
        prev = curr;
        curr = next;
    }
    return result;
    //Your code here
}
