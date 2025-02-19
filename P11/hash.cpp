#include "hash.hpp"



HashMapTable::HashMapTable(int ts){ // Constructor -- creating the hash table
    this->table_size = ts;
    table = new list<string>[table_size];
}

int HashMapTable::hashFunction(string key) { // HASH function
    return (key.length() % table_size);
}

int HashMapTable::hashFunctionkrm(string key){ // New hash function
    //ALINEA A)
    int hash = 7;
    for(int i = 0; i < (int)key.length(); i++){
        hash = hash + key[i];
    }
    return hash % table_size;
}

void HashMapTable::insertElement(string key, int func){ // insert - push the keys in hash table
    if(func == 0){
        int index = hashFunction(key);
        table[index].push_back(key);

    } else if (func == 1){
        int index = hashFunctionkrm(key);
        table[index].push_back(key);
    }

    
}


int HashMapTable::search_value(string key, int func){ 
    // ALINEA B)

}


void HashMapTable::deleteElement(string key, int func){ // delete element from the hash table
    // ALINEA C) 
}


void HashMapTable::displayHashTable() {
    //for (inti = 0; i<table_size; i++) {
    for (int i = 0; i<table_size; i++) {
        cout<<i;
        // traversing at the recent/ current index
        for (auto j : table[i])
            cout<< " ==> " << j;
            cout<<endl;
    }
    
}


int HashMapTable::count_words_starting_char(char c){
    //ALINEA E
} 





