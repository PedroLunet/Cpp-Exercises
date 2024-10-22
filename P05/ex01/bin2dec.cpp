#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

int bin2dec(string n_binario)
{
  // alinea a)
    stack <int> stack;
    int i = 0;
    int n = static_cast<int>(n_binario.length());
    while (i < n){
        if(n_binario[i] == '0')
            stack.push(0);
        else
            stack.push(1);
    i++;
    }
    int result = 0;
    int exp = 0;
    while(!stack.empty()){
        result = result + stack.top() * pow(2, exp);
        stack.pop();
        exp++;
    }
    return result;
  return 0;
}

// Não alterar:
int main()
{
  string n_binario;

  cout << "Introduza número binário: ";
  getline(cin, n_binario);

  cerr << "Representação decimal: " << bin2dec(n_binario) << endl;

  return 0;
}
