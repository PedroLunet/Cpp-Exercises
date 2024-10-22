#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int adicionar(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> *pq, string file_name)
{
  // alínea a)
  int result = -1;
  string driver;
  int i = 1;
  if(pq != nullptr && file_name != ""){
    ifstream file (file_name);
      if(file){
        while(getline(file, driver)){
          pq->push(make_pair(i, driver));
          i++;
        }
        result = pq->size();
      }
  }
  return result;
}

void imprimir(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> *pq, int pos_ini, int pos_fin)
{
  // alínea b)
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq_aux;
  int size = pq->size();
  cout << "Pilotos entre a posição " << pos_ini << " e a posição " << pos_fin << ":" << endl;
  for(int i = 1; i<= size; i++)
  {
    if((i >= pos_ini) && (i <= pos_fin))
    {
        cout << "#" << pq->top().first << "\t" << pq->top().second << endl;
    }
    pq_aux.push(pq->top());
    pq->pop();
  
  }
  cout << endl;
  for(int i = 1; i<= size; i++)
  {
    pq->push(pq_aux.top());
    pq_aux.pop();
  }
  cout << endl;
}

string seleciona_por_ordem(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> *pq, int k)
{
  // alínea c)
string resultado = "";
  if((pq) && (k >= 1) && (k <= (int)pq->size()))
  {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq_aux;
    int initial_size = pq->size();

    for(int i=1; i <= initial_size; i++)
    {
      if(i == k)
      {
        resultado = pq->top().second;
      }
      pq_aux.push(pq->top());
      pq->pop();
    }

    for(int i=1; i <= initial_size; i++)
    {
      pq->push(pq_aux.top());
      pq_aux.pop();
    }
  }
  return(resultado);
}

int coloca_na_ordem(priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> *pq, string piloto, int k)
{
  // alínea d)
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq_aux;
  int result = 0;
  for(int i = 0; i <= (int)pq->size(); i++){
    if(i == k){
      pq_aux.push(make_pair(i, piloto));
      result = 1;
    }
    pq_aux.push(pq->top());
    pq->pop();
  }
  return result;
}

int main()
{

 priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> drivers;

  int n_pilotos = adicionar(&drivers, "drivers.txt");
  cout << "Foram adicionados " << n_pilotos << " pilotos." << endl; 

  imprimir(&drivers, 1, 10);

  cout << "Teste seleciona_por_ordem:" << endl;

  vector<int> positions{1, 7, 9, 34, 65, 120, 700, 1345, 0};

  string piloto;
  for(int i = 0; i < positions.size(); i++)
  {
    piloto = seleciona_por_ordem(&drivers, positions[i]);
    if(piloto == "")
    {
      cout << "Posição " <<  positions[i] << " da lista não existe." << endl;
    }
    else
    {
      cout << "Posição " <<  positions[i] << " da lista é: " << seleciona_por_ordem(&drivers, positions[i]) << endl;
    }
  }

  cout << "Teste coloca_na_ordem:" << endl;
  
  vector<pair<int, string>> novas_colocacoes{{89, "Piloto 1"}, {93, "Piloto 2"}, {101, "Piloto 3"}, {1016, "Piloto 4"}};

  int resultado;

  for(int i = 0; i < novas_colocacoes.size(); i++)
  {
    resultado = coloca_na_ordem(&drivers, novas_colocacoes[i].second, novas_colocacoes[i].first);
    if(resultado)
    {
      cout << "Colocação do piloto " << novas_colocacoes[i].second << " na posição " << novas_colocacoes[i].first << " conseguida" << endl;
      imprimir(&drivers, novas_colocacoes[i].first-5, novas_colocacoes[i].first+5);
    }
    else
    {
      cout << "Colocação do piloto " << novas_colocacoes[i].second << " na posição " << novas_colocacoes[i].first << " não conseguida" << endl;
    }

  }
  cout << "Tamanho final da lista de prioridades de pilotos: " << drivers.size() << endl;

  return 0;
}


