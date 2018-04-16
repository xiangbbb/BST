/*Name: Junxiang Liu
//Data:4/15/2018
//File:binary_search_tree.cpp
//Description: Binary search tree
*/

#include "binary_search_tree.h"

using namespace std;
#include <map>//map library
Node::Node(){
  left = NULL;
  right = NULL;
  root = NULL;
}
Node::Node(string name, int num){
  key = name;
  data = num;
}

Node::~Node(){
  destructorHelper(root);

}
void Node::destructorHelper(Node *current) {
  if(current != NULL) {
    destructorHelper(current->left);
    destructorHelper(current->right);
    delete current;
  }
}
void Node::read_file(string filename){
  ifstream ifile;
  //Open file
  ifile.open(filename.c_str());
  //Declare map 
  map<string, int> wordCount;
  while(ifile >> key){
    wordCount[key]++;;
  }
  for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it)
    {
      key = it->first;
      data = it->second;
      set(key, data);
    }
  ifile.close();
}
void Node::set(string name, int num){
  if(root == NULL){
    root = new Node(name, num);
  }
  else{
    insertHelper(root, name, num);
  }
}

void Node::insertHelper(Node *current, string name, int num){
  if(name.compare(current->key) < 0) {
    //Insert Left
    if(current->left == NULL)
      current->left = new Node(name, num);
    else
      insertHelper(current->left, name, num);
  }
  else {
    //Insert Right
    if(current->right == NULL)
      current->right = new Node(name, num);
    else
      insertHelper(current->right, name, num);
  }
}

void Node::print(){
  printHelper(root);
  cout << endl;
}

void Node::printHelper(Node *current){
  // In-order traversal.
  if(current != NULL) {
    printHelper(current->left);
    cout << current->key << endl << current->data << endl;
    printHelper(current->right);
  }
}

void Node::deletes(string name){
  deleteHelper(root, name);
}

void Node::deleteHelper(Node * &current, string name){
  //Node doesn't exist
  if(current == NULL)
    return;
  //Go left
  else if(name.compare(current->key) < 0)
    deleteHelper(current->left, name);
  //Go right
  else if(name.compare(current->key) > 0)
    deleteHelper(current->right, name);
  //Equal
  else {
    Node *temp;

    if(current->left == NULL) {
      temp = current->right;
      delete current;
      current = temp;
    }
    else if(current->right == NULL) {
      temp = current->left;
      delete current;
      current = temp;
    }
    //2 children
    else {
      temp = current->right;
      Node *parent = NULL;
      
      while(temp->left != NULL) {
	parent = temp;
	temp = temp->left;
      }

      current->key = temp->key;

      if(parent != NULL)
	deleteHelper(parent->left, parent->left->key);
      else
	deleteHelper(current->right, current->right->key);

    }//else
  }//else

}

int Node::find(string name){
  int n;
  Node *current = root;
  while(current->key != name){
    if(name.compare(current->key) < 0){
      current = current->left;
    }
    else{
      current = current->right;
    }
    n = current->data;
  }
  return n;
}

void Node::min(){
  Node *current = root;
  while(current->left != NULL){
    current = current->left;
  }
  cout << "Smallest key: " << current->key << endl;
}

void Node::max(){
  Node *current = root;
  while(current->right != NULL){
    current = current->right;
  }
  cout << "Largest key: " << current->key << endl;

}

void Node::save_file(string fname){
  ofstream ofile;
  //Open file
  ofile.open(fname.c_str());
  save_file_Helper(root, ofile);
  ofile.close();
}


void Node::save_file_Helper(Node *current, ofstream& ofile){
  if(current != NULL){
    save_file_Helper(current->left, ofile);
    ofile << current->key << endl;
    ofile << current->data << endl;
    save_file_Helper(current->right, ofile);
  }
}
