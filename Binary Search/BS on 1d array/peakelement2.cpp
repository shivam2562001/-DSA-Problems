

 
 #include <bits/stdc++.h>
using namespace std;

//peak element 2d array

 vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int lo = 0; int hi = mat.size()-1;
        while(lo<=hi){
            int mid= (lo+hi)/2; 

            //to calculate max element index in row
            int r = distance(mat[mid].begin(),max_element(mat[mid].begin(),mat[mid].end()));
            // to find top and bottom
            int t = mid-1>=0 ? mat[mid-1][r] : -1;
            int b = mid+1<mat.size() ? mat[mid+1][r] : -1;
            
            if(t< mat[mid][r] && mat[mid][r] > b){
                return {mid,r};
            }else if(mat[mid][r] < b){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return {-1,-1};
    }



int main(){
    vector<vector<int>> nums1({{10,20,15},{21,30,14},{7,16,32}});
    cout<<findPeakGrid(nums1)[0]<<","<<findPeakGrid(nums1)[1];
}