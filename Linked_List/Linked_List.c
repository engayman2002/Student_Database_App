#include "Linked_List.h"
#include <stdlib.h>
#include <string.h>

Linked_List_Status Linked_List_Init(Linked_List_Node** My_Head)
{
    (*(My_Head))=NULL;
    return Linked_OK;
}

Linked_List_Status Linked_List_AddNode(Linked_List_Node** My_Head,Data data)
{
    Linked_List_Node* NewNode = (Linked_List_Node*)malloc(sizeof(Linked_List_Node));

    if(NewNode==NULL)
    {
        return Linked_FULL;
    }

    NewNode->PNextLinkedList=NULL; // because it will be the last node.


    // You can here change it if you change elements in Linked_List.
    NewNode->Person.id=data.id;
    NewNode->Person.age=data.age;
    NewNode->Person.height=data.height;
    strcpy(NewNode->Person.name,data.name);
    NewNode->Person.TotalGrade=data.TotalGrade;
    strcpy(NewNode->Person.pass,data.pass);


    Linked_List_Node* PLastNode=(*(My_Head));

    if((*(My_Head))==NULL)
    {
        (*(My_Head))=NewNode;
    }

    else
    {
        PLastNode=(*(My_Head));

        while(PLastNode->PNextLinkedList!=NULL)
        {
            PLastNode = PLastNode->PNextLinkedList;
        }
        PLastNode->PNextLinkedList=NewNode;
    }

    return Linked_OK;
    /*
    */
}

Linked_List_Status Linked_List_RemoveNode(Linked_List_Node** My_Head,uint32_t index)
{
    // For Validation
    if(index<0)
    {
        return Linked_NOK;
    }

    if((*(My_Head))==NULL)
    {
        return Linked_EMPTY;
    }

    uint32_t count=0;
    Linked_List_Node* PFindIndex=(*(My_Head));
    Linked_List_Node* PPrevIndex=(*(My_Head));

    while(count!=index)
    {
        count++;
        if(PPrevIndex!=PFindIndex)
        {
            PPrevIndex=PFindIndex;
        }
        PFindIndex=PFindIndex->PNextLinkedList;
        if(count==index)
        {
            break;
        }
        if(PFindIndex->PNextLinkedList==NULL)
        {
            return Linked_OutOfTheRange;
        }
    }

    if(index==0)
    {
        (*(My_Head))=(*(My_Head))->PNextLinkedList;
    }
    else
    {
        PPrevIndex->PNextLinkedList=PFindIndex->PNextLinkedList;
    }
    free(PFindIndex);

    return Linked_OK;
}

Linked_List_Status Linked_List_FindNode(Linked_List_Node** My_Head,element_type data,uint32_t* index)
{
    // For Validation
    if((*(My_Head))==NULL)
    {
        *index=-1;
        return Linked_NotFound;
    }

    uint32_t count=0;

    Linked_List_Node* PFindIndex=(*(My_Head));

    while(PFindIndex!=NULL)
    {
        if(data==PFindIndex->Person.id)
        {
            *index=count;
            return Linked_Found;
        }
        count++;
        PFindIndex=PFindIndex->PNextLinkedList;
    }

    *index=-1;
    return Linked_NotFound;
}


Linked_List_Status Linked_List_Length(Linked_List_Node** My_Head,uint32_t *length)
{
    // For Validation
    if((*(My_Head))==NULL)
    {
        *length=0;
        return Linked_EMPTY;
    }

    uint32_t count=0;

    Linked_List_Node* PFindLength=(*(My_Head));

    while(PFindLength->PNextLinkedList!=NULL)
    {
        count++;
        PFindLength=PFindLength->PNextLinkedList;
    }

    *length = count+1;

    return Linked_OK;
}


Linked_List_Status Linked_List_Front(Linked_List_Node** My_Head,Data *data)
{
    // For Validation
    if((*(My_Head))==NULL)
    {
        return Linked_EMPTY;
    }

    data->id=(*(My_Head))->Person.id;
    data->age=(*(My_Head))->Person.age;
    data->height=(*(My_Head))->Person.height;
    strcpy(data->name,(*(My_Head))->Person.name);
    data->TotalGrade=(*(My_Head))->Person.TotalGrade;
    strcpy(data->pass,(*(My_Head))->Person.pass);

    return Linked_OK;
}

Linked_List_Status Linked_List_Back(Linked_List_Node** My_Head,Data *data)
{
    // For Validation
    if((*(My_Head))==NULL)
    {
        return Linked_EMPTY;
    }

    Linked_List_Node* PBack=(*(My_Head));

    while(PBack->PNextLinkedList!=NULL)
    {
        PBack=PBack->PNextLinkedList;
    }

    data->id=PBack->Person.id;
    data->age=PBack->Person.age;
    data->height=PBack->Person.height;
    strcpy(data->name,PBack->Person.name);
    data->TotalGrade=PBack->Person.TotalGrade;
    strcpy(data->pass,PBack->Person.pass);

    return Linked_OK;
}

Linked_List_Status Linked_List_IsFull()
{
    Linked_List_Node* NewNode = (Linked_List_Node*)malloc(sizeof(Linked_List_Node));
    if(NewNode==NULL)
    {
        return Linked_FULL;
    }

    free(NewNode);

    return Linked_OK;
}


Linked_List_Status Linked_List_IsEmpty(Linked_List_Node** My_Head)
{
    if((*(My_Head))==NULL)
    {
        return Linked_EMPTY;
    }

    return Linked_OK;
}


Linked_List_Status Linked_List_NthNodeFromFront(Linked_List_Node** My_Head,Data *data,uint32_t index)
{
    // For Validation
    if((*(My_Head))==NULL)
    {
        return Linked_EMPTY;
    }

    uint32_t count=0;

    Linked_List_Node* PNode=(*(My_Head));

    while(count!=index)
    {
        if(PNode->PNextLinkedList==NULL)
        {
            return Linked_OutOfTheRange;
        }
        count++;
        PNode=PNode->PNextLinkedList;
    }

    data->id=PNode->Person.id;
    data->age=PNode->Person.age;
    data->height=PNode->Person.height;
    strcpy(data->name,PNode->Person.name);
    data->TotalGrade=PNode->Person.TotalGrade;
    strcpy(data->pass,PNode->Person.pass);
    return Linked_Found;
}

Linked_List_Status Linked_List_NthNodeFromFront_Edit_Password(Linked_List_Node** My_Head,uint32_t index,char* pass)
{
    // For Validation
    if((*(My_Head))==NULL)
    {
        return Linked_EMPTY;
    }

    uint32_t count=0;

    Linked_List_Node* PNode=(*(My_Head));

    while(count!=index)
    {
        if(PNode->PNextLinkedList==NULL)
        {
            return Linked_OutOfTheRange;
        }
        count++;
        PNode=PNode->PNextLinkedList;
    }

    strcpy(PNode->Person.pass,pass);

    return Linked_Found;
}

Linked_List_Status Linked_List_NthNodeFromBack(Linked_List_Node** My_Head,Data *data,uint32_t index)
{
    // For Validation
    if((*(My_Head))==NULL)
    {
        return Linked_EMPTY;
    }

    uint32_t count=0;

    Linked_List_Node* PFront=(*(My_Head));
    Linked_List_Node* PBack=(*(My_Head));

    while(count!=index)
    {
        if(PFront->PNextLinkedList==NULL)
        {
            return Linked_OutOfTheRange;
        }
        count++;
        PFront=PFront->PNextLinkedList;
    }

    while(PFront->PNextLinkedList!=NULL)
    {
        PFront=PFront->PNextLinkedList;
        PBack=PBack->PNextLinkedList;
    }


    data->id=PBack->Person.id;
    data->age=PBack->Person.age;
    data->height=PBack->Person.height;
    strcpy(data->name,PBack->Person.name);
    data->TotalGrade=PBack->Person.TotalGrade;
    strcpy(data->pass,PBack->Person.pass);

    return Linked_Found;
}


Linked_List_Status Linked_List_Reverse(Linked_List_Node** My_Head)
{
    // For Validation
    if((*(My_Head))==NULL)
    {
        return Linked_EMPTY;
    }
    if((*(My_Head))->PNextLinkedList==NULL)
    {
        return Linked_OK;
    }

    Linked_List_Node* Buffer1=(*(My_Head))->PNextLinkedList;
    Linked_List_Node* Buffer2=(*(My_Head));
    Buffer2->PNextLinkedList=NULL;

    while(Buffer1!=NULL)
    {
        (*(My_Head))=Buffer1;
        Buffer1=Buffer1->PNextLinkedList;

        (*(My_Head))->PNextLinkedList=Buffer2;
        Buffer2=(*(My_Head));
    }

    return Linked_OK;
}
