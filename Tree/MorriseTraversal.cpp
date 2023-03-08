
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

vector<int> inOrder(Node *root)
{
   vector<int> ans;
   /// mmm traversal
   Node *curr = root;
   while (curr != NULL)
   {
      /* code */
      Node *curr = root;
      if (curr->left == NULL)
      {
         ans.push_back(curr->data);
         curr = curr->right;
      }
      else
      {
         Node *prev = curr->left;
         while (prev->right && prev->right != curr)
         {
            prev = prev->right;
         }
         if (prev->right == NULL)
         {
            prev->right = curr;
            curr = curr->left;
         }
         else
         {
            prev->right = NULL;
            ans.push_back(curr->data);
            curr = curr->right;
         }
      }
   }

   return ans;
}
int main()
{

   return 0;
}