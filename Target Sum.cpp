//Problem Statement
//You are given an integer array nums and an integer target.

///You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

//For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
//Return the number of different expressions that you can build, which evaluates to target.

int findTargetSumWays(vector<int>& nums, int target) {
        
         int sum =0,n = nums.size();
        
        for(auto x: nums)sum+=x;
        
        int s = abs(target + sum)/2;
        
        if((target+sum) % 2 != 0)
            return 0;  
        
         int dp[n+1][s+1];
        
     
      for(int i=1;i<s+1;i++) dp[0][i]=0;
      for(int i=0;i<n+1;i++) dp[i][0]=1;
        
        for(int i =1; i<n+1;i++){
            
            for(int j =0; j<s+1;j++){
                
                if(nums[i-1]<=j){
                    
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }else{
                    
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][s];
    
    }


// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
