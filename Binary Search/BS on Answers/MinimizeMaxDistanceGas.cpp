
 #include <bits/stdc++.h>
using namespace std;

//decimal binary search question tricky

/*brute force*/
long double minimiseMaxDistanceBruteForce(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength =
                diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }

    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength =
            diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}


/*using priority queue*/
double minimiseMaxDistanceUsingPQ(vector<int> &arr, int k){
   int n= arr.size();
   vector<int> hm(n-1,0);
   priority_queue<pair<double, int>> pq;

   for(int i=0;i<n-1;i++){
	   pq.push({arr[i+1]-arr[i],i});
   }

   for(int g = 1; g<=k; g++){

	auto t = pq.top();
	pq.pop();
    int mi = t.second;

	hm[mi]++;

	double diff = arr[mi+1]-arr[mi];
	double sl = diff/(double)(hm[mi]+1);

	pq.push({sl,mi});

   }
   return pq.top().first;
}

/*using binary search*/
bool canPlaceGas(vector<int> &arr,double msl, int k){
   int n = arr.size();
   int cnt = 0;
   for(int i = 1 ; i<n;i++){
    /*find how many can be placed with msl distance between*/
     int placed = (arr[i]-arr[i-1])/msl; 
     /*for checking complete divison*/
     if(arr[i]-arr[i-1] == msl*placed){
        placed--;
     }
    cnt+=placed;
   }
   /*if all gas can be placed return true*/
  return cnt <= k;
}
double minimiseMaxDistanceUsingBS(vector<int> &arr, int k){
double lo = 0; double hi=0;
int n = arr.size();
for(int i=0;i<n-1;i++){
    hi = max(double(arr[i+1]-arr[i]),hi);
}

while(hi-lo > 1e-6){ 

    double mid = (lo+hi)/2.0;

    if(canPlaceGas(arr,mid,k)){
        hi= mid;
    }else{
        lo=mid;
    }

  return hi;
}




}
int main(){
    int x = 4;
    vector<int> nums({1,2, 3, 4,5});
    cout<<minimiseMaxDistanceUsingPQ(nums,x)<<endl;
    cout<<minimiseMaxDistanceBruteForce(nums,x)<<endl;
    cout<<minimiseMaxDistanceUsingBS(nums,x)<<endl;
}