#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int print_vet(vector<int> v)
{
  cout << "[ " ;   
  for(int i=0;i<(int)v.size();i++)
  {
     cout << v[i] << ' ';
  }
  cout<<"]" << endl;
  return 0;
}
int print_pilha(stack<int> s)
{
  cout << "cromos:[ " ;   
 while (!s.empty())
  {   cout << s.top() << ' ';
        s.pop();
  }
  cout<<"]" << endl;
  return 0;
}

vector<int> junta_colecoes(vector<int>& cromos1, vector<int>& cromos2)
{
    vector <int> vc;
    int i = 0, ii = 0;
    while(i < (int)cromos1.size()){
        if(find(vc.begin(), vc.end(), cromos1[i]) == vc.end()){
        vc.push_back(cromos1[i]);
        }
        i++;
    }

    while(ii < (int)cromos2.size()){
        if(find(vc.begin(), vc.end(), cromos2[ii]) == vc.end()){
            vc.push_back(cromos2[ii]);
        }
        ii++;
    }
    sort(vc.begin(), vc.end());
    return vc;
}
void juntar_repetidos(stack<int>& cromos, vector<int> acrescentar)
{
    if (cromos.empty() || acrescentar.empty())
    {
        return;
    }
    stack <int> aux;
    int i = 0;
    while(!cromos.empty()){
        if(acrescentar[i] == cromos.top()){
            aux.push(cromos.top());
            aux.push(acrescentar[i]);
            cromos.pop();
            i++;
        }
        else{
            aux.push(cromos.top());
            cromos.pop();
        }
    }
    
    while(!aux.empty()){
        cromos.push(aux.top());
        aux.pop();
    }
}

int main()
{
    // teste ao ex1.1
    vector<int>  colecao1{2,4,5,6,5,4,10,11,10,10};
	vector<int>  colecao2{3,4,6,9,12};
    vector<int>  ve;
    ve.clear();
    ve = junta_colecoes(colecao1, colecao2);
	if(!ve.empty()) { 
		if (ve.size()==9) cout << "\nNúmero de cromos na nova coleção: 9 (Certo)"<<endl;
		else cout << "\nNúmero de cromos na nova coleção :"<<ve.size()<<" (errado, tem que dar 9)"<<endl;
		cout << "Lista da nova coleção: ";
        print_vet(ve);
    }


    //teste ex1.2
    stack<int> cro;

    cro.push(24);
    cro.push(5);
    cro.push(35);
    cro.push(11);
    cro.push(6);
    cro.push(2);

	
	vector<int> repetidos{5,34,24};
		
	juntar_repetidos(cro, repetidos);
	stack<int> cro1;
    print_pilha(cro);
	/*if(cro.size()==8)
	{
		int ele;
        cro1=cro;
        cro.pop();
        cro.pop();
        cro.pop();
        cro.pop();
        ele=cro.top();
        cro.pop();
		if (ele!=5 || cro.top()!=5) {
				cout<<"O cromo numero 5 não foi inserido no local correto"<<endl;

		} else {
			 cro.pop();
        ele=cro.top();
        cro.pop();
			if (ele!=24 || cro.top()!=24) {
				cout <<"O cromo numero 24 não foi inserido no local correto"<<endl;

			} else { cout<<"Os cromos foram inseridos nos locais corretos"<<endl ;}
		}
		
		
		
	
			
	}
	else
		cout<<"pilha com tamanho errado (tamanho: "<<cro.size()<<"; esperado: 8)"<<endl;
		print_pilha(cro1);
*/	
}