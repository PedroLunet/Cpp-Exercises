/*****************************************************************/
/*   Grafo c/ lista de adjacencias | ESDA | LEEC | 2022/23      */      
/*****************************************************************/

#include <iostream>
#include <vector>
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
    /* Alinea 2.a */
    if(v1 < 0 || v2 < 0){
        return -1;
    }
    else{
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
        return 0;
    }
}

int Graph::identifyOverload() {

    /* Alinea 2.b */
    int result = 0;
    int flag = 0;
    int size = adj.size();
    for(int i = 0; i < size; i++){
        if((int)adj[i].size() >= flag){
            flag = adj[i].size();
            result = i;
        }   
    }
    return result;
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

