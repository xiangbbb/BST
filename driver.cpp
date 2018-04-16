/*Name:Junxiang Liu
///Date: 4/15/2018
/File: driver.cpp
//Description: Binary search tree
*/
#include "binary_search_tree.h"
using namespace std;
int main(){
  Node tree;
  string file_name, ofname, dname, fname;
  int choice;
  while(choice != 8){
    cout << "Welcome to BST!"
	 << "You may select one of the following options:" << endl;
    cout << "1 Read the file" << endl;
    cout << "2 Write the file" << endl;
    cout << "3 Print the BST" << endl;
    cout << "4 Delet one item" << endl;
    cout << "5 Find the max word" << endl;
    cout << "6 Find the min word" << endl;
    cout << "7 Find one item with name" << endl;
    cout << "8 Exit this program" << endl;
    cin >> choice;
    cout << endl;
    if(choice == 1){
      cout << "What file name want to input?" << endl;
      cin >> file_name;
      tree.read_file(file_name);
    }
    else if(choice == 2){
      cout << "What file name you want to write?" << endl;
      cin >> ofname;
      tree.save_file(ofname);
    }
    else if(choice == 3){
      tree.print();
    }
    else if(choice == 4){
      cout << "What name of item you want to delete? " << endl;
      cin >> dname;
      tree.deletes(dname);
    }
    else if(choice == 5){
      tree.max();
    }
    else if(choice == 6){
      tree.min();
    }
    else if(choice == 7){
      cout << "What item you want to find?" << endl;
      cin >> fname;
      int num = tree.find(fname);
      cout << "Number of this key: " << num << endl;
    }
    else if(choice == 8){
      cout << "EXIT!" << endl;
    }

  }
  return 0;
}
