#include <iostream>
using namespace std;

void cutrod(int *p,int n)
{
	int r[n+1];
	int s[n];
	r[0]=0;
	for(int j = 1;j <= n; j++)
	{
		int q=-2147483648;
		for(int i = 0;i < j; i++)
		{
			if(q < p[i] + r[j-i-1])
			{
				q = p[i] + r[j-i-1];
				s[j] = i + 1;
			};
		}
		r[j] = q;
	}
	cout<<r[n]<<endl;
	while(n>0)
	{
		cout<<s[n]<<" ";
		n = n - s[n];
	}
	cout<<"-1 "<<endl;
}


int main(int argc,char **argv)
{
	int size = 1;
	cin>>size;
	int* arr;
	arr = new int[size];
	for(int i = 0;i < size;i++)
	{
		cin>>arr[i];
	}
	cutrod(arr,size);
}