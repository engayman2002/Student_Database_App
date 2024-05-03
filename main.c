#include <stdio.h>
#include <string.h>

#include "Linked_List/Linked_List.h"
#include "Admin/Admin.h"
#include "User/User.h"

element_type Gid=0;
#define Ayman_Password "Ayman"




int main()
{
    Linked_List_Node* My_Students;
    Linked_List_Init(&My_Students);
    
    printf("\n-----------------  Weclome to our Student Database System  -----------------\n");
    printf("------------------------------------------------------------------------------------------------");
    int status;
    int choice=0;
    char temp[40];

    while(1)
    {
        status=0;
        printf("\n\nPlease Choose from these modes : \n");
        printf("1- Admin Mode\n");
        printf("2- User Mode\n");
        printf("Enter your choice here : ");
        scanf(" %d",&status);
        switch (status)
        {
        case 1: // Admin Mode
            printf("Enter the password here : ");
			fflush(stdin);
            gets(temp);
            if(strcmp(temp,Ayman_Password)!=0)
            {
                printf("Invalid Password\n\n");
                break;
            }
            while(1)
            {
                choice=0;
                printf("Please Choose from this list what you want : \n");
                printf("1- Add Record\n");
                printf("2- Remove Record\n");
                printf("3- View All Records\n");
                printf("4- Delete All Records\n");
                printf("5- Reverse the Records\n");
                printf("6- Length of the database\n");
                printf("7- The First Record\n");
                printf("8- The Last Record\n");
                printf("9- Database is Empty?\n");
                printf("10- Find Record with ID.\n");
                printf("11- View Record with its Index from front\n");
                printf("12- View Record with its Index from back\n");
                printf("\n13- Logout\n");
                printf("\n\nEnter your choice here : ");
                scanf("%d",&choice);
                if(choice==13)
                {
                    break;
                }
                else if(choice<1 || choice>13)
                {
                    printf("\nWrong Entry, Please Try again.\n\n");
                    continue;
                }
                Admin(&My_Students,choice);
                printf("\n\n----------------------------------\n\n");
            }
            break;
        
        case 2: // User Mode
            while(1)
            {
                choice=0;
                printf("Please Choose from this list what you want : \n");
                printf("1- View your record\n");
                printf("2- Edit your password\n");
                printf("3- Remove yourself from database\n");
                printf("\n4- Logout\n");
                printf("\n\nEnter your choice here : ");
                scanf("%d",&choice);
                if(choice==4)
                {
                    break;
                }
                User(&My_Students,choice);
                printf("\n\n----------------------------------\n\n");

            }
            break;
        default:
            printf("Wrong Entry, Please try again");
            break;
        }
        printf("----------------------------------------------------\n\n\n\n\n");
    }

    return 0;
}