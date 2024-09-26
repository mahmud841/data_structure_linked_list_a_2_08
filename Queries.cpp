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

void insert_function_at_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_function_at_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void delete_function_at_the_index(Node *&head, int index)
{
    if (head == NULL)
        return;
    if (index == 0)
    {
        Node *toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < index - 1; ++i)
    {
        if (temp == NULL || temp->next == NULL)
        {
            return;
        }
        temp = temp->next;
    }

    if (temp->next == NULL)
        return;
    Node *toDeleteNode = temp->next;
    temp->next = toDeleteNode->next;
    delete toDeleteNode;
}

void print_list_function(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int X, V;
        cin >> X >> V;

        if (X == 0)
        {
            insert_function_at_head(head, V);
        }
        else if (X == 1)
        {
            insert_function_at_tail(head, V);
        }
        else if (X == 2)
        {
            delete_function_at_the_index(head, V);
        }
        print_list_function(head);
    }

    return 0;
}

//*****HappY Coding
