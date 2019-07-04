#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;


int main(){
	
//	int data[5] = {-1,2,4,6,8};
//	cout << lower_bound(data,data+5,3) - data << endl;
	string test;
	getline(cin,test);
	
	string::iterator it = test.begin() + 2;
	
	while(it!=test.end()){
		cout << ">>> " << *it << endl;
		it ++;
	}
	
	
	return 0;
}
