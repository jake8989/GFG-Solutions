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
void leftWala(Node *root, vector<int> &ans)
{
   Node *curr = root->left;
   while (curr)
   {
      if (curr->left != NULL || curr->right != NULL)
      {
         ans.push_back(curr->data);
      }
      if (curr->left)
         curr = curr->left;
      else
      {
         curr = curr->right;
      }
   }
}
void rightWala(Node *root, vector<int> &ans)
{
   Node *curr = root->right;
   vector<int> ds;
   while (curr)
   {
      if (curr->left != NULL || curr->right != NULL)
      {
         ds.push_back(curr->data);
      }
      if (curr->right)
         curr = curr->right;
      else
      {
         curr = curr->left;
      }
   }
   for (int i = ds.size() - 1; i >= 0; i--)
   {

      ans.push_back(ds[i]);
   }
}
void leaf(Node *root, vector<int> &ans)
{
   Node *curr = root;

   if (curr->left == NULL && curr->right == NULL)
   {
      ans.push_back(curr->data);
   }
   if (curr->left)
      leaf(root->left, ans);
   if (curr->right)
   {
      leaf(root->right, ans);
   }
}
vector<int> boundary(Node *root)
{
   vector<int> ans;
   ans.push_back(root->data);
   leftWala(root, ans);
   leaf(root, ans);
   rightWala(root, ans);

   return ans;
}
int main()
{

   return 0;
}