// geeks for geeks -> coin change

long long int count(int coins[], int N, int sum) {
        
        vector<long long> dp(sum+1, 0);
        vector<long long> temp(sum+1, 0);
        
        for(long long i=0;i<=sum;i++){
            if(i%coins[0]==0){
                dp[i] = 1;
            }
        }
        
        for(int ind=1;ind<N;ind++){
            for(long long amt=0;amt<=sum;amt++){
                long long pick = 0, notPick = dp[amt];
                if(amt>=coins[ind]){
                  pick = temp[amt-coins[ind]];
                }
                temp[amt] = pick+notPick;
            }
        dp=temp;
        }
        return dp[sum];
    }