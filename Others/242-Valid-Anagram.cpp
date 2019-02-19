#include <iostream>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
	
    if(s.length()!=t.length())
    	return false;
    
    int count[26];
    for(int i=0;i<26;i++){
    	count[i] = 0;
	}
	
	for(int i=0;i<s.length();i++){
		int ch = s[i] - 'a';
		count[ch] ++;
	}
	
	for(int i=0;i<t.length();i++){
		int ch = t[i] - 'a';
		count[ch]--;
		if(count[ch]<0){
			return false;
		}
	}
	
	for(int i=0;i<26;i++){
		if(count[i]!=0){
			return false;
		}
	}
	
	return true;
}

int main(){
	string s = "rat";
	string t = "car";
	cout << isAnagram(s,t) << endl;
	return 0;
}
