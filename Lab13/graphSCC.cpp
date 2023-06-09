#include <iostream>
#include <climits>
#include <list>
#include <stack>
using namespace std;

class Graph{
	int V;
	list<int> *Adj;
	void DFS(int v,bool visit[],list<int> &var);
	void order(int v,bool visit[],stack<int> &Stack);
	public:
		Graph(int V);
		void addE(int u,int v);
		Graph transpose();
		void SCC();
};

Graph::Graph(int V)
{
	this->V=V;
	Adj=new list<int>[V];
}

void Graph::addE(int v,int w){
	Adj[v].push_back(w);
}

void Graph::DFS(int v,bool path[],list<int> &var){
	path[v]=true;
	var.push_back(v);
	list<int>::iterator it;
	for(it=Adj[v].begin();it!=Adj[v].end();it++){
		if(!path[*it]){
			DFS(*it,path,var);
		}
	}
}

Graph Graph::transpose(){
	Graph G(V);
	for(int i=0;i<V;i++){
		list<int>::iterator it;
		for(it=Adj[i].begin();it!=Adj[i].end();it++){
			G.Adj[*it].push_back(i);
		}
	}
	return G;
}

void Graph::order(int v,bool path[],stack<int> &Stack){
	path[v]=true;
	list<int>::iterator it;
	for(it=Adj[v].begin();it!=Adj[v].end();it++){
		if(!path[*it]){
			order(*it,path,Stack);
		}
	}
	Stack.push(v);
}

void Graph::SCC()
{
	stack<int> Stack;
	bool *path=new bool[V];
	for(int i=0;i<V;i++){
		path[i]=false;
	}
	for(int i=0;i<V;i++){
		if(path[i]==false){
			order(i,path,Stack);
		}
	}
	Graph Gt=transpose();
	for(int i=0;i<V;i++){
		path[i]=false;
	}
	list<list<int>> out;
	while(Stack.empty()==false){
		int v=Stack.top();
		Stack.pop();
		if(path[v]==false){
			list<int> var;
			Gt.DFS(v,path,var);
			out.push_back(var);
		}
	}
	int min[out.size()];
	list<list<int>>::iterator it;
	int fin[V];
	int index=0;
	for(it=out.begin();it!=out.end();it++){
		min[index]=INT_MAX;
		list<int>::iterator ir;
		list<int>& var=*it;
		for(ir=var.begin();ir!=var.end();ir++){
			if(*ir<min[index]){
				min[index]=*ir;
			}
		}
		for(ir=var.begin();ir!=var.end();ir++){
			fin[*ir]=min[index];
		}
		index++;
	}
	for(int i=0;i<V;i++){
		cout<<fin[i]<<endl;
	}
}

int main(int argc,char **argv){
	int V,E;
	cin>>V;
	cin>>E;
	Graph G(V);
	for(int i=0;i<E;i++){
		int a,b;
		cin>>a;
		cin>>b;
		G.addE(a,b);
	}
	G.SCC();
	return 0;
}