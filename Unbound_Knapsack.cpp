#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:

    int solve(int idx, vector<int> &wt, vector<int> &val, int w){
        //base case
        if(idx == 0){
            return w/wt[0] * val[0];
        }
        int not_pick = 0 + solve(idx-1,wt,val,w);
        int pick = INT_MAX;

        if(wt[idx] <= w){
            pick = val[idx] + solve(idx-1,wt,val,w-wt[idx]);
        }
        return max(pick,not_pick);
    }

    int f(vector<int> wt,vector<int> val,int w){
        int n = 9;
        return solve(n-1,wt,val,w);
    }
};
