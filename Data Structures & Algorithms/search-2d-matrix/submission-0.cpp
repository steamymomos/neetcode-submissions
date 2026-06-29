class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0,in=matrix.size()-1,j=0,jn=matrix[0].size()-1;
        int n=matrix.size();
        int mid=(i+in)/2;
        int midj=(j+jn)/2;
        while(i<=in){
            if(matrix[mid][j]==target)return true;
            else if(matrix[mid][j]>target)in=mid-1;
            else i=mid+1;
            mid=(i+in)/2;
        }
        while(j<=jn){
            if(matrix[mid][midj]==target)return true;
            else if(matrix[mid][midj]>target)jn=midj-1;
            else j=midj+1;
            midj=(j+jn)/2;
        }
        return false;

    }
};
