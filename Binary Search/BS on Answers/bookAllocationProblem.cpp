
 #include <bits/stdc++.h>
using namespace std;

//Most common template for binary search 
//same problem painter partition, split array largest summ, aggressive crow
// BS on Answers
 bool isPossible(vector<int>& nums, int k,int max_sum){
          int sum = 0;
          int cnt =1;
        for(auto a : nums){
          if(sum+a > max_sum){
           cnt++;
           sum= a;
          }else{
              sum+=a;
          }
        }
     return cnt <=k ;
    }


int findLargestMinDistance(vector<int> &nums, int k)
{
      int lo=*max_element(nums.begin(),nums.end());
         int hi = accumulate(nums.begin(),nums.end(),0);

         while(lo<=hi){
             int mid = lo + (hi-lo)/2;

             if(isPossible(nums,k,mid)){
                 hi = mid-1;
             }else{
                 lo= mid+1;
             }
         }


      return lo;
}

/* 4 2
nums : 10 20 30 40
 */
int main(){
    int x = 2;
    vector<int> nums({10,20, 30, 40});
    cout<<findLargestMinDistance(nums,x)<<endl;;
}