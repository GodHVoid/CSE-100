#include <iostream>
#include <limits.h>
#include <stdio.h>
#define MAX_INT 2147483647
#define MIN_INT -214783647
using namespace std;
 
 int max(int x, int y)
 {
     if(x > y)
     {
         return x;
     }
     return y;
 }
 int max2(int x, int y, int z)
 {
     return max(max(x,y),z);
 }
int maxCrossSum(int ray[],int low2, int mid, int high2)
{
    int sum = 0;
    int leftsum = MIN_INT;
    int rightsum = MIN_INT;
    int i;
    for(i = mid;i >= low2; i--)
    {
        sum =  sum + ray[i];
        if(sum > leftsum)
        {
            leftsum =sum;
        }
    }
    sum = 0;
    for(i = mid + 1; i <= high2; i++)
    {
        sum = sum + ray[i];
        if (sum > rightsum)
        {
            rightsum =sum;
        }
    }
    return max2(leftsum + rightsum, leftsum, rightsum);
}

int maxSubarray(int ray[], int low, int high)
{
    if (low == high)
    {
        return ray[low];
    }
    else
    {
        int mid = low +(high-low)/2;
        int left = maxSubarray(ray,low,mid);
        int right = maxSubarray(ray,mid+1,high);
        int cross = maxCrossSum(ray,low,mid,high);
        
        return max2(left,right,cross);
    }

}



int main(int argc,char **argv) 
{
  int* Sequence;
  int arraySize = 1;

  // Get the size of the sequence
  cin >> arraySize;
  Sequence = new int[arraySize];
    
  // Read the sequence
  for(int i=0; i<arraySize; i++)
    cin >> Sequence[i];
  int maxsum =  maxSubarray(Sequence, 0, arraySize-1);
   // output
  cout << maxsum;
  // Free allocated space
delete[] Sequence;

}
