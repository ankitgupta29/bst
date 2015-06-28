#include<iostream>
#include<stdlib.h>
#include<list>

using namespace std;

class Graph {
	
	int V; //no of vertices
	list<int> *adj; //adjacency list
	void print_visited(int v, bool visited[]);
	
	public:
		Graph(int v) {
			V = v;
			adj = new list<int>[v];
		}
		
		void addEdge(int v, int w) {
			adj[v].push_back(w);
		}
		void DFS(int v) { // DFS travel of the graph reacheable from v
			int i;
			bool *visited = new bool[V];
			for (i = 0; i < V; i++)
				 visited[i] = false;
		
			// Call the recursive helper function to print DFS traversal
			// starting from all vertices one by one
			for(i = 0; i < V; i++)
				if(visited[i] == false)
					print_visited(v, visited);
		}
};
	
	
void Graph:: print_visited(int v, bool visited[])
{
	list<int>:: iterator i;
	visited[v] = true;
	cout << v << " ";
	
	for(i = adj[v].begin(); i != adj[v].end(); i++)
	{
		if (visited[*i] != true)
			print_visited(*i, visited);
	}
}

int main()
{
    // Create a graph given in the above diagram
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}

