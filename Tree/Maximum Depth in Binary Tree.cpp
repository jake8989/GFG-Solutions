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
int height(struct Node *node)
{
   // code here
   if (node == NULL)
      return 0;
   int left = height(node->left);
   int right = height(node->right);
   return 1 + max(left, right);
}
int main()
{

   return 0;
}