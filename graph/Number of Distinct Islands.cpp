
/*उद्यमेन हि सिध्यन्ति कार्याणि न मनोरथैः।*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> grid, vector<vector<int>> &vis, int row0, int col0, vector<pair<int, int>> &tp)
{
   int movx[] = {-1, 0, 1, 0};
   int movy[] = {0, 1, 0, -1};
   int n = grid.size();
   int m = grid[0].size();
   if (row < 0 || row >= n || row < 0 || col >= m)
      return;
   if (vis[row][col])
      return;
   vis[row][col] = 1;
   int n = grid.size();
   int m = grid[0].size();
   tp.push_back({row - row0, col - col0});
   for (int i = 0; i < 4; i++)
   {
      int dr = row + movx[i];
      int dc = col + movy[i];
      if (dr >= 0 && dr < n && dc >= 0 && dc < m && (!vis[dr][dc]) && grid[dr][dc] == 1)
      {
         dfs(dr, dc, grid, vis, row0, col0, tp);
      }
   }
}
int countDistinctIslands(vector<vector<int>> &grid)
{
   set<vector<pair<int, int>>> st;
   int n = grid.size();
   int m = grid[0].size();
   vector<vector<int>> vis(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         if (!vis[i][j] && grid[i][j] == 1)
         {
            vector<pair<int, int>> ans;
            dfs(i, j, grid, vis, i, j, ans);
            st.insert(ans);
         }
      }
   }
   return st.size();
}
int main()
{

   return 0;
}