#include "hash_list.h"
#include "iostream"
using namespace std;

node* _insnode(int key, float value);

/** Don't delete this function but you can leave it empty */
hash_list::hash_list(const hash_list &other)
{
}


/** Don't delete this function, but you can leave it as is */
hash_list &hash_list::operator=(const hash_list &other)
{
    return *this;
}

hash_list::hash_list()
{
    size = 0;
    head = NULL;
}

hash_list::~hash_list()
{
    
}


void hash_list::insert(int key, float value)
{
    // Find the head node, set current to head
    node* current = head;
    node* previousNode = head;
    bool hasWritten = false;

    //Check if first, update head if is
    if(current == NULL)
    {
        std::cout << "(INSERT) head is null, writing here" << std::endl;
        current = _insnode(key, value);
        head = current;
        return;
    }

    // Traverse list
    while (current != NULL)
    {
        
        // If you find a key that matches, update value and bool
        if (current->key == key)
        {
            std::cout << "(INSERT) Found duplicate, overwriting" << std::endl;
            current->value = value;
            hasWritten = true;
        }
        if(current != NULL)
        {
            previousNode = current;
        }
        current = current->next;
        
    }

    // If no values have been updated (new key), make a new node and append to end
    if (hasWritten == false)
    {
        std::cout << "(INSERT) Appending node" << std::endl;
        current = _insnode(key, value);
        previousNode->next = current;
    }

    return;
}

node* _insnode(int key, float value)
{
    // create node
    node *newNode = new (node);
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

bool hash_list::remove(int key){
    
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


void hash_list::printArray()
{
node* current = head;

while(current != NULL)
{
    std::cout << "(PRINT) Key: " << current->key << "   Value: " << current->value << std::endl;
    current = current->next;
}
}

size_t hash_list::get_size() const
{
node* current = head;
size_t size = 0;
while(current != NULL)
{
    size += 1;
    current = current->next;
}
std::cout << "(GETSIZE) Size: " << size << std::endl;
    return size;
}
