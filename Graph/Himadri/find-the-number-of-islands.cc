// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/

#define COL 50
int n, m;

bool isvalid(int row, int col, vector<int> graph[], bool visited[][COL]){
  if(row<n && row>=0 && col <m && col>=0 && graph[row][col] && !visited[row][col]) return true;
  return false;
}

void dfs(int row,int col, vector<int> graph[], bool visited[][COL]) {
    if(visited[row][col]) return;

    visited[row][col] = true;
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int k = 0; k < 8; ++k)
        if (isvalid(row + rowNbr[k], col + colNbr[k], graph, visited))
            dfs(row + rowNbr[k], col + colNbr[k], graph, visited);
}

int findIslands(vector<int> A[], int N, int M)
{
    int island=0;
    n = N; m = M;
    bool visited[N][COL] = {false};

    // Your code here
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(!visited[i][j] && A[i][j]==1){
                island++;
                dfs(i, j, A, visited);
            }
        }
    }
    return island;

}



// { Driver Code Starts.

int main() {

	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}  // } Driver Code Ends
