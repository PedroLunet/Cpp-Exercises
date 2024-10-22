/*****************************************************************/
/*   Grafo c/ lista de adjacencias | ESDA | LEEC | 2022/23      */      
/*****************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "graph.hpp"

Graph::Graph(int v)
{
    if (v > 0) {
        this->v = v; // atribui o número de vértices
        this->adj.resize(v);
    }
}

int Graph::addEdgeUndirected(int v1, int v2)
{
 
    if ((v1 >= 0 && v1 < v) && (v2 >= 0 && v2 < v)) {
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        return 0;
    } 
    return -1;
}

int Graph::identifies_substation()
  {
   
    /*responder aqui*/
  
}
int Graph::substation_complete()

{
   /*responder aqui*/

}
void Graph::print()
{
    for(int i=0; i < this->v; i++){
        cout << i << " -> ";
        for(auto it : this->adj[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}

