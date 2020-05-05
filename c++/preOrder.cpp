#include <iostream>
#include <vector>
using namespace std;

typedef struct treeNode
{
    int value;              /* value of the node */
    struct treeNode *left;  /* pointer to the left child node */
    struct treeNode *right; /* pointer to the right child node */
} treeNode;
// namespace std have been included for this problem.

vector<int> preordered_list;
// Add any helper functions(if needed) below.

// Add any helper functions(if needed) above.
void preorder(treeNode *root)
{
    if (root)
    {
        preordered_list.push_back(root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
bool validate_bst_until(treeNode *root, int min, int max)
{
    if (!root)
        return true;
    if (root->data < min || root->data > max)
        return false;
    return validate_bst_until(root->left, min, root->value - 1) &&
           validate_bst_until(root->right, root->value + 1, max);
}
bool validate_bst(treeNode *root)
{
    return validate_bst_until(root, INT32_MIN, INT32_MAX);
}
int main()
{
    return 0;
}