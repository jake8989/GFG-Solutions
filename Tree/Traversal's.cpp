/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
   int data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int data)
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
};
void inorderTraversal(TreeNode *root)
{
   if (root == NULL)
   {
      return;
   }
   // inorderTraversal(root->left);
   // inorderTraversal(root->right);
   // cout << root->data << " ";
   // same we can do preorder/ postorder by changing the config.
}
int main()
{

   return 0;
}