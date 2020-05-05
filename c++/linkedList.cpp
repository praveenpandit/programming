#include <iostream>

using namespace std;

typedef struct listNode
{
    int value;
    struct listNode *next;
} listNode;
listNode *insert_at_position(listNode *head, int data, int pos)
{
    listNode *temp = new listNode;
    temp->value = data;
    listNode **cur = &head;
    for (int i = 1; *cur && i < pos; cur = &(*cur)->next, i++)
    {
    }
    temp->next = *cur;
    *cur = temp;
    return head;
}

listNode *insert_at_tail(listNode *head, int value)
{
    listNode *temp = new listNode;
    temp->value = value;
    temp->next = NULL;
    listNode **cur = &head;
    while (*cur)
    {
        cur = &(*cur)->next;
    }
    *cur = temp;
    return head;
}
void display(listNode *head)
{
    listNode *cur = head;
    int i = 1;
    while (cur)
    {
        cout << cur->value << "->";
        cur = cur->next;
        // cout << i++ << endl;
    }
}
bool is_list_even(listNode *head)
{
    listNode *cur = head;
    int i = 0;
    while (cur && ++i)
    {
        cur = cur->next;
    }
    cout << i << endl;
    return !(i % 2) ? true : false;
}
listNode *find_middle_node(listNode *head)
{
    listNode *slow = head;
    listNode *fast = head;
    while (fast)
    {
        fast = fast->next;
        if (fast)
            fast = fast->next;
        if (!fast)
            break;
        slow = slow->next;
    }
    return slow;
}
listNode *find_n_node_from_end(listNode *head, int n)
{
    listNode *slow = head;
    listNode *fast = head;
    while (n && fast)
    {
        fast = fast->next;
        n--;
    }
    if (!fast && n != 0)
        return NULL;
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
int main()
{
    listNode *head = NULL;
    head = insert_at_tail(head, 9);
    head = insert_at_tail(head, 1);
    head = insert_at_position(head, 3, 1);
    // head = insert_at_tail(head, 6);
    // head = insert_at_tail(head, 7);
    // head = insert_at_tail(head, 8);
    // insert_at_tail(&head, 2);
    display(head);
    // cout << is_list_even(head);
    // cout << find_middle_node(head)->value;
    // cout << endl
    //      << find_n_node_from_end(head, 5)->value;
    return 0;
}