// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//     }
// };

// void insert_at_the_end(Node *&head, int value)
// {
//     Node *newNode = new Node(value);
//     if (head == NULL)
//     {
//         head = newNode;
//     }
//     else
//     {
//         Node *temp = head;
//         while (temp->next != NULL)
//         {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// int find_the_Index(Node *head, int X)
// {
//     int index = 0;
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->val == X)
//         {
//             return index;
//         }
//         temp = temp->next;
//         index++;
//     }
//     return -1; // if X is not found return -1
// }

// void delete_memory_space_from_List(Node *&head)
// {
//     Node *active = head;
//     Node *next;
//     while (active != NULL)
//     {
//         next = active->next;
//         delete active;
//         active = next;
//     }
//     head = NULL;
// }

// int main()
// {
//     int T;
//     cin >> T;

//     while (T--)
//     {
//         Node *head = NULL;
//         int val;

//         while (cin >> val && val != -1)
//         {
//             insert_at_the_end(head, val);
//         }

//         int X;
//         cin >> X;

//         cout << find_the_Index(head, X) << endl;
//         delete_memory_space_from_List(head);
//     }

//     return 0;
// }

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

void insert_in_end(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
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

int find_index(Node *head, int X)
{
    int index = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->val == X)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; // Return -1 if X is not found
}

void delete_from_list(Node *&head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        Node *head = NULL;
        Node *tail = NULL;
        int value;

        while (cin >> value && value != -1)
        {
            insert_in_end(head, tail, value);
        }

        int X;
        cin >> X;

        int index = find_index(head, X);
        cout << index << endl;
        delete_from_list(head);
    }

    return 0;
}
