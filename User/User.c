#include "User.h"
#include "../LIB/flush.h"

void User(Linked_List_Node** My_Head,int choice)
{

    int i;
    Data data;
    char temp[40];
    element_type temp_id;

    flush();
    printf("Please Enter your ID number here : ");
    flush();
    gets(temp);
    flush();
    temp_id=atoi(temp);
    printf("Please Enter your Password here : ");
    flush();
    gets(temp);
    flush();

    if(Linked_List_FindNode(My_Head,temp_id,&i)==Linked_Found)
        {
            Linked_List_NthNodeFromFront(My_Head,&data,i);
            if( strcmp(temp,data.pass) == 0 )
            {
                printf("Login OK!\n\n");
            }
            else
            {
                printf("\nWrong Password.\n\n");
                return;
            }
        }
        else
        {
            printf("Invalid Login\n\n");
            return;
        }

    switch(choice)
    {
        case 1: // View your record
        
                printf("ID of this student is = %d\n",data.id);
                printf("Name of this student is = %s\n",data.name);
                printf("Age of this student is = %d\n",data.age);
                printf("Height of this student is = %d\n",data.height);
                printf("Total Grade of this student is = %d\n",data.TotalGrade);
                printf("\n\n------------------------------------------\n\n");

        break;

        case 2: // Edit your password
            flush();
            printf("Enter your New Password here (Maxiumum 40 char): ");
            flush();
            gets(temp);
            flush();
            if(Linked_List_NthNodeFromFront_Edit_Password(My_Head,i,temp)==Linked_Found)
            {
                printf("\nThe Operation is done.\n\n");
            }

        break;

        case 3: // Remove yourself from database
            if(Linked_List_RemoveNode(My_Head,i)==Linked_OK)
            {
                printf("\nYou was removed from the database.\n\n");
            }
        break;
    }
}