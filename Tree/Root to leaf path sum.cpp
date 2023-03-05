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
bool check(Node *root, int t, int s)
{
   if (root->left == NULL && root->right == NULL)
   {
      return (s + root->data == t);
   }
   s += root->data;
   bool lh = check(root->left, t, s);
   bool rh = check(root->right, s, t);
   return lh && rh;
   s -= root->data;
}
bool hasPathSum(Node *root, int S)
{
   // Your code here
   int sum = 0;
   return check(root, S, sum);
}
int main()
{

   return 0;
}