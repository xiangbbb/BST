/*Name: Junxiang Liu
//Date: 4/15/2018
/File: binary_search_tree.h
//Description: Binary search tree
*/
#ifndef binary_search_tree_H
#define binary_search_tree_H

#include <iostream>
#include <fstream>
#include <string>

class Node{
 private:
  Node *left, *right, *root;
  std::string key;
  int data;
  void insertHelper(Node *current, std::string name, int num);
  /*
  //Description:
  //     Help insert
  //Inputs:
  //   Node *current, string name, int num
  */
  void printHelper(Node *current);
  /*
  //Description:
  //     Help print 
  //Inputs:
  //   Node *current
  */
  void deleteHelper(Node * &current, std::string n);
  /*
  //Description:
  //     Help delete
  //Inputs:
  //   Node * &current, string n
  */
  void save_file_Helper(Node *current, std::ofstream& ofile);
  /*
  //Description:
  //     Help save to file
  //Inputs:
  //   Node *current, ofstream& ofile
  */
 public:
  Node(std::string key, int data);
  /*Description: 
  //      Parameter constrcutor
  //Inputs:
  //      string name, int data
  */
  Node();
  //Description:
  //     Constructor
  ~Node();
  //Description::
  //        Destructor
  void read_file(std::string n);
  /*
  //Description:
  //     Read the file and count the words
  //Inputs:
  //   string n
  */
  void set(std::string s, int n);
  /*
  //Description: 
  //    insert to BST by order
  //Inputs:
  //      string s, int n
  */
  int find(std::string s);
  /*
  //Description:
  //    Input the name and return number of that word
  //Inputs:
  //    string s
  //Return:
  //     The value of word
  */
  void print();
  /*
  //Description:
  //   Print BST orderly
  */
  void min();
  /*
  //Description:
  //      Find the min word
  */
  void max();
  /*
  //Description:
  //      Find the min word
  */
  void deletes(std::string s);
  /*
  //Description:
  //    Input the name and delete that item
  //Inputs:
  // string s
  */
  void save_file(std::string n);
  /*
  //Description:
  //     Save BST to file
  //Inputs:
  //   string m
  */
  void destructorHelper(Node *current);
  /*
  //Description:
  //    Remove Node
  */
};

#endif // binary_search_tree_H
