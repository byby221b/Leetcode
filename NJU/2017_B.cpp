/*
	Name: 
	Copyright: 
	Author: 
	Date: 27/06/19 13:45
	Description: BFS
*/

#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
  		int size = nums.size();
		if(size <= 1)      {
  			return true;
		}
		
		bool *mark = new bool[size+5];
		
		for(int i=0;i<size;i++){
			mark[i] = false;
		}
		
		queue<int> q;
		mark[0] = true;
		q.push(0);
		
		bool flag = false;
		
		while(!q.empty() && !flag){
			int curr_node = q.front();
			q.pop();
			
			for(int i=1;i<=nums[curr_node];i++){
				if(curr_node+i == size - 1){
					flag = true;
					break;
				}
				if(curr_node+i<size && !mark[curr_node+i]){
					q.push(curr_node+i);
					mark[curr_node+i] = true;
				}
			}
		}
		
		delete [] mark;
		return flag;
		
    }
};

int main(){
//	vector<int> test = {2,3,1,1,4};
	vector<int> test = {3,2,1,0,4};
	
	Solution su = Solution();
	string res;
	if(su.canJump(test)){
		res = "true";
	}else{
		res = "false";
	}
	cout << res << endl;
	return 0;
}

 

