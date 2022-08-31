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
    // Find the head node, set current to head
    node *current = head;
    bool hasWritten = false;

    // Traverse list
    while (current != NULL)
    {
        // If you find a key that matches, update value and bool
        if (current->key == key)
        {
            current->value = value;
            hasWritten = true;
        }
        cout << current->key;
        current = current->next;
    }

    // If no values have been updated (new key), make a new node and append to end
    if (hasWritten == false)
    {
        current = _insnode(key, value);
    }

    return;
}

node *_insnode(int key, float value)
{
    // create node
    node *newNode = new (node);
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

bool hash_list::remove(int key)
{

    node *temp1 = head;
    node *temp2 = NULL;

    return false;
}
