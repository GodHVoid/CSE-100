#include <iostream>
using namespace std;

void heap(int ray[], int n, int x)
{
    int big = x;
    int left = 2*x + 1;
    int right = 2*x + 2;
    if(left < n && ray[left] > ray[big])
    {
        big = left;
    }
    if(right < n && ray[right] >ray[big])
    {
        big = right;
    }
    if(big != x )
    {
        swap(ray[x],ray[big]);
        heap(ray, n, big);
    }
}

void heap_sort(int ray[], int n)
{
    int x;
    for(x = n/2 -1; x>=0;x--)
    {
        heap(ray,n,x);
    }
    for(x = n-1; x>=0; x--)
    {
        swap(ray[0],ray[x]);
        heap(ray,x,0);
    }

}
int main(int argc,char **argv) {

  int* Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the sequence
  for(int i=0; i<arraySize; i++)
    cin >> Sequence[i];
  
   // output
  heap_sort(Sequence,arraySize);

  for(int i=0; i<arraySize; i++)
  {
    cout << Sequence[i] << ";";
  }

  // Free allocated space
  delete[] Sequence;

}
