class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int count=0;
        while(!q.empty()) {
            int sz=q.size();
            int flag=0;
            while(sz--){
                auto [r, c] = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if(nr >= 0 && nr < m &&
                    nc >= 0 && nc < n &&
                    grid[nr][nc] == 1) {  
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        flag=1;
                    }
                }
            }
            if(flag==1)count++;
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2 || grid[i][j]==0) {
                    continue;
                }
                else return -1;
            }
        }
        return count;
    }
};