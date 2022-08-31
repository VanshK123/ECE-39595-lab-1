#include "hash_list.h"
#include "iostream"
using namespace std;

/** Don't delete this function but you can leave it empty */
hash_list::hash_list(const hash_list &other)
{
}

/** Don't delete this function, but you can leave it as is */
hash_list &hash_list::operator=(const hash_list &other)
{
    return *this;
}

void hash_list::insert(int key, float value)
{
    node* temp = head;
    newNode = malloc(sizeof(node*));
    newNode->data = value;
    newNode->key = key;
   bool dup = false;
    while(temp != NULL)
    {
        cout << temp->key;
    }
    node* current = head;

    while(current != NULL){
        if(current->key == key){
            current->value = value;
            dup = true;
            return current;
        }
    }
    while(current->next != NULL){
          current = current->next;
    }
    current->next = newNode; 
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

void hash_list::remove(int key){
    
    bool found = false;
    node* current = head;
    int pos = 0;
    while(current != NULL){
        if(current -> key == key){
            found = true;
            break;
        }
        pos++;
        current = current->next;
    }

    for(int i = 0; i<pos;i++){
        if(current -> next!=NULL){
            current = current -> next;
        }
    }
    if(found){
    current -> next =  current -> next -> next;
    return true;
    } 

    return false;
}

