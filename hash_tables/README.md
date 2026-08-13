# C - Hash Tables

## Description
This project covers the concept and implementation of **Hash Tables** in the C programming language as part of the Low-Level Programming curriculum at Holberton School.

A hash table is a data structure that implements an associative array abstract data type, a structure that can map keys to values. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found. In this project, collision handling is implemented using the **Chaining** method with singly linked lists.

---

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

* What is a hash function.
* What makes a good hash function.
* What is a collision and the main ways to handle it.
* What are the advantages and drawbacks of hash tables.
* What are the most common use cases of hash tables.

---

## Data Structures
The following data structures are defined in the header file `hash_tables.h`:

### Hash Node
```c
/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string (The key is unique in the HashTable)
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
     char *key;
     char *value;
     struct hash_node_s *next;
} hash_node_t;
