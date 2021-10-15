// To Print Longest Common Subsequence
void printLCS(string a,string b){
   int m   = a.length();
   int n = b.length();
   int t[m+1][n+1];
  //Initialisation
   for(int i=0;i<(n+1);i++)t[0][i]=0;
   for(int i=0;i<(m+1);i++)t[i][0]=0;
  //Forming LCS Table
   for(int i=1;i<(m+1);i++){
       for(int j=1;j<(n+1);j++){
           if(a[i-1]==b[j-1]){
               t[i][j] = 1+ t[i-1][j-1];
           }else{
               t[i][j] = max(t[i-1][j], t[i][j-1]);
           }
       }
   }
  //For string LCS
   int i=m,j=n;
   string s="";
   while(i & j){
       if(a[i-1]==b[j-1]){
           s = a[i-1]+s;
           i--;j--;
       }else if(t[i-1][j]>t[i][j-1]){
           i--;
       }else{
           j--;
       }
   }
   cout<<s<<endl;
}

//Input: a: abcdgh
//       b: abedfhr

//Output: abdh
