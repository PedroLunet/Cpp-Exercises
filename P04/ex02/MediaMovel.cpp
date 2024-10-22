#include <iostream>
#include "MediaMovel.h"
using namespace std;

MediaMovel::MediaMovel(double n_elem) : n_elementos(n_elem) {}

// Alínea a)
void MediaMovel::update(double valor)
{
  valores.push_back(valor);
  n_elementos = valores.size();
}

// Alínea b)
double MediaMovel::getMediaMovel() const
{
  auto it = valores.begin();
  double sum = 0;
  while(it != valores.end()){
    sum = sum + *it;
  }
  return sum / valores.size();
}
