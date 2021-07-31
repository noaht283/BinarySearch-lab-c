#include <string>
#include "BinaryNode.h"
using namespace std;

BinaryNode:: BinaryNode(){
  value = "";
  left = NULL;
  right = NULL;
}

BinaryNode:: ~BinaryNode(){
  delete left;
  delete right;
  left = NULL;
  right = NULL;
}
