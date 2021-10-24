//Given a string A, partition A such that every substring of the partition is a palindrome.

//Return the minimum cuts needed for a palindrome partitioning of A.
//1 <= length(A) <= 501
// Input 1:
//     A = "aba"

// Output 1:
//     0

// Explanation 1:
//     "aba" is already a palindrome, so no cuts are needed.

// Input 2:
//     A = "aab"
    
// Output 2:
//     1

// Explanation 2:
//     Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
//Code:
int static t[502][502];
bool isPalindrome(string s,int i,int j){
    if(i>=j)return true;
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;j--;
    }
    return true;
}
int solve(string s,int i,int j){
    if(i>=j)return 0;
    if(isPalindrome(s,i,j)==true)return 0;
    if(t[i][j]!=-1)return t[i][j];
    int mn = INT_MAX;
    for(int k=i;k<=j-1;k++){
        int left,right;
        if(t[i][k]!=-1)left = t[i][k];
        else {
            left = solve(s,i,k);
            t[i][k]=left;
        }
        if(t[k+1][j]!=-1)right = t[k+1][j];
        else {
            right = solve(s,k+1,j);
            t[k+1][j] = right;
        }
        int tmp = 1+left+right;
        mn = min(mn,tmp);
    }
    return t[i][j]=mn;
}
int Solution::minCut(string A) {
    int l = A.length();
    memset(t,-1,sizeof(t));
    return solve(A,0,l-1);
}
