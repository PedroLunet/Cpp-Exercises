#include <iostream>
#include <fstream> 
#include <string>

using namespace std;


/**
 *  reads and prints the file f
 *  param: string f is the name of the file
 *  return: -1 if error, 0 if everything ok 
 */
int print_file(string f){
    ifstream file(f)
        if (!file){
            return -1;
        }
    string line, word;
        while(getline (file, line)){
            cout << line;
            cout << endl;
        }
    return 0;
}

/**
 *  counts and prints the number of chars in file f
 *  param: string f is the name of the file
 *  return: -1 if error, 0 if everything ok 
 */
int count_characters(string f) {
    ifstream file(f);
  if (!file){
      return -1;
  }
  int i = 0;
  char ch;
    while(file.get(ch)){
        i = i + 1;
    }
    cout << "The total number of characters is " << i << endl;
    return 0;
}


/**Test code. Do not change**/

int main() {
	print_file();
    count_characters();
    return 0;
}

