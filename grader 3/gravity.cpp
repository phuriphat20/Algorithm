#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    int t,b,r,k,max,ssr;
    int u,v,l;
    int umin,vmin,dmin;
    cin >> t;
    priority_queue< int,vector<int>,greater<int> > pq;
    for(int j = 0 ; j < t ; j++)
    {
        cin >> b >> r >> ssr;
        vector <int> g[b];
        int len[b][b];
        stack<int> S;
        bool passed[b];
		int count[b];
		for(int i = 0 ; i < b ; i++){
			count[i] = 0;
        }
        for(int i = 0 ; i < r ; i++){
            cin >> u >> v >> l;
            g[u].push_back(v);
            len[u][v] = l;
			count[u]++;
            g[v].push_back(u);
            len[v][u] = l;
            count[v]++;
        }
        int d[b],parent[b];
        stack<int> tt,kk;
        //initial value
        for(int i = 0 ; i < b ; i++){
            d[i] = 10000;
            parent[i] = 0;
            passed[i] = false;
            tt.push(1);
        }

        S.push(ssr);
        passed[ssr] = true;
        d[ssr] = 0;
        int o = 0;
        umin = vmin = dmin = -1;
        int mindv = 10000;
        //loop ball
        while(o < b-1){
            kk = S;
            mindv = 10000;
            while(!kk.empty())
            {
                u = kk.top();
                kk.pop();
                for(k = 0 ; k < count[u] ; k++)
                {
                    v = g[u][k];
                    if(d[u] + len[u][v] < mindv && !passed[v] && passed[u])
                    {
                        umin = u;
                        vmin = v;
                        mindv = d[u]+len[u][v];
                    }
                }
            }
            if(!passed[vmin] && passed[umin])
            {
                u = umin;
                v = vmin;
                S.push(v);
                parent[v] = u;
                d[v] = d[u]+len[u][v];
                passed[v] = true;
            }
            o++;
        }
        
		//push for print
        pq.push(S.top());
        S.pop();
        while (!S.empty())
        {
            if(d[pq.top()] == d[S.top()])
            {
                pq.push(S.top());
                S.pop();
            }
            else
            {
                break;
            }
        }
        while(!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
}

