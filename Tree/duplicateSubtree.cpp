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
string solve(Node *&root, vector<Node *> &ans, unordered_map<string, int> &mpp)
{
   if (root == NULL)
   {
      return "";
   }
   string path = "(";
   path += solve(root->left, ans, mpp);
   path += to_string(root->data);
   path += solve(root->right, ans, mpp);
   path += ")";
   if (mpp[path] == 1)
   {
      ans.push_back(root);
   }
   mpp[path]++;
   return path;
}
vector<Node *> printAllDups(Node *root)
{
   // Code here
   vector<Node *> ans;
   unordered_map<string, int> mpp;
   solve(root, ans, mpp);
   return ans;
}
int main()
{

   return 0;
}