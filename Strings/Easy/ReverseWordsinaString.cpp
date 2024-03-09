  #include <bits/stdc++.h>
using namespace std;
  
  /* 
   bruteForceAprroach: use stack to reverse

   optimal Approach: iterate linear use two pointer
    1.) set first pointer at the starting of word in a string(stop where you find not space)
    2.) set second pointer at the end of word in a string (stop where you find space)
    3.) substring the word and add in result straight if result is empty
    4.) otherwise add in result = sub + " " + result (for reversing string)
    
  */
  string reverseWords(string s) {
         int i=0,n=s.length();
         string result;
          while(i<n){
              while(i<n && s[i] ==' ') i++;
              if(i>=n) break;
              int j=i+1;
              while(j<n && s[j]  !=' ') j++;
              string sub = s.substr(i,j-i);
              if(result.length()==0) result=sub;
              else result=sub+" "+ result;
              i=j+1; 
          }


        return result;
    }