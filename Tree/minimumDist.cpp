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
Node *lca_nodes(Node *root, int a, int b)
{
   if (root == NULL || root->data == a || root->data == b)
   {
      return root;
   }
   Node *left = lca_nodes(root->left, a, b);
   Node *right = lca_nodes(root->right, a, b);
   if (left == NULL)
      return right;
   if (right == NULL)
      return left;
   return root;
}
int findDist(Node *root, int a, int b)
{
   // Your code here
   Node *lca = lca_nodes(root, a, b);
   unordered_map<int, int> mpp;
   queue<pair<Node *, int>> q;

   q.push({root, 0});
   while (!q.empty())
   {
      Node *curr = q.front().first;
      int level = q.front().second;
      q.pop();
      mpp[curr->data] = level;
      if (curr->left)
      {
         q.push({curr->left, level + 1});
      }
      if (curr->right)
      {
         q.push({curr->right, level + 1});
      }
   }
   // cout<<lca->data<<endl;
   return abs(mpp[lca->data] - mpp[a]) + abs(mpp[lca->data] - mpp[b]);
}
int main()
{

   return 0;
}