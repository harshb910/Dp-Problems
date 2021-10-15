//Shortest Common Supersequence(SCS)
//Given two strings str1 and str2, find the shortest string that has both str1 and str2 as subsequences.
//Examples:

//Input:   str1 = "geek",  str2 = "eke"
//Output: 5 , "geeke"
//For length
// SCS length = length(str1) + length(str2) - LCS length
//here SCS length = 4 + 3 - 2 = 5
int SCSlength(string a, string b){
  int m   = a.length();
   int n = b.length();
   int t[m+1][n+1];
   for(int i=0;i<(n+1);i++)t[0][i]=0;
   for(int i=0;i<(m+1);i++)t[i][0]=0;
   for(int i=1;i<(m+1);i++){
       for(int j=1;j<(n+1);j++){
           if(a[i-1]==b[j-1]){
               t[i][j] = 1+ t[i-1][j-1];
           }else{
               t[i][j] = max(t[i-1][j], t[i][j-1]);
           }
       }
   }
   int lcsLength = t[m][n];
  return (m + n - lcsLength);
}


//For string
//we get SCS string by combining string a and b such that LCS string comes only once
string LCSstring(string a,string b){
   int m   = a.length();
   int n = b.length();
   int t[m+1][n+1];
   for(int i=0;i<(n+1);i++)t[0][i]=0;
   for(int i=0;i<(m+1);i++)t[i][0]=0;
   for(int i=1;i<(m+1);i++){
       for(int j=1;j<(n+1);j++){
           if(a[i-1]==b[j-1]){
               t[i][j] = 1+ t[i-1][j-1];
           }else{
               t[i][j] = max(t[i-1][j], t[i][j-1]);
           }
       }
   }
   //cout<<t[m][n]<<endl;
   int i=m,j=n;
   string s="";
   while(i>0 & j>0){
       if(a[i-1]==b[j-1]){
           s = a[i-1]+s;
           i--;j--;
       }else if(t[i-1][j]>t[i][j-1]){
           i--;
       }else{
           j--;
       }
   }
   //cout<<s<<endl;
   return s;
}
//here c = LCSstring(a,b)
string SCSstring(string a,string b,string c){
     string s="";
     int m=a.length(),n=b.length(),o=c.length();
     int i=0,j=0,k=0;
     while(i<m && j<n && k<o){
          if(a[i]==c[k] && b[j]==c[k]){
               s += a[i];
               i++;
               j++;
               k++;
          }else if(a[i]==c[k] && b[j]!=c[k]){
               s+=b[j];
               j++;
          }else if(a[i]!=c[k] && b[j]==c[k]){
               s+=a[i];
               i++;
          }else {
               s+=a[i];i++;
               s+=b[j];j++;
          }
     }
     while(i<m){
          s+=a[i];
          i++;
     }
     while(j<n){
          s+=b[j];
          j++;
     }
     return s;
}
