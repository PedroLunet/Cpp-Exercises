#include <iostream>

using namespace std;

class Aluno
{
public: // Porque e', para ja', importante? Experimente comentar a linha...
  string nome;
  string curso;
  int numero;
  float media;
  
  Aluno(string nom)
  { /* completar (alinea a)) */
    nome = nom;
    curso = "";
    numero = 0;
    media = 0;
  }
  
  Aluno(string nom, string cur, int num)
  { /* completar (alinea a)) */
    nome = nom;
    curso = cur;
    numero = num;
    media = 0;
  }

  /* completar (alinea b)) */
  void setCurso(string cur)
  {
    curso = cur;
  }

  void setMedia(float med)
  {
    media = med;
  }

  string getCurso(){
    return curso;
  }

  string getNome(){
    return nome;
  }

  int getNumero(){
    return numero;
  }

  float getMedia(){
    return media;
  }

  /* completar (alinea c)) */
  void imprimir (ostream & os) const 
  {
    os << "\t" << nome << "\t| " << curso << "\t| " << numero << "\t| " << media << endl;
  }

  /* completar (alinea d)) */

};

int main()
{

  Aluno a1("Pedro Ferreira", "Engenharia", 2020123);
  Aluno a2("Ana Martins", "Direito", 2022045);
  Aluno a3("Manuel Silva", "Arquitetura", 2021033);
  Aluno a4("Alberto Mateus", "Engenharia", 2019197);

  /* completar (alinea b)) */
  a1.setCurso("Medicina");
  a1.setMedia(14.2);
  a2.setMedia(11.3);
  a3.setMedia(12.6);
  a4.setMedia(19.4);


  cout << "Lista de alunos: (nome | curso | numero | media)" << endl;
  cout << "\t" << a1.nome << "\t| " << a1.curso << "\t| " << a1.numero << "\t| " << a1.media << endl;
  cout << "\t" << a2.nome << "\t| " << a2.curso << "\t| " << a2.numero << "\t| " << a2.media << endl;
  cout << "\t" << a3.nome << "\t| " << a3.curso << "\t| " << a3.numero << "\t| " << a3.media << endl;

  /* completar (alinea c)) */ 
  a4.imprimir(cout);
  /* completar (alinea d) */

  return 0;
}
