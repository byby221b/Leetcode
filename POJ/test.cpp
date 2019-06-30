#include <iostream>
#include <algorithm>
#include <string> 

using namespace std;


int main(){
	
//	int data[5] = {-1,2,4,6,8};
//	cout << lower_bound(data,data+5,3) - data << endl;
	string a = "hello"	;
	string b = a;
	
	reverse(b.begin(),b.end());
	
	cout << "a:\t" << a << endl;
	cout << "b:\t" << b << endl;
	
	return 0;
}
