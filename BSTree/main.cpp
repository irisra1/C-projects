#include "BsTree.h"

int main(void)
{
  //Node* node = new Node;
  BsTree test;
  test.InsertInt(10);
  test.InsertInt(5);
  test.InsertInt(12);
  test.InsertInt(3);
  test.InsertInt(7);
  test.InsertInt(11);
  test.InsertInt(15);
  test.InsertInt(1);
  test.InsertInt(9);
  test.InsertInt(17);
  
  Node* root = test.getRoot();
  test.printSorted(root);
  test.findNode(1, root);
  test.findNode(17, root);
  test.findNode(4, root);
  
  return 0; 
}