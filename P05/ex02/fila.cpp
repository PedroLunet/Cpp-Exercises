/*****************************************************************/
/*                 Fila | ESDA | LEEC | 2022/23                  */
/*****************************************************************/


#include <iostream>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

int pos_maior_elemento(queue<char> fila)
{ 
    // alínea a)
    // função que devolve a posição do maior elemento presente numa fila.
    if((int) fila.size() == 0)
        return 0;
    else{
    vector <char> vst;
    int sz = (int) fila.size();
    while(!fila.empty()){
        vst.push_back(fila.front());
        fila.pop();
    }
    int i = 0, max_pos;
    char st;
    st = vst[i];
    while(i < sz){
        if(vst[i] > st){
            st = vst[i];
            max_pos = i + 1;
        }
        i++;
    }
    return max_pos; 
    }
}
int insere_na_posicao(queue<char>* fila, char elem, unsigned int pos)
{ 
	// alínea b)
	// função que insere elemento elem na posicao pos numa fila.
	// retorna 0 se conseguiu, -1 se não conseguiu. 

	return 0;
	
}