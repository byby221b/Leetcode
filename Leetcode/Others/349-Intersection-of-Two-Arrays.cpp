#include <iostream>
#include <vector>
using namespace std;

void gnomeSort(vector<int>& nums){
//	cout << "hit" << endl;
	//sort
	int i = 0;
	while(i<nums.size()){
		if(i==0 || nums[i]>=nums[i-1]){
			i ++ ;
		}else{
			int tmp = nums[i];
			nums[i] = nums[i-1];
			nums[i-1] = tmp;
			i --;
		}
	}
}


void output(vector<int> a){
	vector<int>::iterator it;
	for(it=a.begin();it!=a.end();it++){
		cout << *it << " ";
	}
	cout << endl;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	vector<int> result;
	gnomeSort(nums1);
	gnomeSort(nums2);
//	output(nums1);
//	output(nums2);
	int i = 0,j = 0;
	while(i<nums1.size() && j<nums2.size()){
		if(nums1[i]==nums2[j]){
			if(result.empty() || result.back()!=nums1[i]){
				result.push_back(nums1[i]);
			}
			i ++;
			j ++;
		}
		
		while(nums1[i]<nums2[j] && i<nums1.size()) i++;
		
		while(nums2[j]<nums1[i] && j<nums2.size()) j++;
	}
	
	return result;
	 
}

int main(){
	int _a[] = {4,9,5};
	int _b[] = {9,4,9,8,4};
	vector<int> a(_a,_a+sizeof(_a)/sizeof(_a[0]));
	vector<int> b(_b,_b+sizeof(_b)/sizeof(_b[0]));
//	gnomeSort(a);
//	output(a);
	output(intersection(a,b));
	return 0;
}
