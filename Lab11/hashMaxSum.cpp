#include <iostream>
#include <map>
 
using namespace std;

 
int main(void) {

  // hash and hash iterator
  std::map<std::pair<int, int>, int> h;
  std::map<std::pair<int, int>, int>::iterator it;
  std::map<std::pair<int, int>, int>::iterator ir;
  int n,x,y;
  cin>>n;
  for(int i = 0;i<n;i++)
  {
    cin>>x;
    cin>>y;
    std::pair<int,int> pt1 = std::make_pair(x, y);
    std::pair<std::pair<int,int>, int> new_e = std::make_pair(pt1, x + y);
    h.insert(new_e);
  }
  
  int maxsum = -1;
  for(it = h.begin(); it !=h.end();it++)
  {
    x = it->first.first;
    y = it->first.second;
    std::pair<int,int> pt2 = std::make_pair(x-1, y-1);
    ir = h.find(pt2);
    if (ir != h.end() && it->second > maxsum)
    {
      maxsum = it->second;
    }
  }
  cout << maxsum;
  
  return 0;

}//If there is a maxsum and there are no points with a sum of maxsum-1, then it won't be detected.
