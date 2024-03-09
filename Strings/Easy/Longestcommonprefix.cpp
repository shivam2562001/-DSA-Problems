#include <bits/stdc++.h>
using namespace std;
  
  /*
  Intuition : when sorting array of string then there will be  various consecutive group forms which as some prefix common.
              The string that has more matching prefix comes closer.
              ex = ["cgh","abc","cg","abd","ck","a",]  ===> ["a","abc","abd","cg","cgh","ck"]
  Approach:
    1.) sort vector
    2.) pick first and last element match and get prefix
  */
  string longestCommonPrefix(vector<string>& v) {
        string ans="";
        sort(v.begin(),v.end());
        int n=v.size();
        string first=v[0],last=v[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){
                return ans;
            }
            ans+=first[i];
        }
        return ans;
 }
 //complexity: O(nlogn) where n is vector length

int main(){
    int x;
    cin >> x;
    cout << "hey" <<x;
}