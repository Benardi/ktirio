#include <doubly_ll.h>
#include <malloc.h>

DoublyLinkedList* list_search(DoublyLinkedList** head, Key k)
{
  DoublyLinkedList* searched;
  DoublyLinkedList* node;

  searched = NULL;
  node = (DoublyLinkedList*) (*head);
  while (node != NULL) {
    if (node->data.key == k) {
      searched = node; 
      break;
    }
    node = (DoublyLinkedList*) node->next;
  }

  return searched;
}

DoublyLinkedList* list_insert(DoublyLinkedList** head, Key k)
{
  DoublyLinkedList* node; 
  node = (DoublyLinkedList*) malloc(sizeof(DoublyLinkedList*));
  node->data.key = k;
  node->next = *head;
  node->prev = NULL;

  if (*head != NULL) {
    (*head)->prev = node;
  }

  *head = node;

  return node;
}

void list_delete(DoublyLinkedList** head, DoublyLinkedList* to_remove)
{
  if (to_remove->prev != NULL) {
    (to_remove->prev)->next = to_remove->next;
  }
  else {
    (*head) = to_remove->next;
  }
  if(to_remove->next != NULL) {
      (to_remove->next)->prev = to_remove->prev;
  }
} 