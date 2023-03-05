/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
   int n = image.size();
   int m = image[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   vis[sr][sc] = 1;
   queue<pair<int, int>> q;
   int color = image[sr][sc];
   q.push({sr, sc});
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   while (!q.empty())
   {
      /* code */
      int row = q.front().first;
      int col = q.front().second;

      q.pop();
      for (int i = 0; i < 4; i++)
      {
         int dr = row + movx[i];
         int dc = col + movy[i];
         if (dr >= 0 && dr < n && dc >= 0 && dc < m && (image[dr][dc] == color) && (!vis[dr][dc]))
         {
            q.push({dr, dc});
            image[row][col] = newColor;
            vis[dr][dc] = 1;
         }
      }
   }
}
int main()
{

   return 0;
}