#include <iostream> 
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

void output(UndirectedGraphNode *node,set<int> &labels){
	if(labels.find(node->label)!=labels.end()){
		return;
	}
	labels.insert(node->label);
	cout << "#" << (node->label);
	for(int i=0;i<(node->neighbors).size();i++){
		cout << "," << ((node->neighbors)[i]->label);
	}
	cout << endl;
	for(int i=0;i<(node->neighbors).size();i++){
		output((node->neighbors)[i],labels);
	}
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL){
        return node;
    }
    
    map<int,UndirectedGraphNode *> umap;
    UndirectedGraphNode *nodeClone = new UndirectedGraphNode(node->label);
    umap[node->label] = nodeClone;
    queue<UndirectedGraphNode *> q;
    q.push(node);
    
//    cout << q.size();
    while(!q.empty()){
//    	cout << "hit" << endl;
        UndirectedGraphNode *curr = q.front();
        q.pop();
//        set<int> labels;
//        output(curr,labels);
        for(int i=0;i<(curr->neighbors).size();i++){
            UndirectedGraphNode *nodeNext = (curr->neighbors)[i];
            if(umap.find(nodeNext->label)==umap.end()){
                UndirectedGraphNode *nodeClone = new UndirectedGraphNode(nodeNext->label);
                q.push(nodeNext);
                umap[nodeNext->label] = nodeClone;
            }
            (umap[curr->label]->neighbors).push_back(umap[nodeNext->label]);
        }
    }
    
    return umap[node->label];
}


int main(){
	UndirectedGraphNode *nodeClone0 = new UndirectedGraphNode(0);
	UndirectedGraphNode *nodeClone1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *nodeClone2 = new UndirectedGraphNode(2);
	(nodeClone0->neighbors).push_back(nodeClone1);
	(nodeClone0->neighbors).push_back(nodeClone2);
	(nodeClone1->neighbors).push_back(nodeClone2);
	(nodeClone2->neighbors).push_back(nodeClone2);
	set<int> labels;
//	output(nodeClone0,labels);
	output(cloneGraph(nodeClone0),labels);
//	cloneGraph(nodeClone0);
	return 0;
}
