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
        int height = 1;
        friend class BST;

    public:
        Node(int val) : data(val) {}
    };
    static Node *sp_root;
    Node *curNode = nullptr;

public:
    Node *insert(int data, Node *root = sp_root)
    {
        if (!root)
        {
            Node *temp = new Node(data);
            if (!sp_root)
                sp_root = temp;
            return temp;
        }
        else
        {
            if (data < root->data)
            {
                root->left = insert(data, root->left);
                root->height = 1 + root->left->height;
                root->left = reBalance(root->left);
                // root->height = 1 + root->left->height;
                root->left->parent = root;
            }
            if (data > root->data)
            {
                root->right = insert(data, root->right);
                root->height = 1 + root->right->height;
                root->right = reBalance(root->right);
                // root->height = 1 + root->right->height;
                root->right->parent = root;
            }
        }
        return root;
    }
    void inOrder(Node *root = sp_root)
    {
        if (root)
        {
            inOrder(root->left);
            cout << "[" << root->data << "-" << root->height
                 << "=" << root->parent << "]" << endl;
            inOrder(root->right);
        }
    }
    int slop(int data)
    {
        int lheight = 0, rheight = 0;
        if (find(data))
        {
            if (curNode->left)
                lheight = curNode->left->height;
            if (curNode->right)
                rheight = curNode->right->height;
        }
        return lheight - rheight;
    }
    int height(Node *root = sp_root)
    {
        if (!root)
            return 0;
        else
            return (1 + std::max(height(root->left), height(root->right)));
    }
    bool find(int data, Node *root = sp_root)
    {
        if (root)
        {
            if (data == root->data)
            {
                curNode = root;
                return true;
            }
            if (data > root->data)
                return find(data, root->right);
            else
                return find(data, root->left);
        }
        return false;
    }
    int max(int data)
    {
        if (find(data))
        {
            while (curNode->right)
            {
                curNode = curNode->right;
            }
            return curNode->data;
        }
        return INT32_MIN;
    }
    int min(int data)
    {
        if (find(data))
        {
            while (curNode->left)
            {
                curNode = curNode->left;
            }
            return curNode->data;
        }
        return INT32_MAX;
    }
    int predecessor(int data)
    {
        if (find(data))
        {
            return max(min(data));
        }
        return INT32_MAX;
    }
    int successor(int data)
    {
        if (find(data))
        {
            return min(max(data));
        }
        return INT32_MIN;
    }
    Node *rotateRight(Node *root = sp_root)
    {
        Node *temp = root->left;
        root->left = temp->right;
        temp->right = root;
        temp->parent = root->parent;
        root->parent = temp;
        return temp;
    }
    Node *rotateLeft(Node *root = sp_root)
    {
        Node *temp = root->right;
        root->right = temp->left;
        temp->left = root;
        temp->parent = root->parent;
        root->parent = temp;
        return temp;
    }
    Node *reBalance(Node *root = sp_root)
    {
        int l_slop = slop(root->data);
        Node *temp = root;
        if (l_slop == 2)
        {
            if (slop(root->left->data) == -1)
                temp = rotateLeft(root->left);
            temp = rotateRight(root);
        }
        else if (l_slop == -2)
        {
            if (slop(root->right->data) == 1)
                temp = rotateRight(root->right);
            temp = rotateLeft(root);
        }
        return temp;
    }
};
BST::Node *BST::sp_root = nullptr;
int main()
{
    BST *tree = new BST();
    // cout << tree->height() << endl;
    tree->insert(4);
    tree->insert(6);
    tree->insert(8);
    // tree->insert(3);
    // tree->insert(7);
    // tree->insert(11);
    tree->inOrder();
    // tree->rotateRight();
    // tree->rotateLeft();
    // tree->inOrder();
    cout << tree->slop(8) << endl;

    // cout << tree->predecessor(10) << endl;
    // cout << tree->successor(10) << endl;
    // cout << tree->find(11) << endl;
    // cout << tree->find(15) << endl;
    // cout << tree->max(10) << endl;
    // cout << tree->min(15) << endl;
    return 0;
}