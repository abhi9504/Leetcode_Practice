class Solution {
public:
    int dfs(int i, int j, int cnt, vector<vector<char>>& board, string word) {
        // Base Case
        if(word.size() == cnt)  return true;
        // check outofBound condition
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#'|| board[i][j] != word[cnt]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '#';  // visited mark ho gaya

        bool ans = dfs(i, j+1, cnt+1, board, word)||   // right 
                   dfs(i, j-1, cnt+1, board, word)||   //  left
                   dfs(i-1, j, cnt+1, board, word) ||  // up
                   dfs(i+1, j, cnt+1, board, word);     // down

         // BackTrack # ko original char se replace kro
         board[i][j] = temp;

         return ans;          
    }
    bool exist(vector<vector<char>>& board, string word) {
       // Q2. Day-6/30
       int n = board.size();
       int m = board[0].size();
       for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == word[0] && dfs(i, j, 0, board, word)) {
                return true;
            }
        }
       } 
       return false;
    }
};