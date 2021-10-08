#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> stack, min_stack;
    MinStack() {
		
    }
    
    void push(int x) {
    	stack.push_back(x);
    	if(min_stack.empty() || x <= min_stack.back()){
    		min_stack.push_back(x);
		}
    }
    
    void pop() {
		int res = stack.back();
		stack.pop_back();
		if (min_stack.back() == res){
			min_stack.pop_back();
		}
    }
    
    int top() {
		return stack.back();
    }
    
    int min() {
		return min_stack.back();
    }
};


int main() {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << ">>>" << minStack.min() << endl;  
	minStack.pop();
	cout << ">>>" << minStack.top() << endl;  
	cout << ">>>" << minStack.min() << endl;  
	
	return 0;
}
