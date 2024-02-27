 
 #include <bits/stdc++.h>
using namespace std;

//similar question : Kth element of 2 sorted arrays
 
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);

        int lo=0;
        int hi=n1;
        int ll = (n1+n2+1)/2;
        while(lo<=hi){
           int mid1 = (lo+hi)/2 ;
           int mid2 = ll - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

           if(mid1 < n1) r1 = nums1[mid1];
           if(mid2 < n2) r2 = nums2[mid2];
           if(mid1-1 >= 0) l1 = nums1[mid1-1];
           if(mid2-1 >= 0) l2 = nums2[mid2-1];

           if(max(l1,l2)<=min(r1,r2)){
               if((n1+n2) % 2 == 1) return max(l1,l2);
               else return ((double)(max(l1,l2)+min(r1,r2)))/2.0 ;
           }else if(l1 > r2){
               hi= mid1-1;
           }else{
               lo = mid1+1;
           }
        }
        return 0;
    }


int main(){
    vector<int> nums1({1,2});
    vector<int> nums2({3,4});
    cout<<findMedianSortedArrays(nums1,nums2)<<endl;
}