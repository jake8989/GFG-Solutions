/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> grid)
{
   int n = grid.size();
   int m = grid[0].size();
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   if (row < 0 || row >= n || col < 0 || col >= m)
      return;
   if (vis[row][col])
      return;
   vis[row][col] = 1;
   for (int i = 0; i < 4; i++)
   {
      int dr = row + movx[i];
      int dc = col + movy[i];
      if (grid[dr][dc] == 1)
      {
         dfs(dr, dc, vis, grid);
      }
   }
}
int numberOfEnclaves(vector<vector<int>> &grid)
{
   // Code here
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
         {
            if (grid[i][j] == 1 && (!vis[i][j]))
            {
               queue<pair<int, int>> q;
               int movx[] = {-1, 0, 1, 0};
               int movy[] = {0, 1, 0, -1};
               q.push({i, j});
               vis[i][j] = 1;
               while (!q.empty())
               {
                  int row = q.front().first;
                  int col = q.front().second;
                  q.pop();
                  for (int i = 0; i < 4; i++)
                  {
                     int dr = row + movx[i];
                     int dc = col + movy[i];
                     if (dr >= 0 && dr < n && dc >= 0 && dc < m && (!vis[dr][dc]) && grid[dr][dc] == 1)
                     {
                        q.push({dr, dc});
                        vis[dr][dc] = 1;
                     }
                  }
               }
            }
         }
      }
   }
   int cnt = 0;
   //     for (int i = 0; i < n; i++)
   //   {
   //       for (int j = 0; j < m; j++)
   //       {
   //         cout<<vis[i][j]<<" ";
   //       }
   //       cout<<endl;
   //   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (grid[i][j] == 1 && (!vis[i][j]))
            cnt++;
      }
   }
   return cnt;
}
int main()
{

   return 0;
}