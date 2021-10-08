#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
	Name: 
	Copyright: 
	Author: 
	Date: 02/09/19 10:52
	Description: 
*/

class CQueue {
public:
	vector<int> memory, tmp;
    CQueue() {
		
    }
    
    void appendTail(int value) {
	 	memory.push_back(value);
    }
    
    int deleteHead() {
    	
    	int result = -1;
		if(!tmp.empty()){
			result = tmp.back();
			tmp.pop_back();
		}else if(!memory.empty()){
			while(!memory.empty()){
				tmp.push_back(memory.back());
				memory.pop_back();
			}
			result = tmp.back();
			tmp.pop_back();
		}
		
		return result;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */



int main(){
	CQueue* obj = new CQueue();
	obj->appendTail(1);
	cout << ">>>" << obj->deleteHead() << endl;
	cout << ">>>" << obj->deleteHead() << endl;
	obj->appendTail(2);
	obj->appendTail(3);
	
	
	cout << ">>>" << obj->deleteHead() << endl;
	return 0;
}

