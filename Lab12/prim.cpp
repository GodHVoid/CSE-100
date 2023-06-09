#include <iostream>
#include <climits>
#include <list>
#include <queue>

using namespace std;

typedef pair<int,int> intPair; 

class Graph
{
	int V;
	list<intPair> *Adj;
	public:
		Graph(int V);
		void addE(int u,int v,int w);
		void prim();
};

Graph::Graph(int V)
{ 
	this->V=V;
	Adj=new list<intPair>[V];
}

void Graph::addE(int u,int v,int w)
{
	Adj[u].push_back(make_pair(v,w));
	Adj[v].push_back(make_pair(u,w));
}

void Graph::prim() 
{
	priority_queue<intPair,vector<intPair>,greater<intPair>> min;
	vector<int> key(V,INT_MAX);
	vector<int> parent(V,-1);
	vector<bool> intree(V,false);
	min.push(make_pair(0,0));
	key[0]=0;
	while(!min.empty())
	{
		int u= min.top().second;
		min.pop();
		intree[u]=true;
		list<intPair>::iterator it;
		for(it = Adj[u].begin(); it != Adj[u].end();it++)
		{
			int v=(*it).first;
			int weight=(*it).second;
			if (intree[v] == false && key[v] > weight)
			{
				key[v]=weight;
				min.push(make_pair(key[v],v));
				parent[v]=u;
			}
		}
	}
	
	for(int i=1;i<V;i++)
	{
		cout<<parent[i]<<endl;
	}
}

int main(int argc,char **argv)
{
	int V,E;
	cin>>V;
  	cin>>E;
	Graph G(V);
	for(int i=0;i<E;i++)
	{
		int u,v,w;
		cin>>u;
		cin>>v;
		cin>>w;
		G.addE(u,v,w);
	}
	G.prim();
	return 0;
}