#include <bits/stdc++.h>
using namespace std;

/*
Graph : directed / undirected graph
cyclic / acyclic  graph
weightaed / unit weigth graphs

n = number of nodes ,
m = numbre of edges,

adjacency matrix :

.   0 1 2 3 4 5  --u   adj[v][u] = 1 .. represents there is edge of unit weight between vertex u and v .
.
0   1 0 0 0 0 1
1   0 0 1 0 0 1
2   0 1 0 0 1 1
3   0 0 0 1 0 0
4   0 0 1 0 1 0
5   1 1 1 0 0 1
|
| --> v

*/

int main()
{
    int n, m ,prefre =0;
    cout << "enter no. of nodes and no. of edges";

    cin >> n >> m;
    cout<<" select preferance : 1 for adjlist , 0 for adjmatrix :";
    cin>>prefre;
    if (prefre == 1)
    {
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cout << "enter edge links :";
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        cout << endl;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        vector<int> adj[n+1]; // adjlist , if it is weighted then use vector<pair<int ,int> > arr[n+1]
        for(int i=0 ;i<m ; i++){
            int u,v;
            cout << "enter edge links :";
            cin >> u >> v;
            if(u==v) adj[u].push_back(v);
            else{
            adj[u].push_back(v);
            adj[v].push_back(u);
            }
        }
        cout<<endl;
        for(int i =1 ;i<=n;i++){
            cout<<i<<":";
            for(int j =0 ; j< adj[i].size();j++){
                cout<<adj[i][j] <<" ";
            }
            cout<<endl;
        }
           
    }

    return 0;
}