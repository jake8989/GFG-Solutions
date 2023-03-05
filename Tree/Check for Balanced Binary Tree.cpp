
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
int check(Node *root)
{
   if (root == NULL)
      return 0;

   int lh = check(root->left);

   int rh = check(root->right);
   if (rh == -1 || lh == -1)
      return -1;

   if (abs(lh - rh) > 1)
      return -1;
   return 1 + max(lh, rh);
}
bool isBalanced(Node *root)
{
   //  Your Code here
   if (check(root) == -1)
      return false;
   return true;
}
int main()
{

   return 0;
}