#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

/*** problema 2.1 ***/
int  contar_apelidos(queue<string> f)
{
	int i = 0;
	string st;
	while(!f.empty()){
		st = f.front();
		if((int)st.find(" ") != -1){
			i++;
		}
		f.pop();
	}	
	
	return i;
}

/*** problema 2.2 ***/

list<string> lista_a_j (queue<string>& f )
{
    list <string> aux;
	vector <string> vst;
	int i = 0;
	while(!f.empty()){
		if(f.front()[0] <= 'J')
		vst.push_back(f.front());
		f.pop();
	}
	
	while(!vst.empty()){
		aux.push_back(vst[i]);
		vst.pop_back();
		i++;
	}
	return aux;

	
	
} 

int print_list(list<string> l)
{
  if (l.empty())
  return -1;
  for(auto it=l.begin();it!=l.end();it++)
  {
     cout << (*it) << endl;
  }
 
  return 0;
}



int main()
{
	
	/* testes */
	queue<string> f;
	f.push("Maria");
	f.push("João Teixeira");
    f.push("Júlia Costa");
	f.push("Henrique");
	f.push("Afonso Costa");
	f.push("Nuno Antunes");


	int ve;
	/* inicio teste prob2.1 */
	ve = contar_apelidos(f);
	if(ve==4) { 
		cout <<"Numero de pessoas com apelidos correto: 4"<<endl;		
	} else
		cout <<"Numero de pessoas com apelidos errado (numero:"<< ve<<" esperado: 4)"<<endl;
	/* fim teste prob2.1 */

	/* inicio teste prob2.2 */
	list<string> l;
  l=lista_a_j (f);
   print_list(l);
		
	/* fim teste prob2.2 */


	return 0;
}
