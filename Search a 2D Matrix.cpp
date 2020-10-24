class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int m=matrix.size(), n=matrix[0].size();
        for(int l=0,r=m*n;l<r;) {
            int md = (l+r)/2;
            int a = matrix[md/n][md%n];
            if(a==target) return true;
            else if(a<target) l=md+1;
            else r=md;
        }
        return false;
    }
};
