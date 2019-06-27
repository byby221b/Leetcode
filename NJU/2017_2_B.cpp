/*
	Name: 
	Copyright: 
	Author: 
	Date: 27/06/19 20:13
	Description: 树状数组，选定两条边，计算符合条件的第三条边的数目 
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
		
		for(int i=1;i<=2000;i++){
			bitAttr[i] = 0;
		}
		
		for(int i=0;i<size;i++){
			update(nums[i],1);
		}
		
		int res = 0;
		for(int i=0;i<size;i++){
			if(nums[i]==0) continue;
			for(int j=i+1;j<size;j++){
				if (nums[j]==0) continue;
				
				int minV = minus(nums[i],nums[j]);
				int maxV = nums[i] + nums[j];
				res += rangeSum(minV,maxV);
				
				if(minV < nums[i] && nums[i] < maxV){
					res --;
				}
				if(minV < nums[j] && nums[j] < maxV){
					res --;
				}
			}
		}
		
		delete [] bitAttr;
		
		res /= 3;
		
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
		if(idx==0) return;
		while(idx<=1000){
			bitAttr[idx] += delta;
			idx += (idx & (-idx));
		}
	}
	
	int minus(int a,int b){
		int tmp = a - b;
		return (tmp >= 0) ? tmp : (-tmp);
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
