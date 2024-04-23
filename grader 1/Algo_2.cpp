#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
bool finish_first(pair<int,int> a, pair<int,int> b)
{
  return a.second < b.second;
}
int main()
{
  int n;
  cin >> n;
  vector< pair<int, int> > j;
  int s, f;
  for(int i=0;i<n;i++)
  {
    cin >> s;
    cin >> f;
    j.push_back(make_pair(s, f));
  }
  sort(j.begin(), j.end(), finish_first);
  int count =0;
  int time = -1;
  for(int i=0;i<n;i++)
  {
    if(j[i].first > time)
    {
      count++;
      time = j[i].second;
    }
  }
  cout << count;
}

