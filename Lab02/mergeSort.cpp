#include <iostream>
using namespace std;

void merge(int ray[], int start, int mid, int length)
{
    int x, y, z, left, right;
    left = mid - start + 1;
    right = length - mid;
    int left_ray[left]; 
    int right_ray[right];
    for(x = 0; x < left; x++)
    {
        left_ray[x] = ray[start + x];
    }
    for(y = 0 ; y < right; y++)
    {
        right_ray[y] = ray[mid + 1 + y];
    }
    x = 0;
    y = 0;
    z = start;
    while(x < left && y < right)
    {
        if(left_ray[x] <= right_ray[y])
        {
            ray[z] = left_ray[x];
            x++;
        }
        else
        {
            ray[z] = right_ray[y];
            y++;
        }
        z++;
    }
    while(x < left)
    {
        ray[z] =left_ray[x];
        x++;
        z++;
    }
    while(y < right)
    {
        ray[z] =  right_ray[y];
        y++;
        z++;
    }
}
void merge_sort(int ray[], int start, int length)
{
    int mid;
    if(start < length)
    {
        int mid = start + (length - start)/2;
        merge_sort(ray, start, mid);
        merge_sort(ray, mid+1, length);
        merge(ray, start, mid, length);
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
  merge_sort(Sequence, 0, arraySize - 1) ;

  for(int i=0; i<arraySize; i++)
  {
    cout << Sequence[i] << ";";
  }

  // Free allocated space
  delete[] Sequence;

}
