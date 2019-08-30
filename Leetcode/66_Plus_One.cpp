/*
	Name: 
	Copyright: 
	Author: 
	Date: 29/08/19 11:41
	Description: 
*/

#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		int N = digits.size();
		int carry = 1;
		int res;
		for(int i=N-1;i>=0;i--)        {
			if(!carry) break;
			res = digits[i] + carry;
			digits[i] = res % 10;
			carry = res / 10;
		}
		if(carry){
			digits.insert(digits.begin(),1);
		}
		
		return digits;
    }
};

int main(){
	Solution su = Solution();
//	vector<int> test = {4,3,2,1};
//	vector<int> test = {0};
	vector<int> test = {9,9,9,9};
	
	vector<int> res = su.plusOne(test);
	
	for(int i=0;i<res.size();i++){
		cout << res[i];
	}
	cout << endl;
	
	return 0;
}
