// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> , int ,int );


int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;

        vector<vector<int>> g(V);

        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }

        for(int i=0;i<V;i++)
        {
      	    for(int j=0;j<V;j++)
      	    {
      		    cin>>g[i][j];
      	    }
        }

        int s;
        cin>>s;

        dijkstra(g, s, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends
/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here

    int distance[V];
    for(int i=0; i<V; i++)
        distance[i] = INT_MAX;
    distance[src] = 0;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> pq;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int vertex = pq.top().second;
        pq.pop();

        for(int i=0; i<V; i++)
        {
            if(graph[vertex][i] && distance[i] > distance[vertex] + graph[vertex][i])
            {
                distance[i] = distance[vertex] + graph[vertex][i];
                pq.push(make_pair(distance[i],i));
            }
        }
    }

    for(int i=0; i<V; i++)
        cout<<distance[i]<<" ";
}
