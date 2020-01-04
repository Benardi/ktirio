/**
 * @file doubly_ll.h
 * @author Benardi Nunes <benardinunes@gmail.com>
 * @date 2 Jan 2020
 * @brief Header file for Doubly Linked List module.
 *
 * Defines the constant MAX number of elements, the structs Key, Register
 * and DoublyLinkedList and the prototypes for the subroutines of the
 * DoublyLinkedList module.
 */
#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <stddef.h>
#include <stdbool.h>

typedef int Key;

typedef struct
{
  Key key; /* Key that maps the register */
}
Register;

typedef struct DoublyLinkedList
{
  struct DoublyLinkedList *prev;
  struct DoublyLinkedList *next;
  Register data;
}
DoublyLinkedList;

/** @brief Inserts element to front of Linked List.
 *  
 * Inserts element to front of Linked List. If other 
 * elements already exist in list new element becomes
 * new head and existing elements are linked to new one. 
 * Returns pointer to added element and updates double
 * pointer with new head of the linked list.
 *
 * @param head Double pointer to head of linked list. 
 * @param k Key for Register of inserted element.
 * @return Pointer to inserted node.
 */
DoublyLinkedList* list_insert(DoublyLinkedList** head, Key k);

/** @brief Retrieves node in linked list via key. 
 *
 * Iterates sequentially over linked list. If node with
 * given key exists returns pointer to it, otherwise
 * returns @c NULL.
 *
 * @param head Double pointer to head of linked list. 
 * @param k Key for Register of inserted element.
 * @return Pointer to retrieved node.
 */
DoublyLinkedList* list_search(DoublyLinkedList** head, Key k);

/** @brief Deletes given node from linked list. 
 *
 * Removes a node given via pointer from linked list.
 * List is amended to make up for absence of removed
 * node. Allocated memory for node pointer is not freed.
 * It's up to user to free memory allocated to pointer.
 *
 * @param head Double pointer to head of linked list. 
 * @param k key for Register of inserted element.
 * @return Void
 */
void list_delete(DoublyLinkedList** head, DoublyLinkedList* to_remove);

#endif