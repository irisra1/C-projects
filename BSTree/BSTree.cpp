#include "BsTree.h"
BsTree::BsTree()
{
  cout << "constructed" << endl;
  root = nullptr;
}

BsTree::~BsTree()
{
  cout << "destroyed" << endl;
  deleteTree(root);//calls delete tree to delete the tree
}

void BsTree::deleteTree(Node* curr)
{
  if(!curr->left && !curr->right)//if it's a leaf
  {
   cout << "deleted value:" << curr->data << endl;
   delete curr;
   return;
  }
  if(curr->left)
  {
    cout << "went left" <<endl;
    deleteTree(curr->left);
  }
  if(curr->right)
  {
    cout << "went right" <<endl;
    deleteTree(curr->right);
  }
  cout << "deleted value:" << curr->data << endl;
  delete curr;
}
Node* BsTree::getRoot() const
{
  return root;
}

void BsTree::InsertInt(int a)
{
  //make a new node
  Node* node = new Node;
  //set data and pointers
  node->data = a;
  node->left = nullptr;
  node->right = nullptr;
  //if the root doesn't exist set node as the root
  if(!root)
  {
    root = node;
  }
 //if it does call insertNode to add the node to the tree 
 else 
  {
    InsertNode(node, root);
  }
}

void BsTree::InsertNode(Node* node, Node* curr)
{
  //check against current node(greater or less than)
  if (curr->data >= node->data)
  {
    if(curr-> left == nullptr)
    {
      curr-> left = node;
      return;
    }
    else
    {
     InsertNode(node, curr->left); 
    }
  }
  else
  {
   if(curr-> right == nullptr)
   {
     curr->right = node;
     return;
   }     
   else
   {
     InsertNode(node, curr->right);
   }
  }
  //check if child is empty 
  //if it is place as child node 
  //if not recurse futher down the tree 
}


void BsTree::printSorted(Node* curr)//works until we end up with one node on the right and none on the left
{
  //cout << "start function" << endl;
  if(!curr->left && !curr->right)
  {
    cout << "end data:" << curr->data << endl;
    //cout << "returned" << endl;
    return;
  }
  else if(curr->left)
  {
    //cout << "recursed l" << endl;
    printSorted(curr->left);
  }

  cout << "mid data:" << curr->data << endl;
  
  if(curr->right)
  {
    printSorted(curr->right);
  }

  //print left, print self, print right
  //basically we want to check if the left is a null ptr 
  //so if it's not we're gonna want to recurse
  // once it is we're gonna want to print stuff   
}

Node* BsTree::findNode(int a, Node* curr)
{
  cout << "finding node" << endl;
  if(curr->data == a)
  {
    cout << a << "=" << curr->data << endl;
   return curr;
  }
  else if(a < curr->data && curr->left)
  {
    cout << "a = " << a << endl;
    cout << "data = " << curr->data <<endl;
    cout << "went left" << endl;
    return findNode(a, curr->left);
  }
  else if(a > curr->data && curr->right)
  {
    cout << "a = " << a << endl;
    cout << "data = " << curr->data <<endl;
    cout << "went right" << endl;
    return findNode(a, curr->right);
  }
  //if not return a null pointer  
  else
  {
    cout << "No node found" << endl;
    return nullptr; 
  }
}