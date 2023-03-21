/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
public:
   char data;
   TrieNode *childerns[26];
   bool isLeaf;
   int childCount = 0;
   TrieNode(char d)
   {
      data = d;
      for (int i = 0; i < 26; i++)
      {
         childerns[i] = NULL;
      }
      isLeaf = false;
   }
};

class Trie
{
public:
   TrieNode *root;
   Trie()
   {
      root = new TrieNode('$');
   }
   TrieNode *child = root;
   void insertUtil(TrieNode *root, string key)
   {
      if (key.length() == 0)
      {
         root->isLeaf = 1;
         return;
      }
      TrieNode *child;
      int index = key[0] - 'a';
      if (root->childerns[index] != NULL)
      {
         child = root->childerns[index];
      }
      else
      {
         child = new TrieNode(key[0]);
         root->childCount++;
         root->childerns[index] = child;
      }
      insertUtil(child, key.substr(1));
   }
   void insert(string key)
   {
      insertUtil(root, key);
   }
   bool searchUtil(TrieNode *root, string key)
   {
      if (key.length() == 0)
         return root->isLeaf;

      TrieNode *child;
      int index = key[0] - 'a';
      if (root->childerns[index] != NULL)
      {
         child = root->childerns[index];
      }
      else
      {
         return false;
      }
      return searchUtil(child, key.substr(1));
   }
   bool search(string key)
   {
      return searchUtil(root, key);
   }
   void lcp(string str, string &ans)
   {
      for (int i = 0; i < str.length(); i++)
      {
         char ch = str[i];
         int index = ch - 'a';
         if (root->childCount == 1)
         {
            ans.push_back(ch);
            root = root->childerns[index];
         }
         else
         {
            break;
         }
         if (root->isLeaf)
            break;
      }
   }
};
int main()
{
   Trie *t = new Trie();
   t->insert("jakei");
   string ans = "";
   cout << t->search("jake");
   return 0;
}