#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;



void radixSort( int arr[][10],int n)
{
    for(int x=9;x>-1;x--)
    {
        for(int i=1;i<n;i++)
        {
            int key[10];
            for(int k=0;k<10;k++)
            {
                key[k]=arr[i][k];
            }
            int j=i-1;
            while(j>=0&&arr[j][x]>key[x])
            {
                for(int k=0;k<10;k++)
                {
                    arr[j+1][k]=arr[j][k];
                }
                j=j-1;
            }
            for(int k=0;k<10;k++)
            {
                arr[j+1][k]=key[k];
            }
        }
    }
}

int main(int argc,char **argv) 
{
  int size = 1;
  cin>>size;
  int arr[size][10];
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<10;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    radixSort(arr,size);
    
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<10;j++)
        {
            cout<<arr[i][j]<<";";
        }
        cout<<endl;
    }

  
}
