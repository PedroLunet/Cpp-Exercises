#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    // Asks user for the first string s1
    cout << "First String: ";
    // Stores the first string
    cin >> s1;
    // Asks user for the second string s2
    cout << "Second String: ";
    // Stores the second string
    cin >> s2;
    // (a) Create new string s3 that is the concatenation of s1 and s2.
    string s3 = s1 + s2;
    cout << "Concatenation: " << s3 << endl;
    // (b) Calculate and print number of chars in s3.
    cout << "The lenght of the string is: " << s3.size() << endl;
    // (c) Print char 2 of s3.
    cout << "2nd char: " << s3[1] << endl;
}  
