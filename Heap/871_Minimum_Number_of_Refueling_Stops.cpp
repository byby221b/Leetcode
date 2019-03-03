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
	vector<int> virtual_station = {target,0};
    stations.push_back(virtual_station);
    
    int currPosi = 0,currFuel = startFuel;
    int count = 0;
    priority_queue<vector<int>,vector<vector<int> >,cmp> q;
    for(int i=0;i<stations.size();i++){
        vector<int> tmp_station = stations[i];
        
        while(currFuel<tmp_station[0]-currPosi && !q.empty()){
            vector<int> max_station = q.top();
            q.pop();
            currFuel += max_station[1];
            count ++;
        }
        
        if(currFuel<tmp_station[0]-currPosi){
            return -1;
        }
        
        
        currFuel -= (tmp_station[0] - currPosi);
        currPosi = tmp_station[0];
        q.push(tmp_station);
    }
    
    
    return count;
}

int main(){
	vector<int> station0 {13,21};
	vector<int> station1 {26,115};
	vector<int> station2 {100,47};
	vector<int> station3 {225,99};
	vector<int> station4 {299,141};
	vector<int> station5 {444,198};
	vector<int> station6 {608,190};
	vector<int> station7 {636,157};
	vector<int> station8 {647,255};
	vector<int> station9 {841,123};
	vector<vector<int> > stations = {station0,station1,station2,station3,station4,station5,station6,station7,station8,station9};
	int target = 1000;
	int startFuel = 299;
	cout << minRefuelStops(target,startFuel,stations) <<endl;
	return 0;
}
