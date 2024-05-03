#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "../LIB/My_Platform_Types.h"


// You can edit the Data Section with your desired data but keep Name of the structure (Data).
// Edit only on the next line (element_type) ^_^
#define element_type uint32_t

typedef struct
{
    // Effective Data or Payload
    element_type id;
    char name[40];
    int age;
    int height;
    int TotalGrade;
    char pass[41];
}Data;

// ----------------------------- Please don't edit in this Section -----------------------------
typedef struct
{
    // Effective Data
    Data Person;
    // Pointer to the next node
    struct Linked_List_Node* PNextLinkedList;
}Linked_List_Node;

typedef enum
{
    Linked_NOK,
    Linked_OK,
    Linked_FULL,
    Linked_EMPTY,
    Linked_OutOfTheRange,
    Linked_NotFound,
    Linked_Found,
}Linked_List_Status;

// You must create head pointer to your Linked_List it will make you have various numbers of Linked_List
/*
    Example:
    Linked_List_Node* Students_head=NULL;
*/

// APIs
extern Linked_List_Status Linked_List_Init(Linked_List_Node** My_Head);
extern Linked_List_Status Linked_List_AddNode(Linked_List_Node** My_Head,Data data);
extern Linked_List_Status Linked_List_RemoveNode(Linked_List_Node** My_Head,uint32_t index);
extern Linked_List_Status Linked_List_FindNode(Linked_List_Node** My_Head,element_type data,uint32_t* index);
extern Linked_List_Status Linked_List_Length(Linked_List_Node** My_Head,uint32_t *length);
extern Linked_List_Status Linked_List_Front(Linked_List_Node** My_Head,Data *data);
extern Linked_List_Status Linked_List_Back(Linked_List_Node** My_Head,Data *data);
extern Linked_List_Status Linked_List_IsFull();// It's only test your heap.
extern Linked_List_Status Linked_List_IsEmpty(Linked_List_Node** My_Head);
extern Linked_List_Status Linked_List_NthNodeFromFront(Linked_List_Node** My_Head,Data *data,uint32_t index);
extern Linked_List_Status Linked_List_NthNodeFromFront_Edit_Password(Linked_List_Node** My_Head,uint32_t index,char* pass);
extern Linked_List_Status Linked_List_NthNodeFromBack(Linked_List_Node** My_Head,Data *data,uint32_t index);
extern Linked_List_Status Linked_List_Reverse(Linked_List_Node** My_Head);


#endif
