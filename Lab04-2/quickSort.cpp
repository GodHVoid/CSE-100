#include <iostream>
using namespace std;

int partition(int ray[], int x, int n)
{
    int shift = ray[n];
    int i = x -1;
    for(int j = x; j<=n-1;j++)
    {
        if(ray[j]<=shift)
        {
           i++;
           swap(ray[i],ray[j]);
        }
    }
    swap(ray[i+1],ray[n]);
    return i+1;
}

void quick_sort(int ray[],int x, int n)
{
    if(x<n)
    {
        int part_index = partition(ray,x,n);
        quick_sort(ray,x,part_index-1);
        quick_sort(ray,part_index+1,n);
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
  quick_sort(Sequence,0,arraySize-1);

  for(int i=0; i<arraySize; i++)
  {
    cout << Sequence[i] << ";";
  }

  // Free allocated space
  delete[] Sequence;

}
