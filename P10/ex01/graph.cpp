/*****************************************************************/
/*   Grafo c/ listas de adjacencias | ESDA | LEEC | 2022/23      */      
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

int Graph::addEdgeDirected(int v1, int v2)
{
    /* Alinea 1.a */
    if(v1 < 0 || v2 < 0){
        return -1;
    }
    else{
        adj[v1].push_back(v2);
        return 0;
    }
}

int Graph::removeEdge(int v1, int v2)
{
    /* Alinea 1.a */
    if(v1 < 0 || v2 < 0){
        return -1;
    }
    else{
        for(auto it = adj[v1].begin(); it != adj[v1].end(); it++){
            if(*it == v2){
                adj[v1].remove(v2);
                return 1;
            }
        }
        return 1;
    }   
}

bool Graph::existsNeighbor(int v1, int v2)
{
    /* Alinea 1.a */
        if(v1 < 0 || v2 < 0){
        return false;
    }
    else{
        for(auto it = adj[v1].begin(); it != adj[v1].end(); it++){
            if(*it == v2){
                return true;
            }
        }
        return false;
    }
}


int Graph::outDegree(int v)
{
    /* Alinea 1.b */
	return (int)adj[v].size();
}

vector<list<int>> Graph::transposeGraph()
{
    /* Alinea 1.c */
    int size = adj.size();
    vector<list<int>> gt(size);
    for(int i = 0; i < size; i++){
        for(auto it = adj[i].begin(); it != adj[i].end(); it++){
            gt[*it].push_back(i);
        }
    }
    return gt;
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

void Graph::print(vector<list<int>> vet)
{
    for(int i=0; i < (int)vet.size(); i++){
        cout << i << " -> ";
        for(auto it : vet[i]){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;
}


