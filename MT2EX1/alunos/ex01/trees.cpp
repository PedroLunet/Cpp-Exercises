#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "trees.hpp"

using namespace std;

Node::Node(string item)
{
    this->item = item;
    left = NULL;
    right = NULL;
    height = 0; // new node is initially
                // added at leaf
}

BSTree::BSTree()
{
    root = NULL;
}

Node *BSTree::getRoot()
{
    return this->root;
}

void BSTree::setRoot(Node *newRoot)
{
    this->root = newRoot;
}

void BSTree::insert(string value)
{
    insert(root, value);
}

void BSTree::insert(Node *treeNode, string value)
{
    /* Alinea b */

    if (!treeNode)
    {
        treeNode = new Node(value);
        
        root = treeNode;
    }
    else
    {
        if (value < treeNode->item)
        {
            if (!treeNode->left)
            {
                Node *treeTemp = new Node(value);

                treeNode->left = treeTemp;
            }
            else
                insert(treeNode->left, value);
        }
        else
        {
            if (!treeNode->right)
            {
                Node *treeTemp = new Node(value);
    
                treeNode->right = treeTemp;
            }
            else
                insert(treeNode->right, value);
        }
        // Update the height of the node
        treeNode->height = 1 + max(getHeight(treeNode->left),
                        getHeight(treeNode->right));

    }
}

/* Calcula a altura da árvore a partir de um nó */
int BSTree::getHeight(Node *treeNode)
{
    int result;
    if (treeNode == NULL)
    {
        result = -1;
    }
    else
    {
        if ((treeNode->left == NULL && treeNode->right == NULL))
        {
            result = 0;
        }
        else
        {
            if (getHeight(treeNode->left) > getHeight(treeNode->right))
            {
                result = (1 + getHeight(treeNode->left));
            }
            else
            {
                result = (1 + getHeight(treeNode->right));
            }
        }
    }
    return(result);
}


Node* BSTree::searchItem(string item)
{
    Node* result = nullptr;
    
    if((item != "") && (this->getRoot()))
    {
        result = searchItem(this->getRoot(), item);
    }
    return(result);
};

Node* BSTree::searchItem(Node* treeNode, string item)
{
    //alínea a)
    if(treeNode == nullptr){
        return nullptr;
    }
    else{
        if(treeNode->item == item){
            return treeNode;
        }
        else{
            if(treeNode->item > item){
                return searchItem(treeNode->left, item);
            }
            else{
                return searchItem(treeNode->right, item);
            }
        }
    }
}   



int BSTree::getDepth(string item)
{
    int result = -1;
    if ((this->root) && item != "")
    {
        result = getDepth(this->root, item);
    }
    return(result);
};

int BSTree::getDepth(Node* treeNode, string item)
{
    //alínea c)
    int result = -1;
    if(treeNode->item == item)
    {
        result = 0;
    }
    else
    {
       if(item < treeNode->item)
       {
            result = getDepth(treeNode->left, item);
       }
       else
       {
            result = getDepth(treeNode->right, item);
       }
       if(result != -1)
       {
        result++;
       }
    }
    return(result); 
};

/* Imprime a arvore */
void BSTree::printTree(Node *treeNode)
{
    if (treeNode != NULL)
    {
        cout << treeNode->item << "   depth: " << getDepth(treeNode->item) << endl;
        printTree(treeNode->left);
        printTree(treeNode->right);
    }
}

bool BSTree::isSuccessor(string item1, string item2)
{
    //alínea b)
        if(item1 == "" || item2 == ""){
        return false;
    }
    else{
        Node* node = searchItem(this->getRoot(), item2);
        if(searchItem(node->left, item1)){
            return true;
        }
        if(searchItem(node->right, item1)){
            return true;
        }
        else{
            return false;
        }
    }
}

string BSTree::getLongestBranch()
{
    string result = "";
    if(this->getRoot())
    {
        result = getLongestBranch(this->getRoot());
    }
    return(result);
}

string BSTree::getLongestBranch(Node* treeNode)
{
    //alínea d)
    string result = "";
    if(treeNode != nullptr){
        result = treeNode->item;
        if(getHeight(treeNode->left) >= getHeight(treeNode->right)){
            result = result + getLongestBranch(treeNode->left);
        }
        else{
            result = result + getLongestBranch(treeNode->right);
        }
    }
    return result;
}

// **************** AVL methods ********************************
//**************************************************************

string AVL::maxString(string a, string b)
{
    return (a > b)? a : b;
}

AVL::AVL()
{ 
  this->root = NULL;
}

Node* AVL::getRoot(){
    return this->root;
}

/* Calcula a altura da árvore a partir de um nó */
int AVL::getHeight(Node *node)
{
    int result;
    if (node == NULL)
    {
        result = -1;
    }
    else
    {
        if ((node->left == NULL && node->right == NULL))
        {
            result = 0;
        }
        else
        {
            if (getHeight(node->left) > getHeight(node->right))
            {
                result = (1 + getHeight(node->left));
            }
            else
            {
                result = (1 + getHeight(node->right));
            }
        }
    }
    return(result);
}

Node* AVL::rightRotate(Node *node)
{
    Node *temp = node->left;
    Node *temp2 = temp->right;
 
    // Perform rotation
    temp->right = node;
    node->left = temp2;
 
    // Update heights
    node->height = max(getHeight(node->left),
                    getHeight(node->right)) + 1;
    
    temp->height = max(getHeight(temp->left),
                    getHeight(temp->right)) + 1;
    
    // Return new root
    return temp;
}
 

Node* AVL::leftRotate(Node *node)
{
    Node *temp = node->right;
    Node *temp2 = temp->left;
 
    // Perform rotation
    temp->left = node;
    node->right = temp2;
 
    // Update heights
    node->height = max(getHeight(node->left),   
                    getHeight(node->right)) + 1;
                    //alínea a)                
    
    temp->height = max(getHeight(temp->left),
                    getHeight(temp->right)) + 1;
 
        
    // Return new root
    return temp;
}
 

int AVL::getBalance(Node *node)
{
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void AVL::insert(string item)
{
    
    if (!root)
    {
        Node* node = new Node(item);
        root = node;
    }
    else
    {
        root = insert(root, item);
    }
}

Node* AVL::insert(Node* node, string item)
{
    if (node == NULL)
    {
        node = new Node(item);
        return(node);
    }
        
    if (item < node->item)
        node->left = insert(node->left, item);
    else if (item > node->item)
        node->right = insert(node->right, item);
    else // Equal items are not allowed in BST
        return node;
 
    // Update the height of the node
    node->height = 1 + max(getHeight(node->left),
                        getHeight(node->right));
    
    
 
    // Get the balance factor
    int balance = getBalance(node);
 
    // If unbalanced
 
    // Left Left Case
    if (balance > 1 && item < node->left->item)
        return rightRotate(node);
 
    // Right Right Case
    if (balance < -1 && item > node->right->item)
        return leftRotate(node);
 
    // Left Right Case
    if (balance > 1 && item > node->left->item)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
 
    // Right Left Case
    if (balance < -1 && item < node->right->item)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    //If not unbalanced
    return node;
}

Node* AVL::searchItem(string item)
{
    Node* result = nullptr;
    if((item != "") && (this->getRoot()))
    {
        result = searchItem(this->getRoot(), item);
    }
    return(result);
};

Node* AVL::searchItem(Node* treeNode, string item)
{
    //alínea a)
    if(treeNode == nullptr){
        return nullptr;
    }
    else{
        if(treeNode->item == item){
            return treeNode;
        }
        else{
            if(treeNode->item > item){
                return searchItem(treeNode->left, item);
            }
            else{
                return searchItem(treeNode->right, item);
            }
        }
    }
}


int AVL::getDepth(string item)
{
    int result = -1;
    if ((this->root) && item != "")
    {
        result = getDepth(this->root, item);
    }
    return(result);
};

int AVL::getDepth(Node* treeNode, string item)
{
    //alínea c)
    int result = -1;
    if(treeNode->item == item)
    {
        result = 0;
    }
    else
    {
       if(item < treeNode->item)
       {
            result = getDepth(treeNode->left, item);
       }
       else
       {
            result = getDepth(treeNode->right, item);
       }
       if(result != -1)
       {
        result++;
       }
    }
    return(result);
};
 

bool AVL::isSuccessor(string item1, string item2)
{
    //alínea b)
    if(item1 == "" || item2 == ""){
        return false;
    }
    else{
        Node* node = searchItem(this->getRoot(), item2);
        if(searchItem(node->left, item1)){
            return true;
        }
        if(searchItem(node->right, item1)){
            return true;
        }
        else{
            return false;
        }
    }
}

void AVL::printTree(Node *node)
{
    if (node != NULL)
    {
        cout << node->item << "   depth: " << getDepth(node->item) << endl;
        printTree(node->left);
        printTree(node->right);
    }
}

string AVL::getLongestBranch()
{
    string result = "";
    if(this->getRoot())
    {
        result = getLongestBranch(this->getRoot());
    }
    return(result);
}

string AVL::getLongestBranch(Node* treeNode)
{
    //alínea d)
    string result = "";
    if(treeNode != nullptr){
        result = treeNode->item;
        if(getHeight(treeNode->left) >= getHeight(treeNode->right)){
            result = result + getLongestBranch(treeNode->left);
        }
        else{
            result = result + getLongestBranch(treeNode->right);
        }
    }
    return result;
}

