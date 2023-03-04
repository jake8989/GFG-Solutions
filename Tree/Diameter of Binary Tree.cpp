/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
// diameter = longest path b / w any two nodes;
// no. of nodes b/w longest path
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
      this->left = this->right = NULL;
   }
};
int height(int &ans, Node *root)
{
   if (root == NULL)
      return 0;
   int lh = height(ans, root->left);
   int rh = height(ans, root->right);
   ans = max(ans, lh + rh);
   return 1 + max(lh, rh);
}
int diameter(Node *root)
{
   // Your code here
   int ans = INT_MIN;
   height(ans, root);
   return ans;
}
int main()
{

   return 0;
}