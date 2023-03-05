/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *left;
   Node *right;
   Node(int data)
   {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
   }
};
bool help(Node *l, Node *r)
{
   if (l == NULL && r == NULL)
      return true;
   if (l == NULL && r != NULL)
      return false;
   if (l != NULL && r == NULL)
      return false;
   if (l->data != r->data)
      return false;
   bool lh = help(l->left, r->right);
   bool rh = help(l->right, r->left);
   return lh && rh;
}
// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node *root)
{
   // Code here
   if (root == NULL)
      return true;
   return help(root->left, root->right);
}
int main()
{

   return 0;
}