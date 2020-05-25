#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};
void printLinkedList(Node *head)
{
    cout << "[ ";
    while (head != NULL)
    {
        cout << head->data;
        head = head->next;
        if (head != NULL)
            cout << "->";
    }
    cout << "->NULL ]";
}
Node *createLinkedList(vector<int> arr)
{
    Node *head = NULL;
    Node *curr = head;
    for (auto &v : arr)
    {
        if (!curr)
            curr = new Node(v), head = curr;
        else
            curr->next = new Node(v), curr = curr->next;
    }
    return head;
}
/* Node *reverse(Node *head)
{
    if (!head->next)
        return head;
    Node *rest = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
} */
Node *reverse(Node *head)
{
    Node *curr = head;
    stack<int> s;
    Node *evenHead = NULL;
    while (curr)
    {
        if (curr->data % 2 == 0)
        {
            if (!evenHead)
                evenHead = curr;
            s.push(curr->data);
        }
        else
        {
            while (!s.empty())
            {
                evenHead->data = s.top();
                s.pop();
                evenHead = evenHead->next;
            }
            evenHead = NULL;
        }
        curr = curr->next;
    }
    while (!s.empty())
    {
        evenHead->data = s.top();
        s.pop();
        evenHead = evenHead->next;
    }
    return head;
}
int main()
{
    Node *head_1 = createLinkedList({6, 2, 8, 9, 12, 16, 17, 18});
    printLinkedList(head_1);
    Node *output_1 = reverse(head_1);
    printLinkedList(output_1);
    return 0;
}