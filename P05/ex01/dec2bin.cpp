#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

string dec2bin(int n_decimal)
{
  // alinea b)
    stack <int> stack;
    string bin = "";
    while(n_decimal > 0){
        int res = n_decimal % 2;
        stack.push(res);
        n_decimal = n_decimal / 2;
    }
    
    while(!stack.empty()){
        bin = bin + to_string(stack.top());
        stack.pop();
    }
    
    return bin;
  return "";
}

// Não alterar:
int main()
{
  string n_decimal;

  cout << "Introduza número decimal: ";
  getline(cin, n_decimal);

  cerr << "Representação binária: " << dec2bin(stoi(n_decimal)) << endl;

  return 0;
}
