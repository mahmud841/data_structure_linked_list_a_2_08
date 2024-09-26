#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert_function_at_end(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

bool check_list_equals_or_not(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val != temp2->val)
        {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 == NULL && temp2 == NULL)
    {
        return true;
    }

    return false;
}

void delete_list_function(Node *&head)
{
    Node *active = head;
    while (active != NULL)
    {
        Node *next = active->next;
        delete active;
        active = next;
    }
    head = NULL;
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    int val;

    while (cin >> val && val != -1)
    {
        insert_function_at_end(head1, tail1, val);
    }

    while (cin >> val && val != -1)
    {
        insert_function_at_end(head2, tail2, val);
    }

    if (check_list_equals_or_not(head1, head2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    delete_list_function(head1);
    delete_list_function(head2);

    return 0;
}
