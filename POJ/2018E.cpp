/*
	Name: 
	Copyright: 
	Author: 
	Date: 21/06/19 09:27
	Description: leetcode 493 归并排序 
	注意边界情况 
	1.输入序列有可能为空
	2.整数的二倍有可能超过整数范围 
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int mergeSort(int left,int right){
		if(left==right){
			return 0;
		}
		
		int mid = (left+right)/2;
//		cout <<left << " " << right<< " " <<  mid << endl;
		int leftCount = mergeSort(left,mid);
//		cout <<left << " " << right<< " " <<  mid << endl;
		int rightCount = mergeSort(mid+1,right);
		
		
		//merge
		long long *tmp = new long long[right - left + 1];
		int p = left , q = mid + 1 , r = 0;
		int count = 0;
		int s = left;
		while(p<=mid && q<=right && r<=(right-left)){
			if(data[p]<=data[q]){
				tmp[r] = data[p];
				p ++;
			}else{
				tmp[r] = data[q];
				while(data[s]<=2*data[q] && s<=mid){
					s ++;
				}
				count += (mid - s + 1);
				q ++;
//				for(int i=s;i<=mid;i++){
//					cout << data[s] << " " << tmp[r] << endl;
//				}
				
//				cout << "===================" << endl;
			}
			r++;
		}
		
		while(p<=mid){
			tmp[r++] = data[p++];
		}
		
		while(q<=right){
			tmp[r++] = data[q];
			while(data[s]<=2*data[q] && s<=mid){
					s ++;
			}
			count += (mid - s + 1);
			q++;
		}
		
		for(int i=0;i<=(right-left);i++){
			data[left+i] = tmp[i];
		}
		
		
		delete[] tmp;
		return (leftCount + rightCount + count);
	}
	
	
    int reversePairs(vector<int>& nums) {
    	if(nums.empty()) return 0;
    	
        data = new long long[nums.size()];
//        size = nums.size();
        for(int i=0;i<nums.size();i++){
        	data[i] = nums[i];
//        	cout << data[i] << " " ;
		}
        
        int res = mergeSort(0,nums.size()-1);
        delete[] data;
        
        return res;
    }
private:
	long long *data;
//	int size;
};

int main() {
	Solution su = Solution();
//	vector<int> test = {2,4,3,5,1};
//	vector<int> test = {1,3,2,3,1};
//	vector<int> test = {0,9,8,7,6,5,4,3,2,1};
//	vector<int> test = {0,1,2,3,4,5,6,8,7};
//	vector<int> test = {};
	vector<int> test = {-5,-5};
	cout << su.reversePairs(test) << endl;
	
	return 0;
}

