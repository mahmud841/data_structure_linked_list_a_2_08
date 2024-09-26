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

// void insert_function_at_the_end(Node *&head, int val)
// {
//     Node *newNode = new Node(val);
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

// int find_the_deferences(Node *head)
// {
//     if (head == NULL)
//     {
//         return 0;
//     }

//     int max_value = head->val;
//     int min_value = head->val;

//     Node *temp = head;
//     while (temp != NULL)
//     {
//         if (temp->val > max_value)
//         {
//             max_value = temp->val;
//         }
//         if (temp->val < min_value)
//         {
//             min_value = temp->val;
//         }
//         temp = temp->next;
//     }

//     return max_value - min_value;
// }

// int main()
// {
//     Node *head = NULL;
//     int val;

//     while (cin >> val && val != -1)
//     {
//         insert_function_at_the_end(head, val);
//     }

//     int got_min_max = find_the_deferences(head);
//     cout << got_min_max << endl;

//     return 0;
// }

// // #include <bits/stdc++.h>
// // using namespace std;

// // class Node
// // {
// // public:
// //     int val;
// //     Node *next;
// //     Node(int val)
// //     {
// //         this->val = val;
// //         this->next = NULL;
// //     }
// // };

// // void insert_function_at_end(Node *&head, int value)
// // {
// //     Node **temp = &head;
// //     while (*temp)
// //         temp = &((*temp)->next);
// //     *temp = new Node(value);
// // }

// // int find_the_differences(Node *head)
// // {
// //     int max_value = head->val, min_value = head->val;
// //     for (Node *temp = head; temp; temp = temp->next)
// //     {
// //         max_value = max(max_value, temp->val);
// //         min_value = min(min_value, temp->val);
// //     }
// //     return max_value - min_value;
// // }

// // int main()
// // {
// //     Node *head = NULL;
// //     for (int value; cin >> value && value != -1;)
// //         insert_function_at_end(head, value);
// //     cout << find_the_differences(head) << endl;
// //     return 0;
// // }

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

// insert function
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

// max min function
int find_max_min_difference_function(Node *head)
{
    int max_value = INT_MIN;
    int min_value = INT_MAX;

    Node *temp = head;
    while (temp != NULL)
    {
        max_value = max(max_value, temp->val);
        min_value = min(min_value, temp->val);
        temp = temp->next;
    }
    return max_value - min_value;
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
    Node *head = NULL;
    Node *tail = NULL;

    int val;

    while (cin >> val && val != -1)
    {
        insert_function_at_end(head, tail, val);
    }

    if (head != NULL)
    {
        int output = find_max_min_difference_function(head);
        cout << output << endl;
    }
    delete_list_function(head);

    return 0;
}
