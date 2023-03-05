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
      this->left = this->right = NULL;
   }
};
int solve(Node *root, int &maxi)
{
   if (root == NULL)
      return 0;
   int leftSum = max(0, findMaxSum(root->left));
   int rightSum = max(0, findMaxSum(root->right));
   maxi = max(root->data + leftSum + rightSum, maxi);
   return root->data + max(leftSum, rightSum);
}
int findMaxSum(Node *root)
{
   // Your code goes here
   int maxi = INT_MIN; /// line is imp.
   solve(root, maxi);
   return maxi;
}
int main()
{

   return 0;
}