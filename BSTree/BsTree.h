#pragma once //make sure file is only included once
#include <iostream> //cout

using namespace std;

struct Node
{
  int data;
  Node* left;
  Node* right;
};
//////////////////////////////////////////////////////

class BsTree
{
  public:
  BsTree();
  ~BsTree();
  
  void InsertInt(int a); //Insert the given int into the tree.
  void printSorted(Node* curr);// prints node data in order of least to greatest
  Node* findNode(int a, Node* curr);// finds node with value of a and returns the pointer to it's node
  Node* getRoot() const;
  private:
  Node* root;
  void InsertNode(Node* node, Node* curr);// inserts a node into the tree
  void deleteTree(Node* curr);
};