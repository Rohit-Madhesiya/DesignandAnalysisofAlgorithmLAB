#include <iostream>
void swap(int, int);
class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) {
    this->val = val;
    left = NULL;
    right = NULL;
  }
  TreeNode insert(TreeNode *root, int data) {
    TreeNode temp(data);
    if (root == NULL)
      return temp;
  }
  void minHeapify(TreeNode *root) {
    TreeNode *smallest = root;
    TreeNode *left = root->left;
    TreeNode *right = root->right;

    if (left != NULL && left->val < smallest->val)
      smallest = left;

    if (right != NULL && right->val < smallest->val)
      smallest = right;

    if (smallest != root) {
      swap(root->val, smallest->val);
      minHeapify(smallest);
    }
  }
};
int main() {}