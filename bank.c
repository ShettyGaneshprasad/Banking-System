//Programme for banking application
//Author Shetty Ganesh
//USN: 2sd17cs088
//Branch:- CSE
//Submitted on 17-jan-2020

//preprocessor directive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "account.h" //including user defined header file containing important function for this programme

//start of main function
int main()
{
    int choice, swi; //variable for switch and menu generation
    char dummy;      //for handling ENTER read by keyboard

    //structure variable for struct account
    struct account acc;

    //pointer for passing acc_structure into the function
    struct account *acc_ptr;

    //assigning address of strcut acc to structure pointer
    acc_ptr = &acc;

    printf("\nWelcome to the banking Application created by \'Ganesh Shetty\'\n");
    printf("Initializing");
    //for smooth exit animation.
    for (int i = 0; i < 2; i++)
    {
        printf(".....");
        sleep(1);
    }
    printf("\n");
    //create account function
    acc = acc_creation();
    printf("Account Created\n\n");
    printf("press ENTER to continue\n\n");
    scanf("%c", &dummy);

    //infinite loop for menu generation
    while (1)
    {
        //menu generation
        printf("\nEnter the choice as Menu\n\'1\':Check Balance\n\'2\':Account Info\n\'3\':Withdraw\n\'4\':Deposit\n\'5\':Apply for credit card\n'0\': to exit Programme\n");
        //getting input data for switch for menu driven programme
        scanf("%d", &swi);

        //switch for menu driven programme
        switch (swi)
        {
        case 0:
            printf("\nThanks for using our Programme ;)\n");
            sleep(1);
            printf("Have a nice day\n");
            sleep(1);
            printf("exiting");
            //for smooth exit animation.
            for (int i = 0; i < 2; i++)
            {
                printf(".....");
                sleep(1);
            }
            exit(0);
            break;

        case 1:
            //calling function for checking balance
            balance(acc);
            break;

        case 2:
            //calling function for getting account info
            accountinfo(acc);
            break;

        case 3:
            //calling function for withdrawing money from account
            acc_ptr = withdraw(acc_ptr);
            break;

        case 4:
            //calling function for depositing money in account
            acc_ptr = deposit(acc_ptr);
            break;

        case 5:
            //checking wheather card is already given or not
            if (acc.card == 1)
            {
                //when card is already assigned to that account
                printf("\nCard already Assigned \n");
                printf("Press ENTER to continue\n");
                scanf("%c", &dummy);
                scanf("%c", &dummy);
            }
            else
            {
                //this block execute when card is not assigned previously
                printf("\nCredit card assigned\n");
                printf("and it will be sent to you shortly\n");
                acc.card = 1;
                printf("Press ENTER to continue\n");
                scanf("%c", &dummy);
                scanf("%c", &dummy);
            }
            break;
        default:
            //for invalid input to switch
            printf("Invalid input try again!!!\n");
            scanf("%c", &dummy);
        }
        //end of switch
    }
    //end of while loop
    printf("exiting\n");
    return 0;
}
//end of main function
