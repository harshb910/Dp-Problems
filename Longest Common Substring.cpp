//Longest Common Substring(Dynamic Programming)
//Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
//Examples:

//Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
//Output : 5
//The longest common substring is “Geeks” and is of length 5.
int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int t[n+1][m+1];
        for(int i=0;i<(m+1);i++)t[0][i]=0;
        for(int i=0;i<(n+1);i++)t[i][0]=0;
        int length=0;
        for(int i=1;i<(n+1);i++){
            for(int j=1;j<(m+1);j++){
                if(S1[i-1]==S2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                    length = max(length,t[i][j]);
                }else{
                    t[i][j]=0;
                }
            }
        }
        return length;
    }
