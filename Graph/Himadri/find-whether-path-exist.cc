#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class UndirectedGraph{
  int v;
  list<int> *adj;
public:
  UndirectedGraph(int v){
    this->v = v;
    adj = new list<int>[v];
  }
  void addEdge(int s, int d);
  bool BFS(int s, int d);
};

void UndirectedGraph :: addEdge(int s, int d){
  adj[s].push_back(d);
  adj[d].push_back(s);
}

bool UndirectedGraph :: BFS (int s, int d) {
  if(s==d) return true;

  bool *visited = new bool[v];
  for(int i=0; i<v; i++) visited[i] = false;

  list<int> q;
  list<int>:: iterator i;

  visited[s] = true;
  q.push_back(s);

    while(!q.empty()){
      s = q.front();
      q.pop_front();

      for(i=adj[s].begin(); i!=adj[s].end(); i++){
        if(*i == d) return true;
        if(!visited[*i]) {
          visited[*i] = true;
          q.push_back(*i);
        }
      }

    }
    return false;
}

bool isSafe(int i, int j, int n, int **matrix) {
  if(i<0 || i>=n || j <0 || j >=n || matrix[i][j]==0) return false;
  return true;
}

bool pathExists(int **matrix, int n) {
  int s, d;
  int v = n*n;

  UndirectedGraph graph(v);

  int index = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++){
      if(matrix[i][j]!=0){
        //add edges
        if(isSafe(i, j+1, n, matrix)) graph.addEdge(index, index+1);
        if(isSafe(i, j-1, n, matrix)) graph.addEdge(index, index-1);
        if(isSafe(i+1, j, n, matrix)) graph.addEdge(index, index+n);
        if(isSafe(i-1, j, n, matrix)) graph.addEdge(index, index-n);
      }
      if(matrix[i][j]==1) s = index;
      if(matrix[i][j]==2) d = index;

      index++;
    }
  }
  return graph.BFS(s,d);

}

int main() {
	//code
	int t, n;
	cin >> t;
	while(t--){
	    cin>> n;
	    int **arr;
      arr = new int*[n];
      for(int i=0; i<n; i++) arr[i] = new int[n];
	    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) cin >> arr[i][j];
      }

      if(pathExists(arr, n)) cout << '1' <<endl;
      else cout << '0' << endl;


	}
	return 0;
}
