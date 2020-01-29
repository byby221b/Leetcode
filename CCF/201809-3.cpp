#include <iostream> 
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
/*
	Name: 
	Copyright: 
	Author: 
	Date: 11/09/19 10:43
	Description: Í¨¹ýÑùÀý8/10 
*/


using namespace std;

struct Element{
	string label,id;
	int parent;
	
	Element(string Label,string Id,int p): label(Label),id(Id),parent(p){}
};

struct Query{
	int type;
	string name;
	Query(int t,string n) : type(t),name(n){}
};

Element *Eles[105];
char buf[85];
int n,m;

bool isAlpha(char ch){
	return ((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9'));
}

char toLower(char ch){
	if(ch>='A' && ch<='Z'){
		return ch - 'A' + 'a';
	}else{
		return ch;
	}
}

void readEle(){
	int parents[105];
	memset(parents,-1,sizeof(parents));
	
	char *ptr;
	int dotCount = 0,state = 0;
	string labelName,idName;
	for(int i=1;i<=n;i++){
		fgets(buf,85,stdin);
		ptr = buf;
		dotCount = 0;
		state = 0;
		labelName = "";
		idName = "";
		
		while(true){
			if(state==0){
				if(*ptr=='.'){
					state = 2;
					dotCount ++;
				}else if(isAlpha(*ptr)){
					state = 1;
					labelName += toLower(*ptr);
				}
			}else if(state==1){
				if(isAlpha(*ptr)){
					labelName += toLower(*ptr);
				}else if(*ptr=='#'){
					state = 4;
				}else if(*ptr=='\n'){
					state = 3;
				}
			}else if(state==2){
				if(*ptr=='.'){
					dotCount ++;
				}else if(isAlpha(*ptr)){
					state = 1;
					labelName += toLower(*ptr);
				}
			}else if(state==3){
				break;
			}else if(state==4){
				if(isAlpha(*ptr)){
					idName += *ptr;
				}else if(*ptr=='\n'){
					state = 3;
				}
			}
			ptr ++;
		}
		if(dotCount==0){
			Eles[i] = new Element(labelName,idName,-1);	
		}else{
			Eles[i] = new Element(labelName,idName,parents[dotCount/2-1]);
		}
		parents[dotCount/2] = i;
		
	}
	
}

void output(){
	cout << "*********************" << endl;
	for(int i=1;i<=n;i++){
		cout << Eles[i]->label << "\t" << Eles[i]->id << "\t" << Eles[i]->parent << endl;
	}
}

bool judge(Element *e,Query *q){
	if(q->type==0 && (e->label)==(q->name)) return true;
	if(q->type==1 && (e->id)==(q->name)) return true;
	
	return false;
}

void query(){
	fgets(buf,85,stdin);
	char *ptr = buf;
	string name;
	vector<int> found;
	Query *querys[10];
	int top = 0;
	while(*ptr!='\n'){
		name = "";
		if(*ptr=='#'){
			ptr ++;
			while(isAlpha(*ptr)){
				name += *ptr;
				ptr++;
			}
			
			querys[top] = new Query(1,name);
			top++;
		}else if(*ptr==' '){
			ptr ++;
		}
		else{
			while(isAlpha(*ptr)){
				name += toLower(*ptr);
				ptr ++;
			}
			querys[top] = new Query(0,name);
			top++;
		}
	}
	
	
	
	
//	for(int i=0;i<top;i++){
//		cout << querys[i]->type << " " << querys[i]->name << endl;
//	}
//	
	if(top==1){
		for(int i=1;i<=n;i++){
			if(judge(Eles[i],querys[0])) found.push_back(i);
		}
	}else{
		for(int i=1;i<=n;i++){
//			cout << Eles[i]->label << " " << (querys[size-1])->name << endl;
			if(judge(Eles[i],querys[top-1])){
				int p = Eles[i]->parent;
				while(p!=-1)	{
					if(judge(Eles[p],querys[top-2])){
						found.push_back(i);
						break;
					}
					p = Eles[p]->parent;
				}
			}
		}
	}
	
	
	if(!found.empty()){
		printf("%d ",found.size());
		for(int i=0;i<found.size()-1;i++){
			printf("%d ",found[i]);
		}
		printf("%d\n",found[found.size()-1]);
	}else{
		printf("0\n");
	}
}

int main(){
	scanf("%d%d",&n,&m);
	
	fgets(buf,85,stdin);
	
	readEle();
//	output();

	for(int i=0;i<m;i++){
		query();
	}
	return 0;
}

