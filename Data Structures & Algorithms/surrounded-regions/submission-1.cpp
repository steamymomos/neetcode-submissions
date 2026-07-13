class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>> q;
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') {
                q.push({0,j});
                board[0][j] = '#';
            }
            if(board[n-1][j] == 'O') {
                q.push({n-1,j});
                board[n-1][j] = '#';
            }
        }
        for(int i = 1; i < n-1; i++) {
            if(board[i][0] == 'O') {
                q.push({i,0});
                board[i][0] = '#';
            }
            if(board[i][m-1] == 'O') {
                q.push({i,m-1});
                board[i][m-1] = '#';
            }
        }
        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();

            for(auto &d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   board[nr][nc] == 'O') {

                    board[nr][nc] = '#';
                    q.push({nr,nc});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};