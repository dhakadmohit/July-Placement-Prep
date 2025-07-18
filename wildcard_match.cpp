class Solution {
public:
    bool solve(int idx1, int idx2, string &s, string &p,vector<vector<int>> &dp){
        //base case
        if(idx2 < 0 && idx1 < 0) return true;
        if(idx2 < 0 && idx1 >= 0) return false;

        if(idx1 < 0 and idx2 >= 0){
            for(int i = 0; i <= idx2; i++){
                if(p[i] != '*') return false;
            }
            return true;
        }

        if(dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }


        if((s[idx1] == p[idx2]) || (p[idx2] == '?')){
            return dp[idx1][idx2] =  solve(idx1-1,idx2-1,s,p,dp);
        }

        else if(p[idx2] == '*'){
            return dp[idx1][idx2] = solve(idx1,idx2-1,s,p,dp) || solve(idx1-1,idx2,s,p,dp);
        }

        return dp[idx1][idx2] = false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(),vector<int> (p.length(),-1));
        return solve(s.length()-1,p.length()-1,s,p,dp);
    }
};