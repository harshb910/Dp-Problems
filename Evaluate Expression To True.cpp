// Given an expression, A, with operands and operators (OR , AND , XOR), in how many ways can you evaluate the expression to true, by grouping in different ways?

// Operands are only true and false.

// Return the number of ways to evaluate the expression modulo 103 + 3.
// 1 <= length(A) <= 150
// Input 1:
//     A = "T|F"

// Output 1:
//     1

// Explanation 1:
//     The only way to evaluate the expression is:
//         => (T|F) = T 

// Input 2:
//     A = "T^T^F"
    
// Output 2:
//     0
    
// Explanation 2:
//     There is no way to evaluate A to a true statement.
//Code:
int static dp[151][151][2];
int solve(string str, int i, int j, int istrue)
    {
        if(i>j)return 0;
        if(i==j)
        {
            if(istrue)return str[i]=='T';
            else return str[i]=='F';
        }
        if(dp[i][j][istrue]!=-1)
        return dp[i][j][istrue];
        
        int ans=0;
        
        for(int k=i+1;k<=j-1;k=k+2)
        {
            int leftT,leftF,rightT,rightF;
            
            if(dp[i][k-1][1]==-1){
                leftT=solve(str,i,k-1,1);
                dp[i][k-1][1] = leftT;
            }
            else leftT=dp[i][k-1][1];
            
            if(dp[i][k-1][0]==-1){
                leftF=solve(str,i,k-1,0);
                dp[i][k-1][0]=leftF;
            }
            else leftF=dp[i][k-1][0];
            
            if(dp[k+1][j][1]==-1){
                rightT=solve(str,k+1,j,1);
                dp[k+1][j][1]=rightT;
            }
            else rightT=dp[k+1][j][1];
            
            if(dp[k+1][j][0]==-1){
                rightF=solve(str,k+1,j,0);
                dp[k+1][j][0]=rightF;
            }
            else rightF=dp[k+1][j][0];
            
            if(str[k]=='^')
            {
                if(istrue)
                ans+=(leftT*rightF) + (leftF*rightT);
                else ans+=(leftT*rightT) + (leftF*rightF) ;
            }
            else if(str[k]=='&')
            {
                if(istrue)
                ans+=(leftT*rightT);
                else ans+=(leftT*rightF) + (leftF*rightT) + (leftF*rightF);
            }
            else if(str[k]=='|')
            {
                if(istrue)
                ans+=(leftT*rightF) + (leftF*rightT) + (leftT*rightT);
                else ans+=(leftF*rightF) ;
            }
            // dp[i][j][istrue]=ans%1003;
        }
        return dp[i][j][istrue]=ans%1003;
    }
int Solution::cnttrue(string A) {
    memset(dp,-1,sizeof(dp));
    
    return solve(A,0,A.length()-1,true);
}
