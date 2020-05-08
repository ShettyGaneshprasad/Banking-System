//Programme for banking application
//Author Shetty Ganesh
//USN: 2sd17cs088
//Branch:- CSE
//Submitted on 17-jan-2020

//preprocessor directive
#include <stdio.h>
#include <string.h>

struct account *withdraw(struct account *); //function prototype to withdraw money from account.
void balance(struct account);               //function prototype to check balance in account.
void accountinfo(struct account);           //function prototype to create account.
struct account acc_creation();              //function prototype to create account.
struct account *deposit(struct account *);  //function prototype to deposit account.

//structure for account
struct account
{
    char name[50];                   //storing name
    char lname[50];                  //storing lname
    int account_no;                  //storing account number
    int age;                         //storing age of account holder
    char city[50];                   //storing city of customer
    int balance;                     //for balance of customer
    unsigned long long int aadhar;   //aadhaar number storage
    unsigned long long int pan;      //pan card number storage
    unsigned long long int phnumber; //phonenumber of customer
    int acctype;                     //account type whether it is current of saving account
    int card;                        //credit card info
};

//function to get account info
void accountinfo(struct account acc)
{
    char dummy, dummy1;
    printf("\n\nAccount holders name=>      %s %s\n", acc.name, acc.lname);
    if (acc.acctype == 1)
    {
        printf("Account Type=>              Savings Account\n");
    }
    else
    {
        printf("Account type=>              Current\n");
    }
    printf("Account number =>           %d\n", acc.account_no);
    printf("Account age =>              %d\n", acc.age);
    printf("Account holder's city =>    %s\n", acc.city);
    printf("Pan number=>                %llu\n", acc.pan);
    if (acc.aadhar == 0)
    {
        printf("Aadhaar number=>             Not linked with your account\n");
    }
    else
    {
        printf("Aadhaar number =>           %llu\n", acc.aadhar);
    }

    printf("Phone number=>              %llu\n", acc.phnumber);
    printf("Account balance =>          Rs %d \n", acc.balance);
    //exiting account info
    printf("press ENTER to continue\n\n");
    scanf("%c%c", &dummy, &dummy1);
}
//end of account info

//function to get account balance
void balance(struct account acc)
{
    char dummy, dummy1;
    printf("\nAvailable balance of your account number %d is Rs %d\n\n", acc.account_no, acc.balance);
    printf("press ENTER to continue\n\n");
    scanf("%c%c", &dummy, &dummy1);
}
//end of function for printing balance

//function to create account
struct account acc_creation()
{
    struct account b;
    char dummy;
    int choice, i = 0, j = 0;
    unsigned long long int check;
    b.account_no=456258;
    printf("\nEnter the name of Account Holder\n");
    scanf("%s", b.name);

    printf("\nEnter last name of the Account holder\n");
    scanf("%s", b.lname);
    !printf("\nAge of the customer\n");
    scanf("%d", &b.age);

    printf("\nEnter City of the customer\n");
    scanf("%s", b.city);

    printf("\nEnter type of account needed\n\t \'1\':Savings Account\n\t \'2\':Current Account\n");
    scanf("%d", &b.acctype);

pan:
    printf("\nEnter Pan number of Account holder \n");
    printf("NOTE:Pan number do not start with 0\n");
    scanf("%llu", &b.pan);
    check = b.pan;
    //checking the number of digit for valid pan number
    for (i = 0; check != 0; i++)
    {
        check = check / 10;
        j++;
    }

    if (j != 10)
    {
        printf("\n!!Invalid pan number=> number should be \'10\' digit number not \'%d\' digit number!!\n", j);
        printf("Press ENTER to continue\n\n");
        scanf("%c", &dummy);
        scanf("%c", &dummy);
        j = 0;
        goto pan;
    }

aadhaar:
    printf("\nDo you want to link your Aadhar number with your bank Account ?\n \'1\':If yes or \'0\':If no\n");
    scanf("%d", &choice);
    if (choice)
    {
        printf("\nEnter your Aadhaar number\n");
        printf("NOTE:Aadhar number do not start with 0\n");
        scanf("%llu", &b.aadhar);

        check = b.aadhar;
        j = 0;
        //checking the number of digit for valid aadhaar number
        for (i = 0; check != 0; i++)
        {
            check = check / 10;
            j++;
        }
        if (j != 12)
        {
            printf("\n!!Invalid Aadhaar number=> number should be \'12\' digit number not \'%d\' digit number!!\n", j);
            printf("Press ENTER to continue\n\n");
            scanf("%c", &dummy);
            scanf("%c", &dummy);
            j = 0;
            goto aadhaar;
        }
    }
    else
    {
        printf("Its not mandatory but its suggested that Aadhaar should be linked with bank account like pan card\n");
        printf("Aadhar card is not linked\n");
        printf("press ENTER to continue\n\n");
        scanf("%c%c", &dummy, &dummy);
        b.aadhar == 0;
    }

phno:
    printf("\nEnter phone number\n");
    printf("NOTE:Phone  number do not start with 0\n");
    scanf("%llu", &b.phnumber);

    check = b.phnumber;
    j = 0;
    //checking the number of digit for valid phone number
    for (i = 0; check != 0; i++)
    {
        check = check / 10;
        j++;
    }
    if (j != 10)
    {
        printf("!!Invalid Phone number=> number should be \'10\' digit number not \'%d\' digit number\n", j);
        printf("Press ENTER to continue\n\n");
        scanf("%c", &dummy);
        scanf("%c", &dummy);
        j = 0;
        goto phno;
    }

label:
    printf("\nEnter the starting balance of the account\n");
    printf("NOTE:Minimum balance to create a account is Rs 5000\n");
    scanf("%d", &b.balance);
    //minium balance of account should be 5000 to create account
    if (b.balance < 5000)
    {
        printf("\n!! Minimum balance of Rs 5000 is required to create new account\n\n");
        printf("press ENTER to continue\n\n");
        scanf("%c", &dummy);
        goto label;
    }
    //returning modified account structure
    return b;
}
//end of function to create account

//function to withdraw money from account
struct account *withdraw(struct account *ptracc)
{
    int draw, bal;
    char dummy;
    //struct account data;

again:
    printf("\nEnter the ammount to be withdrawn \nRs "); //reading amount of money to be withdrawn
    scanf("%d", &draw);
    scanf("%c", &dummy);

    if (draw <= (ptracc->balance)) //checking for available balance
    {
        ptracc->balance = ptracc->balance - draw;
        printf("\nAmount of Rs %d is withdrawn\n", draw);
        printf("Available balance after transaction is Rs %d\n", ptracc->balance);
        printf("press ENTER to continue\n\n");
        scanf("%c", &dummy);
        return ptracc;
    }
    else
    {
        printf("\nInsufficent Balance\n");
        printf("press ENTER to continue\n\n");
        scanf("%c", &dummy); //insufficent balance clause
        goto again;
    }
};

//function to deposit money into account
struct account *deposit(struct account *ptracc)
{
    int deposit;
    char dummy;
    printf("\nEnter the ammount to be deposited\nRs ");
    scanf("%d", &deposit);
    scanf("%c", &dummy);
    //depositing ,omey into account
    ptracc->balance = ptracc->balance + deposit;
    printf("\nAmount of Rs %d is deposited\n", deposit);
    printf("Available balance after transaction is Rs %d\n", ptracc->balance);
    printf("Press ENTER to continue\n\n");
    scanf("%c", &dummy);
};