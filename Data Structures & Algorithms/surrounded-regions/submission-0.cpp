class Solution {
public:
    vector<vector<int>> d={{0,1},{1,0},{0,-1},{-1,0}};
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        set<pair<int,int>> s;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                s.insert({0,i});
            }
            if(board[n-1][i]=='O'){
                q.push({n-1,i});
                s.insert({n-1,i});
            }
        }
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                s.insert({i,0});
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                s.insert({i,m-1});
            }
        }
        while(!q.empty()){
            auto a=q.front();
            q.pop();
            int f=a.first;
            int se=a.second;
            for(int i=0;i<4;i++){
                if(s.count({f+d[i][0],se+d[i][1]})==0 && f+d[i][0]>=0 && se+d[i][1]>=0 && f+d[i][0]<=n-1 && se+d[i][1]<=m-1 && board[f+d[i][0]][se+d[i][1]]=='O'){
                    q.push({f+d[i][0],se+d[i][1]});
                    s.insert({f+d[i][0],se+d[i][1]});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s.count({i,j})==0)board[i][j]='X';
            }
        }
    }
};
