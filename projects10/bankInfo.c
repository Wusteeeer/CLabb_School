#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MAXNAMELENGTH 40

typedef struct account{
    
    char name[MAXNAMELENGTH];
    int money;

}Account;

Account createAccount(char name[], int money);

void printAccount(Account acc);
void transfer(Account *acc1, Account *acc2);

int main(){

    printf("\n");

    Account account1 = createAccount("Simran Singh", 3210);
    Account account2 = createAccount("Mark Asplund", 210);
    
    printAccount(account1);
    printAccount(account2);

    transfer(&account1, &account2);

    printAccount(account1);
    printAccount(account2);

    return 0;
}

Account createAccount(char name[], int money)
{

    Account acc;
    acc.money = money;
    strcpy(acc.name, name);

    return acc;

}

void printAccount(Account acc){

    puts(acc.name);
    printf("%d\n", acc.money);

}

void transfer(Account *acc1, Account *acc2){

    acc2->money += acc1->money;

    acc1->money = 0;

}