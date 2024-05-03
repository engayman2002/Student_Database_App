#include "Admin.h"
#include "../LIB/flush.h"


extern element_type Gid;
void Admin(Linked_List_Node** My_Head,int choice)
{
    int i;
    Data data;
    char temp[40];
    element_type temp_id;
    switch(choice)
    {

        case 1: // Add Record
            
            data.id=Gid;
            Gid++;
            flush();
            printf("Please Enter the name here : ");
            flush();
            gets(data.name);
            flush();

            printf("Please Enter the age here : ");
            flush();
            gets(temp);
            flush();
            data.age=atoi(temp);
            printf("Please Enter the height here : ");
            flush();
            gets(temp);
            flush();
            data.height=atoi(temp);

            printf("Please Enter the Total Grade here : ");
            flush();
            gets(temp);
            data.TotalGrade=atoi(temp);
            
            flush();
            printf("Please Enter the password here : ");
            flush();
            gets(data.pass);
            flush();

            if(Linked_List_AddNode(My_Head,data)==Linked_OK)
            {
                printf("\nThe User added successfully\n\n");
            }
            else
            {
                printf("\nOops! LinkedList is full\n");
            }
        break;

        
        case 2: //Remove Record
            printf("Enter the index of the Student that you want to remove : ");
            flush();
            scanf("%d",&temp_id);
            flush();
            switch(Linked_List_RemoveNode(My_Head,temp_id))
            {
                case Linked_OK:
                    printf("\nThe User is removed successfully\n\n");
                    break;
                
                case Linked_NOK:
                    printf("\nWrong Entry! You must type a natural number (0,1,2,......)\n\n");
                    break;

                case Linked_EMPTY:
                    printf("\nLinked is Empty\n\n");
                    break;

                case Linked_OutOfTheRange:
                    printf("\nThis Index is out of the range\n\n");
                    break;
            }
        break;

        case 3: //View all records
            
            for(i=0;Linked_List_NthNodeFromFront(My_Head,&data,i)==Linked_Found;i++)
            {
                printf("\n\nThe Record of the Student with Index %d\n",i);
                printf("ID of this student is = %d\n",data.id);
                printf("Name of this student is = %s\n",data.name);
                printf("Age of this student is = %d\n",data.age);
                printf("Height of this student is = %d\n",data.height);
                printf("Total Grade of this student is = %d\n",data.TotalGrade);
                printf("\n\n------------------------------------------\n\n");
            }
            if(i==0)
            {
                printf("\nDatabase is Empty\n\n");
            }
        break;

        case 4: //Delete All Records
            if(Linked_List_IsEmpty(My_Head)==Linked_EMPTY)
            {
                printf("\nDatabase is Empty.\n\n");
                break;
            }
            for(i=0;Linked_List_IsEmpty(My_Head)!=Linked_EMPTY;i++)
            {
                Linked_List_RemoveNode(My_Head,0);
            }
            printf("\n\nAll Elements are removed successfully\n\n");
        break;


        case 5: //Reverse the Records
            if(Linked_List_Reverse(My_Head)==Linked_EMPTY)
            {
                printf("\nYour Database is Empty\n\n");
            }
            else
            {
                printf("\n\nThe Operation was done.\n\n");
            }
            
        break;

        case 6: // Length of the database
            Linked_List_Length(My_Head,&temp_id);
            printf("The Length = %d\n\n",temp_id);
        break;

        case 7: // the first record
        if(Linked_List_Front(My_Head,&data)==Linked_EMPTY)
        {
            printf("\nDatabase is empty\n\n");
        }
        else
        {
                printf("The First Record\n\n");
                printf("ID of this student is = %d\n",data.id);
                printf("Name of this student is = %s\n",data.name);
                printf("Age of this student is = %d\n",data.age);
                printf("Height of this student is = %d\n",data.height);
                printf("Total Grade of this student is = %d\n",data.TotalGrade);
                printf("\n\n------------------------------------------\n\n");
        }
        

        break;

        case 8: // the last record
        if(Linked_List_Back(My_Head,&data)==Linked_EMPTY)
        {
            printf("\nDatabase is empty\n\n");
        }
        else
        {
                printf("The Last Record\n\n");
                printf("ID of this student is = %d\n",data.id);
                printf("Name of this student is = %s\n",data.name);
                printf("Age of this student is = %d\n",data.age);
                printf("Height of this student is = %d\n",data.height);
                printf("Total Grade of this student is = %d\n",data.TotalGrade);
                printf("\n\n------------------------------------------\n\n");
        }

        break;

        case 9: // Database is Empty ?
            if(Linked_List_IsEmpty(My_Head)==Linked_EMPTY)
            {
                printf("\nYour Database is Empty\n\n");
            }
            else
            {
                printf("\n Your Database isn't Empty. \n");
            }

        break;

        case 10: // Find record with ID
            printf("Please Enter the ID of this student here : ");
            flush();
            gets(temp);
            temp_id=atoi(temp);
            if(Linked_List_FindNode(My_Head,temp_id,&i)==Linked_NotFound)
            {
                printf("this ID isn't here\n\n");
            }
            else
            {
                Linked_List_NthNodeFromFront(My_Head,&data,i);
                printf("This Record is here\n\n");
                Linked_List_NthNodeFromFront(My_Head,&data,i);
                printf("ID of this student is = %d\n",data.id);
                printf("Name of this student is = %s\n",data.name);
                printf("Age of this student is = %d\n",data.age);
                printf("Height of this student is = %d\n",data.height);
                printf("Total Grade of this student is = %d\n",data.TotalGrade);
                printf("\n\n------------------------------------------\n\n");
            }
        break;

        case 11: // View Record with its Index from front
        printf("\nEnter the id here : ");
        flush();
        gets(temp);
        flush();
        i=atoi(temp);
            if(Linked_List_NthNodeFromFront(My_Head,&data,i)==Linked_Found)
            {
                printf("This Record is here\n\n");
                printf("ID of this student is = %d\n",data.id);
                printf("Name of this student is = %s\n",data.name);
                printf("Age of this student is = %d\n",data.age);
                printf("Height of this student is = %d\n",data.height);
                printf("Total Grade of this student is = %d\n",data.TotalGrade);
                printf("\n\n------------------------------------------\n\n");
            }
            else
            {
                printf("\nThis index is out Of the range.\n\n");
            }
        break;

        case 12: // View Record with its Index from back
        printf("\nEnter the id here : ");
        flush();
        gets(temp);
        flush();
        i=atoi(temp);
        if(Linked_List_NthNodeFromBack(My_Head,&data,i)==Linked_Found)
            {
                printf("This Record is here\n\n");
                printf("ID of this student is = %d\n",data.id);
                printf("Name of this student is = %s\n",data.name);
                printf("Age of this student is = %d\n",data.age);
                printf("Height of this student is = %d\n",data.height);
                printf("Total Grade of this student is = %d\n",data.TotalGrade);
                printf("\n\n------------------------------------------\n\n");
            }
            else
            {
                printf("Index is Out Of The Range\n\n");
            }
        break;
    }
}