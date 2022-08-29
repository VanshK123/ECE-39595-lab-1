#ifndef HASH_LIST_H
#define HASH_LIST_H

#include <optional>
#include <stddef.h>
#include <stdlib.h>

/** A single key/value pair in the linked list */
struct node
{
    /** The key the node is storing */
    int key;

    /** the value the node is storing */
    float value;

    /** a pointer to the next node */
    node *next;
};

/** A list that stores key/value pairs */
class hash_list
{

public:
    /** Create empty list. Should set head to null and size to 0 */
    hash_list();

    /** 
     * You need to define these functions in hash_list.cpp but can leave them blank (this is done for you in provided hash_list.cpp file)
     * You'll learn what they are and will implement them in the next part of the lab. For now all that you need to know is that you
     * shouldn't write any code like the following.
     * 
     * hash_list x;
     * 
     * hash_list y(x); -> Don't write this
     * 
     * y = x           -> Don't write this either 
     * 
     */

    /** The copy constructor */
    hash_list(const hash_list &other);

    /** assignment operator */
    hash_list& operator=(const hash_list& other);

    /**
     * Insert a node with the corresponding key value pair into the list.
     * If a node with the associated key already exists, update that node with the new value instead of
     * adding a new node to the list.
     */
    void insert(int key, float value);

    /**
     * Return an optional containing the value associated with the specified key. If the key isn't in
     * the list return an empty optional.
     */
    std::optional<float> get_value(int key) const;

    /**
     * Remove the node containing the specified key from the list and return true. If the key isn't
     * in the list return false.
     */
    bool remove(int key);

    /** Return the number of nodes in the list */
    size_t get_size() const;

    /** Free all memory associated with the nodes. This must not free the nodes recursively */
    ~hash_list();

private:
    /** The number of nodes in the list */
    size_t size;

    /** A pointer to the first node in the list */
    node *head;
};

#endif
