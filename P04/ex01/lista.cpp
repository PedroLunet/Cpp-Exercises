#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main()
{

  // a) criar a lista 
    list <string> lst_jogos;
  // b) inserir jogos na lista
    ifstream file("arquivo.txt");
    string line;
    while(getline(file, line)){
        lst_jogos.push_back(line);
    }
  // c) imprimir tamanho da lista
    cout << "Foram carregados " << lst_jogos.size() << " jogos." << endl;
  // d) imprimir conteúdo da lista
    cout << "Conteúdo da Lista:" << endl;
    int i = 0;
    auto it = lst_jogos.begin();
    while (it != lst_jogos.end()){
        cout << "Pos " << i << " -> " << *it << endl;
        it++;
        i++;
    }

  // e) ordenar lista e imprimir
    cout << "\nLista Ordenada:" << endl;
    int i = 0;
    lst_jogos.sort();
    auto it = lst_jogos.begin();
    while (it != lst_jogos.end()){
        cout << "Pos " << i << " -> " << *it << endl;
        it++;
        i++;
    }

  // f) remover "Mario Kart (Wii)" e imprimir
    cout << "\nLista sem o jogo Mario Kart (Wii):" << endl;
    int i = 0;
    auto it = lst_jogos.begin();
    lst_jogos.remove("Mario Kart (Wii)");
    while (it != lst_jogos.end()){
        cout << "Pos " << i << " -> " << *it << endl;
        it++;
        i++;
    }
  // g) remover jogos PS2 e imprimir
    int pos = 0;
    cout << "Lista sem jogos da PS2:" << endl;
        for(auto it = lst_jogos.begin(); it != lst_jogos.end(); it++){
            if ((int )(*it).find( "(PS2)") != -1)
            {
               it = lst_jogos.erase(it);
            }
            cout << "Pos " << pos <<" -> " << *it << endl;
            pos++;
        }

  return 0;
}