#include <iostream>
#include <bits/stdc++.h> 
#include <string>
using namespace std;

class Hash
{
	int M;
	list<int> *table;
	public:
		Hash(int z);
		int hashFunction(int key)
        {
			return(key % M);
		}
		void insert(int key);
		void delet3(int key);
		void search(int key);
		void output();
};

Hash::Hash(int z)
{
	this->M = z;
	table = new list<int>[M];
}

void Hash::insert(int key)
{
	int index = hashFunction(key);
	table[index].push_front(key);
}

void Hash::delet3(int key)
{
	int index = hashFunction(key);
	list<int>::iterator i;
	for(i = table[index].begin();i != table[index].end(); i++)
    {
		if(*i==key)
        {
			break;
		}
	}
	if(i != table[index].end())
    {
		table[index].erase(i);
		cout<<key<<":DELETED;"<<endl;
	}
    else
    {
		cout<<key<<":DELETE_FAILED;"<<endl;
	}
}

void Hash::search(int key)
{
	int index=hashFunction(key);
	list<int>::iterator i;
	int x=0;
	for(i = table[index].begin();i != table[index].end(); i++)
    {
		if(*i==key)
        {
			break;
		}
		x++;
	}
	if(i != table[index].end())
    {
		cout<<key<<":FOUND_AT"<<index<<","<<x<<";"<<endl;
	}
    else
    {
		cout<<key<<":NOT_FOUND;"<<endl;
	}
}

void Hash::output()
{
	for(int i = 0;i < M; i++)
    {
		cout<<i<<":";
		for(int x:table[i])
        {
			cout<<x<<"->";
		}
		cout<<";"<<endl;
	}
}

int main(int argc,char **argv)
{
	int m=1;
	cin>>m;
	
	Hash h(m);
	
	while(true)
    {
		string command;
		cin>>command;
		if(command.at(0) == 'i')
        {
			h.insert(stoi(command.substr(1)));
		}
        else if(command.at(0) == 'd')
        {
			h.delet3(stoi(command.substr(1)));
		}
        else if(command.at(0) == 'o')
        {
			h.output();
		}
        else if(command.at(0) =='s')
        {
			h.search(stoi(command.substr(1)));
		}
        else if(command.at(0) =='e')
        {
			break;
		}
	}
	return 0;
}