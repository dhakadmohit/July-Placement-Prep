#include<bits/stdc++.h>
using namespace std;
class solution{
    public:

    int solve(int idx,vector<int> &temp){
        //base case
        if(idx == 1){
            return 0;
        }
        if(idx == 0) return 0;

        int left = solve(idx - 1,temp) + abs(temp[idx] - temp[idx - 1]);
        int right = solve(idx - 2,temp) + abs(temp[idx] - temp[idx - 2]);

        return min(left,right);
    }
};