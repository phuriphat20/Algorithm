#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool finish_first(pair<int, int> a , pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int amount, s, f;
    int max;
    vector < pair <int, int> > box;
    cin >> amount;
    for (int i = 0; i < amount; i++)
    {
        cin >> s;
        cin >> f;
        box.push_back(make_pair(s,f));
    }
    sort(box.begin(), box.end(), finish_first);
    max = box[amount-1].second;
    int countBox[max+1];
    for (int i = 0; i <= max; i++)
    {
        countBox[i] = 0;
    }

    for (int i = 1; i <= max; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (box[j].first == i && box[j].second )
            {
                countBox[i]++;
            }
            
        }
        
    }
    for (int i = 1; i <= max; i++)
    {
        cout << countBox[i] << endl;
    }
    
    
    return 0;
}