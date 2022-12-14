#include "hash_list.h"
//#include <iostream>

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
    node* current;

    while (head != NULL)
    {
        current = head;
        //std::cout << current->key << std::endl;
        head = head->next;
        delete current;
    }
    
    //// std::cout << "(DESTRUCTOR)  Destruct Finished" << std::endl;
    
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
        //// std::cout << "(INSERT) head is null, writing here" << std::endl;
        current = _insnode(key, value);
        head = current;
        size += 1;
        return;
    }

    // Traverse list
    while (current != NULL)
    {
        
        // If you find a key that matches, update value and bool
        if (current->key == key)
        {
            //// std::cout << "(INSERT) Found duplicate, overwriting" << std::endl;
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
        //// std::cout << "(INSERT) Appending node" << std::endl;
        current = _insnode(key, value);
        previousNode->next = current;
        size += 1;
    }
    
    return;
}
std::optional<float> hash_list::get_value(int key) const{
        node* current = head;
while(current != NULL)
{
    //finds
    if(current->key == key)
    {
        // std::cout << "(GETVALUE) Value: " << current->value << std::endl;
return current->value;
    }
    current = current->next;
}
// std::cout << "(GETVALUE) Did not Find" << std::endl;
    return {};
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
    node* current = head;
    node* prev = head;

    if(head != NULL && (head->key == key))
    {
        node* temp = head;
        head = head->next;
        delete temp;
        // std::cout << "(REMOVE) Did remove Head: "<< "Key: " << key  << std::endl;
        size -= 1;
        return true;

    }

    while(current != NULL)
    {
        if(current == NULL)
        {
            //DID NOT FIND TO REMOVE
            // std::cout << "(REMOVE) Did Not Find: "<< "Key: " << key  << std::endl;
            return false;
        }

        if(current->key == key)
        {
            prev->next = current->next;
            //free current
            delete current;
            // std::cout << "(REMOVE) Did Find: "<< "Key: " << key  << std::endl;
            size -= 1;
            return true;

        }

        prev = current;
        current = current->next;
    }
// std::cout << "(REMOVE) Did Not Find: "<< "Key: " << key  << std::endl;
    return false;
}
 


size_t hash_list::get_size() const
{
    //std::cout << size << std::endl;
    return size;
}
