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

void remove_duplicates_function(Node *head)
{
    Node *active = head;

    while (active != NULL && active->next != NULL)
    {
        Node *running = active;
        while (running->next != NULL)
        {
            if (running->next->val == active->val)
            {
                Node *duplicateNodeFound = running->next;
                running->next = running->next->next;
                delete duplicateNodeFound;
            }
            else
            {
                running = running->next;
            }
        }
        active = active->next;
    }
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
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_function_at_tail(head, val);
    }
    remove_duplicates_function(head);
    print_list_function(head);

    return 0;
}
