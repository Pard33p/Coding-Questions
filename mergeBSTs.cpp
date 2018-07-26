void merge(Node *root1, Node *root2)
{
    Node * curr1 = root1, *curr2 = root2;
    bool done1 = false,done2 = false;
    bool finish1 = false, finish2 = false;
    stack<Node* > s1,s2;
    while(true)
    {
        int num1, num2;
        while(!done1 and !finish1)
        {
            if(curr1)
            {
                s1.push(curr1);
                curr1 = curr1->left;
            }
            else
            {
                if(s1.empty())
                {
                    finish1 = true;
                    num1 = INT_MAX;
                }
                else
                {
                    done1 = true;
                    curr1 = s1.top();
                    s1.pop();
                    num1 = curr1->data;
                    curr1 = curr1->right;
                }
            }
        }
        while(!done2 and !finish2)
        {
            if(curr2)
            {
                s2.push(curr2);
                curr2 = curr2->left;
            }
            else
            {
                if(s2.empty())
                {
                    finish2 = true;
                    num2 = INT_MAX;
                }
                else
                {
                    done2 = true;
                    curr2 = s2.top();
                    s2.pop();
                    num2 = curr2->data;
                    curr2 = curr2->right;
                }
            }
        }
        if(finish1 and finish2)
            return;
        if(num1 <= num2)
        {
            cout << num1 << " ";
            done1 = false;
        }
        else
        {
            cout << num2 << " ";
            done2 = false;
        }
    }
   //Your code here
}
