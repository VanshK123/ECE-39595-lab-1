#include "hash_list.h"

void insert(int key, float value)
{
   // node* temp = hash_list::head;
//check if node exists

//no node there

//node there
}

node* _insnode(int key, float value)
{
//create node
struct node *newNode = new (node);
newNode->key = key;
newNode->value=value;
newNode->next=NULL;
return newNode;
}