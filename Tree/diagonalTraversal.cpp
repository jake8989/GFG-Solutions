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

Struct
    vector<int>
    diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   queue<Node *> q;
   q.push(root);
   while (!q.empty())
   {
      Node *curr = q.front();
      q.pop();
      while (curr)
      {
         ans.push_back(curr->data);
         if (curr->left)
            q.push(curr->left);
         curr = curr->right;
      }
   }
   return ans;
}
int main()
{

   return 0;
}