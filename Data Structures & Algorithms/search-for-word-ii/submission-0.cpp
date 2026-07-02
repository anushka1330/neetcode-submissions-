class Solution {
public:
    bool dfs(vector<vector<char>>& b, string &w, int i, int j, int k){
        if(k==w.size()) return true;
        if(i<0||j<0||i>=b.size()||j>=b[0].size()||b[i][j]!=w[k]) return false;

        char c=b[i][j];
        b[i][j]='#';

        bool f=dfs(b,w,i+1,j,k+1)||dfs(b,w,i-1,j,k+1)||
               dfs(b,w,i,j+1,k+1)||dfs(b,w,i,j-1,k+1);

        b[i][j]=c;
        return f;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        for(string &w:words){
            bool ok=false;
            for(int i=0;i<board.size()&&!ok;i++){
                for(int j=0;j<board[0].size()&&!ok;j++){
                    if(dfs(board,w,i,j,0)){
                        ans.push_back(w);
                        ok=true;
                    }
                }
            }
        }
        return ans;
    }
};