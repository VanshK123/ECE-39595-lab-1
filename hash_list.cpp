#include "hash_list.h"


/** Don't delete this function but you can leave it empty */
hash_list::hash_list(const hash_list &other)
{
}

/** Don't delete this function, but you can leave it as is */
hash_list &hash_list::operator=(const hash_list &other)
{
    return *this;
}

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

