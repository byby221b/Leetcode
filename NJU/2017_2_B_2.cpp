/*
	Name: 
	Copyright: 
	Author: 
	Date: 27/06/19 21:18
	Description: 树状数组，先固定最大边，然后计算大于最大边的数目 
*/

#include <iostream>
#include <algorithm> 

using namespace std;


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
  		int size = nums.size();
  		if(size<3){
  			return 0;
		}
		
		bitAttr = new int[2005];
		
		for(int i=1;i<2005;i++){
			bitAttr[i] = 0;
		}
		
		sort(nums.begin(),nums.end());
		
		int res = 0;
		for(int i=0;i<size;i++){
			res += rangeSum(nums[i],2*nums[i]+1);
			
			for(int j=0;j<i;j++){
				update(nums[j]+nums[i],1);
			}
		}
		
		delete [] bitAttr;
		
//		res /= 3;
		
		return res;
    }
    
private:
	
	//[0,idx]	
	int prefixSum(int idx){
		int result = 0;
		while(idx > 0){
			result += bitAttr[idx];
			idx -= (idx & (-idx));
		}
		
		return result;
	}
	
	void update(int idx,int delta){
		if(idx ==0) return;
		while(idx<=2000){
			bitAttr[idx] += delta;
			idx += (idx & (-idx));
		}
	}
	
	//(p,q)
	int rangeSum(int p,int q){
		return (prefixSum(q-1) - prefixSum(p));
	}
	
	int *bitAttr;
};



int main(){
//	vector<int> test = {2,3,2,4};
	vector<int> test = {0,0,0};
	Solution su = Solution();
	cout << su.triangleNumber(test) << endl;
	return 0;
}
