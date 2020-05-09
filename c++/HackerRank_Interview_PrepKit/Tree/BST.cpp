#include <iostream>
using namespace std;

class BST
{
    class Node
    {
        int data;
        Node *left = nullptr;
        Node *right = nullptr;
        Node *parent = nullptr;
        int height = 0;
        friend class BST;

    public:
        Node(int val) : data(val) {}
    };
    static Node *root = nullptr;

public:
    Node *insert(Node *root, int data, int height = 0)
    {
        if (!root)
        {
            Node *temp = new Node(data);
            temp->height = height;
            return temp;
        }
        else
        {
            if (data < root->data)
            {
                root->left = insert(root->left, data, height + 1);
                root->parent = root;
            }
            if (data > root->data)
            {
                root->right = (root->right, data, height + 1);
                root->parent = root;
            }
        }
        return root;
    }
};
int main()
{
    Node n(10);
    cout << n.data << endl;
    cout << n.left << endl;
    cout << n.right << endl;
    cout << n.parent << endl;
    cout << n.height << endl;
    return 0;
}