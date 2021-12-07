#include <bits/stdc++.h>
using namespace std;


/*
Following are the detailed steps.
Input: Graph and a source vertex src 
Output: Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.
1) This step initializes distances from the source to all vertices as infinite and distance to the source itself as 0. Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.
2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph. 
…..a) Do following for each edge u-v 
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v] 
………………….dist[v] = dist[u] + weight of edge uv
3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v 
……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle” 
The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle
How does this work? Like other Dynamic Programming Problems, the algorithm calculates shortest paths in a bottom-up manner. It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. The idea is, assuming that there is no negative weight cycle, if we have calculated shortest paths with at most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges (Proof is simple, you can refer this or MIT Video Lecture)
Example 
Let us understand the algorithm with following example graph. The images are taken from this source.
Let the given source vertex be 0. Initialize all distances as infinite, except the distance to the source itself. Total number of vertices in the graph is 5, so all edges must be processed 4 time








*/



int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector <int> dis(n,INT_MAX);
	    dis[0]=0;
	    int edge=edges.size();
	    
	    for(int i=0;i<n-1;i++){
	        for(int j=0;j<edge;j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            if(dis[u]==INT_MAX){
	                continue;
	            }
	            if(dis[u]+wt<dis[v]){
	                dis[v]=dis[u]+wt;
	            }
	        }
	    }
	      for(int j=0;j<edge;j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            if(dis[u]+wt<dis[v]){
	                return 1;
	            }
	        }
	        return 0;
	    
	    
	}



