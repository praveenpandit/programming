// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }
    Node *lca(Node *root, int v1, int v2)
    {
        // Write your code here.
        if (!root)
            return nullptr;
        if (root->data == v1 || root->data == v2)
            return root;
        Node *lcaLeft = lca(root->left, v1, v2);
        Node *lcaRight = lca(root->right, v1, v2);
        if (lcaLeft && lcaRight)
            return root;
        return lcaLeft ? lcaLeft : lcaRight;
    }
    int height(Node *root)
    {
        // Write your code here.
        if (!root)
            return -1;
        else
            return 1 + std::max(height(root->left), height(root->right));
    }
    void checkBST(Node *root, bool *flag, int *a)
    {
        if (root)
        {
            if (root->data < *a)
                *flag = *flag && false;
            else
            {
                checkBST(root->left, flag, a);
                *a = root->data;
                checkBST(root->right, flag, a);
            }
        }
    }

}; //End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    // int height = myTree.height(root);

    // std::cout << height;
    // int v1, v2;
    // std::cin >> v1 >> v2;

    // Node *ans = myTree.lca(root, v1, v2);

    // std::cout << ans->data;
    bool flag = true;
    int min = INT32_MIN;
    myTree.checkBST(root, &flag, &min);
    std::cout << flag << endl;
    return 0;
}
