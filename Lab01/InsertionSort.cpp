#include <iostream>

#define MAX_INT 2147483647

using namespace std;
 
void insertionSort(int ray[], int number)
{
    int i, key, j, n;
    for (i = 1; i < number; i++)
    {
        key = ray[i];
        j = i - 1;
        while (j >= 0 && ray[j] > key)
        {
            ray[j + 1] = ray[j];
            j = j - 1;
        }
        ray[j + 1] = key;
        for(n = 0 ; n <= i; n++)
        {
          cout << ray[n] << ";"; 
        }
        cout << endl;  
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
  insertionSort(Sequence, arraySize);
  // Free allocated space
  delete[] Sequence;

}
