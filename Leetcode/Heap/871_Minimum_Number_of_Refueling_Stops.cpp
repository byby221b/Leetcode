#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
/*
 *  Giggle
 *  2019-03-03 16:50:37
 */

struct cmp{ 
	bool operator ()(vector<int> &a,vector<int> &b){ 
		return a[1] < b[1];
	} 
}; 

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
 	int size = stations.size();
	long long *dp = new long long[size+1];
	for(int i=0;i<=size;i++){
	    dp[i] = startFuel;
	    cout << i << "\t" ;
	}
	
	cout << endl;
	
	for(int i=0;i<size;i++){
	    vector<int> tmp = stations[i];
	    for(int j=i;j>=0;j--){
	        if(dp[j]>=tmp[0]){
	            dp[j+1] = max(dp[j+1],dp[j]+tmp[1]);
	        }
	    }
	    
	    for(int i=0;i<=size;i++){
	    	cout << dp[i] << "\t";
		}
		cout << endl;
	}
	
	int i = 0;
	bool flag = false;
	
	for(;i<=size;i++){
	    if(dp[i]>=target){
	        flag = true;
	        break; 
	    }
	}
	
	return flag?i:-1;
}

int main(){
	vector<int> station0 {25,27};
	vector<int> station1 {36,187};
	vector<int> station2 {140,186};
	vector<int> station3 {378,6};
	vector<int> station4 {492,202};
	vector<int> station5 {517,89};
	vector<int> station6 {579,234};
	vector<int> station7 {673,86};
	vector<int> station8 {808,53};
	vector<int> station9 {954,49};
	vector<vector<int> > stations = {station0,station1,station2,station3,station4,station5,station6,station7,station8,station9};
	int target = 1000;
	int startFuel = 83;
	cout << minRefuelStops(target,startFuel,stations) <<endl;
	return 0;
}
