#include "BinaryNode.h"
#include <string>
#include "BinarySearchTree.h"
using namespace std;

BinarySearchTree:: BinarySearchTree(){
  root = NULL;
}

BinarySearchTree::~ BinarySearchTree(){
  deleter root;
  root = NULL;
}

void BinarySearchTree:: insert(BinaryNode* n, const string& x){
  BinaryNode* node = new BinaryNode();
  node->value = x;
  if (root->value == "?"){
    root = node;
  }
  else if (node->value > n->value && n->right !=NULL){
    insert(n->right, x);
  }
  else if (node->value < n->value && n->left != NULL){
    insert(n->left, x);
  }
  else if (node->value > n->value && n->right==NULL){
    n->right = node;
  }
  else if (node->value < n->value && n->left==NULL){
    n->left = node;
  }
}
void BinarySearchTree:: insert(const string& x){
  insert(root, x);
}

BinaryNode* BinarySearchTree :: remove( BinaryNode*& n,const string& x){
  //remove when found
  if (n->value == x) {
    delete n;
    n = NULL;
    return NULL;
  }
  
  else if (n->value > x && n-> left != NULL){
    remove(n->left, x);
  }
  else if (n->value < x && n->left != NULL){
    remove(n->right, x);
  }
  else if (n->left== NULL && n->right==NULL){
    return NULL;
   
}
}
void BinarySearchTree :: remove(const string & x) {
  remove(root, x);
}
void showTrunks(Trunk* p) {
  if (p == nullptr) return;
  showTrunks(p->prev);
  cout << p->str;
}
void BinarySearchTree :: printTree() {
  printTree(root, NULL, false);// Recursive function to print binary tree
// It uses inorder traversal
void BinarySearchTree::printTree(BinaryNode* root, Trunk* prev, bool isRight) {
  if (root == NULL) return;

  string prev_str = "    ";
  Trunk* trunk = new Trunk(prev, prev_str);

  printTree(root->right, trunk, true);

  if (!prev)
    trunk->str = "---";
  else if (isRight) { // github user @willzhang05 pointed out that I forgot to change this from isLeft to isRight on my first commit
    trunk->str = ".---";
    prev_str = "   |";
  } else {
    trunk->str = "`---";
    prev->str = prev_str;
  }

  showTrunks(trunk);
  cout << root->value << endl;

  if (prev) prev->str = prev_str;
  trunk->str = "   |";

  printTree(root->left, trunk, false);
}
}// Recursive function to print binary tree
// It uses inorder traversal

string BinarySearchTree ::  pathTo(const string& x) const{
  return pathTo1(const string& x, root);
}
string BinarySearchTree :: pathTo1(const string& x, BinaryNode*& n) {
  string str = '';
  BinaryNode* node = new BinaryNode();
  node->value = x;
  if (n == NULL){
    return str;
  }
  else if (node->value > n->value){
    str += n->value +" "+  pathTo1(x, n->right);
  }
  else if (node->value < n<-value) {
    str +=n->value +" "+  pathTo1(x, n->left);
  }
  else {
    str += n->value + " ";
  }
  return str;
}

bool BinarySearchTree :: find(const string& x) const{
  return find( x, root);
}

bool BinarySearchTree :: find1(const string& x, BinaryNode*& n ) const{
  BinaryNode* node = new BinaryNode();
  node ->value = x;
  if (node->value == n->value) {
    return true;
  }
  else if (node->value != n-> value && n->right==NULL && n->left ==NULL){
    return false;
  }
  else if (node->value != n->value && n->right== NULL && n->left != NULL){
    return find(x, n->left);
  }
  else if (node->value != n->value && n->right!= NULL && n->right ==NULL){
    return find(x, n->right);
  }
      
}
int BinarySearchTree :: numNodes() const{
  return numNodes(root);
}

int BinarySearchTree :: numNodes1(BinaryNode*& n) {
  int z  = 0;
  if (n == NULL) {
    return z;
  }
  if (n->left !=NULL && n->right!=NULL) {
    z += 1 + numNodes(n->right) + numNodes(n->left);
  }
  if (n->left == NULL && n->right !=NULL){
    z += 1 + numNodes(n->right);
  }
  if (n->left !=NULL && n->right ==NULL){
    z += 1 + numNodes(n->left);
  }
  if (n->left ==NULL && n->right == NULL){
    z += 1;
  }
}

string BinarySearchTree :: min(BinaryNode*& node) const{
  string str = "";
  while (node->left != NULL){
    str = node->value;
    node = node->left;
  }
    
}

