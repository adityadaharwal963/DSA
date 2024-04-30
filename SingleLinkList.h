// Created by Aditya Daharwal

// Implemented Single Link list using single and double pointer
// function with suffix "DP" are implemented by Double pointer **
// For better understanding 
//      ptr  => head of link list
//      elem => element (int data)
//      pos  => position

// Functions in this header file:
// 1. createNode()
// 2. insertatEndDP(struct Node **ptr, int elem)
// 3. insertatEnd(struct Node *ptr, int elem)
// 4. insertatStart(struct Node *ptr, int elem)
// 5. insertatStartDP(struct Node **ptr, int elem)
// 6. display(struct Node *ptr)
// 7. DeleteatFirstDP(struct Node **ptr)
// 8. DeleteatFirst(struct Node *ptr)
// 9. DeleteatEnd(struct Node *ptr)
// 10. DeleteatEndDP(struct Node **ptr)
// 11. lenght(struct Node *ptr)
// 12. search(struct Node *ptr, int key)
// 13. Deleteat(struct Node **ptr, int pos)
// 14. search(struct Node *ptr, int key)
// 15. Update(struct Node *ptr, int ele, int pos)  
// 16. UpdateDP(struct Node **ptr, int ele, int pos)
// 17. Deleteat(struct Node **ptr, int pos)
// 18. reverse(struct Node *ptr)
// 19. reverseDP(struct Node **ptr)
#include <stdio.h>
#include <stdlib.h>

struct Node
{
      int data;
      struct Node *link;
};

struct Node *createNode()
{
      struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
      return ptr;
}

void insertatEndDP(struct Node **ptr, int elem)
{ // Using Double pointer

      struct Node *NewNode = createNode();
      //checking  memory allocation successful
      if (NewNode == NULL) 
      {
            printf("Memory allocation failed");
      }
      else
      {
            NewNode->data = elem;
            NewNode->link = NULL;
            if (ptr == NULL)
            { // if Linklist is empty set NewNode as head
                  *ptr = NewNode;
            }
            else
            {
                  struct Node *temp = *ptr;
                  // traverse till end of list 
                  while (temp->link != NULL)
                  {
                        temp = temp->link;
                  }
                  //insert node at end
                  temp->link = NewNode;
            }
      }
}

struct Node *insertatEnd(struct Node *ptr, int elem)
{

      struct Node *NewNode = createNode();
      //checking  memory allocation successful
      if (NewNode == NULL)
      {
            printf("Memory allocation failed");
      }
      else
      {
            NewNode->data = elem;
            NewNode->link = NULL;
            if (ptr == NULL)
            { // if Linklist is empty set NewNode as head
                  ptr = NewNode;
            }
            else
            { // Sll non empty
                  struct Node *temp = ptr;

                  // traverse till end of list
                  while (temp->link != NULL)
                  {
                        temp = temp->link;
                  }

                  //insert node at end
                  temp->link = NewNode;
            }
            return ptr;
      }
}

struct Node *insertatStart(struct Node *ptr, int elem)
{

      struct Node *NewNode = createNode();
      //checking  memory allocation successful
      if (NewNode == NULL)
      {
            printf("Memory allocation failed");
      }
      else
      {     //set newNode link = head and set newNode to head
            NewNode->data = elem;
            NewNode->link = ptr;
            ptr = NewNode;
      }
      return ptr;
}

void insertatStartDP(struct Node **ptr, int elem)
{ // Using Double pointer

      struct Node *NewNode = createNode();
      if (NewNode == NULL)
      {
            printf("Memory allocation failed");
      }
      else
      { //set newNode link = head and set newNode to head
            NewNode->data = elem;
            NewNode->link = *ptr;
            *ptr = NewNode;
      }
}

void display(struct Node *ptr)
{     // display link list 
      if (ptr == NULL)
      {
            printf("Empty SLL");
      }
      else
      {
            printf("[");
            while (ptr->link!= NULL)
            {
                  printf("%d->", ptr->data);
                  ptr = ptr->link;
            }
             printf("%d", ptr->link->data);
            printf("]");
      }
}



int DeleteatFirstDP(struct Node **ptr)
{     //The Function delete the node and return data of node 

      //Empty SLL means return -1(means no value)
      if (*ptr == NULL)
      {
            printf("Empty SLL");
            return -1;
      }
      else
      {     //store head in temp
            //set head to temp->link (means set head as second node)
            //delete temp and return data
            struct Node *temp = *ptr;
            int dat = temp->data;
            *ptr = temp->link;
            free(temp);
            return dat;
      }
}

struct Node *DeleteatFirst(struct Node *ptr)
{     //The Function delete the node and return data of node 

      //Empty SLL means return -1(means no value)
      if (ptr == NULL)
      {
            printf("Empty SLL");
      }
      else
      {     //store head in temp
            //set head to temp->link (means set head as second node)
            //delete temp and return data
            struct Node *temp = ptr;
            int dat = temp->data;
            printf("%d deleted form SLL", dat);
            ptr = temp->link;
            free(temp);
      }
      return ptr;
}

struct Node *DeleteatEnd(struct Node *ptr)
{
      if (ptr == NULL) // empty linklist , so operation not possible
      {
            printf("Empty SLL");
      }
      else
      {
            struct Node *temp = ptr;
            if (temp->link == NULL)
            {     //only one node
                  ptr = NULL;     
                  free(temp);
            }
            //traverse till last second node
            while (temp->link->link != NULL)
            {
                  temp = temp->link;
            }
            // set last second node -> link = NULL and delete last node
            int dat = temp->data;
            printf("%d deleted form SLL", dat);
            free(temp->link);
            temp->link = NULL;
      }
      return ptr;
}

void DeleteatEndDP(struct Node **ptr)
{ // Using Double pointer

      if (ptr == NULL)// empty linklist , so operation not possible
      {
            printf("Empty SLL");
      }
      else
      {
            struct Node *temp = *ptr;
            if (temp->link == NULL)
            {     //only one node
                  *ptr = NULL; 
                  free(temp);
            }
             //traverse till last second node
            while (temp->link->link != NULL)
            {
                  temp = temp->link;
            }
            // set last second node -> link = NULL and delete last node
            int dat = temp->data;
            printf("%d deleted form SLL", dat);
            free(temp->link);
            temp->link = NULL;
      }
}

int lenght(struct Node *ptr)
{     // return lenght of linklist
      int i = 0;
      while (ptr != NULL)
      {
            i++;
            ptr = ptr->link;
      }
      return i;
}

int search(struct Node *ptr, int key)
{     //function return index of in link list 
      //Note: indexing start from 1 like(1,2,3,....)

      int flag = 0;
      if (ptr == NULL)
      {
            printf("Empty SLL");
            return -1;
      }
      else
      {
            int i = 0;
            //linear search over list
            while (ptr != NULL)
            {
                  i++;
                  if (ptr->data == key)
                  {
                        flag = 1;
                        break;
                  }
                  ptr = ptr->link;
            }

            //print the element
            if (flag == 1)
            {
                  printf("key found at %d \n", i);
            }
            else
            {
                  printf("key not found");
            }
            return i;
      }
}

struct Node *Update(struct Node *ptr, int ele, int pos) // insert newNode at position 
{     //Note: indexing start from 1 like (1,2,3,....)

      if (ptr == NULL)                        // List is Empty
      {
            printf("Empty SLL");
      }
      else if (pos <= 0 || pos > lenght(ptr)) //index out of bound 
      {
            printf("Invalid positon");
      }
      else if (pos == 1)                      //insert at start 
      {
            ptr = insertatStart(ptr, ele);
      }
      else
      {     
            struct Node *NewNode = createNode();
            //checking memory allocation successful
            if (NewNode == NULL)
            {
                  printf("Memory allocation failed in Update");
            }
            else
            {     
                  int i = 1;
                  NewNode->data = ele;
                  struct Node *temp = ptr;

                  // traverse till pervious node of position 
                  while (i < pos - 1) 
                  {     // this is pos - 1 as loop ends at i = pos - 1

                        temp = temp->link;
                        i++;
                  }

                  // insert in between
                  NewNode->link = temp->link;
                  temp->link = NewNode;
            }
      }
      return ptr;
}

void UpdateDP(struct Node **ptr, int ele, int pos)    // insert newNode at position 
{     //Note: indexing start from 1 like (1,2,3,....)
      if (*ptr == NULL)                      // List is Empty
      {
            printf("Empty SLL");
      }
      else if (pos <= 0 || pos > lenght(*ptr))//index out of bound
      {
            printf("Invalid positon");
      }
      else if (pos == 1)                      //insert at start
      {
            insertatStartDP(ptr, ele);
      }
      else
      {
            struct Node *NewNode = createNode();
            //checking memory allocation successful
            if (NewNode == NULL)
            {
                  printf("Memory allocation failed in Update");
            }
            else
            {
                  int i = 1;
                  NewNode->data = ele;
                  struct Node *temp = *ptr;

                  // traverse till pervious node of position 
                  while (i < pos - 1)
                  {     // this is pos - 1 as loop ends at i = pos - 1
                        temp = temp->link;
                        i++;
                  }
                   // insert in between
                  NewNode->link = temp->link;
                  temp->link = NewNode;
            }
      }
}

void Deleteat(struct Node **ptr, int pos)  // delete element at position pos
{
      if (*ptr == NULL)                        // List is Empty
      {
            printf("Empty SLL");
      }
      else if (pos <= 0 || pos > lenght(*ptr))//index out of bound
      {
            printf("Invalid positon");
      }
      else if (pos == 1)                       //insert at start
      {
            DeleteatFirstDP(ptr);
      }
      else
      {
            int i = 1;
            struct Node *temp = *ptr;
            // traverse till pervious node of position
            while (i < pos - 1)
            {     // this is pos - 1 as loop ends at i = pos - 1
                  temp = temp->link;
                  i++;
            }
            int dat = temp->link->data;
            printf("%d deleted form SLL\n", dat);

            // set (pervious node of position)temp->link = (next node of position)
            temp->link = temp->link->link;
            free(temp->link);
      }
}

struct Node *reverse(struct Node *ptr) // reverse the link list 
{     // try a dry run on paper
      if (ptr == NULL)
      {
            printf("Empty SLL");
      }
      else
      {
            struct Node *prev = NULL;
            struct Node *cur = ptr;
            struct Node *next = NULL;
            while (cur != NULL)
            {
                  next = cur->link;
                  cur->link = prev;
                  prev = cur;
                  cur = next;
            }
            ptr = prev;
      }
      return ptr;
}

void reverseDP(struct Node **ptr)   // reverse the link list 
{
      if (ptr == NULL)
      {
            printf("Empty SLL");
      }
      else
      {
            struct Node *prev = NULL;
            struct Node *cur = *ptr;
            struct Node *next = NULL;
            while (cur != NULL)
            {
                  next = cur->link;
                  cur->link = prev;
                  prev = cur;
                  cur = next;
            }
            *ptr = prev;
      }
}