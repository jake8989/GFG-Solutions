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
bool isIdentical(Node *r1, Node *r2)
{
   // Your Code here
   if (r1 == NULL && r2 != NULL)
      return false;
   if (r1 != NULL && r2 == NULL)
      return false;
   if (r1 == NULL && r2 == NULL)
      return true;
   if (r1->data != r2->data)
      return false;
   bool l = isIdentical(r1->left, r2->left);
   bool r = isIdentical(r1->right, r2->right);
   if (l && r)
      return true;
   return false;
}
int main()
{

   return 0;
}