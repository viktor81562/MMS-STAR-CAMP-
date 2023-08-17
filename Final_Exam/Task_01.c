#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_STRING_LENGTH 100
#define ITEMS_COUNT 10

// Направете структура BankAccount, която да има:
// номер - цяло положително 16 битово число;
// име на притежател - символен низ до 100 символа;
// наличност - реално число;
// валута - символен низ до 4 символа.

// Да се направи свързан списък от ITEMS_COUNT (препроцесорна константа) елементи.
//  Да се генерират автоматично произволни данни, с които да се запълни списъка от предмети.
// Ограничения за произволните данни:
// номер - цяло положително 16 битово число - уникално за всеки елемент в списъка;
// име на притежател - Съдържа между 2 и 5 произволни думи, разделени с интервал.
//  Всяка дума е между 1 и 20 произволни символа (малки или главни латински букви). 
//   Всяка дума започва с главна буква.
// наличност - реално число между 0.00лв и 100 000.00лв;
// валута - избира се от предварително създаден масив от символни низове.

// Да се реализират следните функции които обработват свързания списък:
// функция, която намира общата наличност на всички елементи в списъка. При неуспех да върне -1.
// double totalBalance(node_t* head);
// функция, която намира банковата сметка с най-висока наличност. 
// При успех да върне указател към елемента, а при неуспех нулев указател.
//                node_t * maxBalance(node_t* head);


// Изведете съдържанието на списъка в стандартния изход с подходящо форматиране.
//  Да се изведе общата наличност на банковите сметки и информация за банковата сметка с най-висока наличност.

typedef struct BankAccount{

uint16_t number;
char ownerName[100];
double balance;
char currency[4];
void *next;
}BankAccount;



BankAccount *createBankAccount(uint16_t number, char* ownerName, double balance,const char* currency){
    BankAccount* account = (BankAccount*)malloc(sizeof(BankAccount));
    if(account == NULL){
        perror("Memory allocation problem!");
        exit(-1);
    }
     account->number = number;
    strncpy(account->ownerName, ownerName, MAX_STRING_LENGTH - 1);
    account->ownerName[MAX_STRING_LENGTH - 1] = '\0';
    account->balance = balance;
    strncpy(account->currency, currency, 4);
    account->currency[4] = '\0';
    account->next = NULL;
    
    return account;
}

double totalBalance(BankAccount* head) {
    double total = 0.0;
    while ((head) != NULL) {
        total += (head)->balance;
        head = (head)->next;
    }
    if(total < 1){
        return -1;
    }
    return total;
}
BankAccount* maxBalance(BankAccount* head) {
    BankAccount* maxAccount = NULL;
    double maxBalance = -1.0;
    while ((head) != NULL) {
        if ((head)->balance > maxBalance) {
            maxBalance = (head)->balance;
            maxAccount = (head);
        }
        head = head->next;
    }
    return maxAccount;
}

void printBankAccounts(BankAccount* head) {
    while (head != NULL) {
        printf("Number: %d\n", head->number);
        printf("Owner: %s\n", head->ownerName);
        printf("Balance: %.2f %s\n", head->balance, head->currency);
        printf("\n");
        head = head->next;
    }
}
void deinitBankAccounts(BankAccount *head){
    BankAccount *temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    
}

int main() {
    const char* currencies[] = {"BGN", "USD", "EUR", "GBP"};
    BankAccount* accounts = NULL;
    
    srand(time(NULL));
    
    for (int i = 0; i < ITEMS_COUNT; i++) {

        uint16_t number = rand() % 65536;

        char ownerName[MAX_STRING_LENGTH];

        snprintf(ownerName, sizeof(ownerName), "Owner%d", i);

        double balance = (rand() % 10000001) / 100.0;

        const char* currency = currencies[rand() % 4];

        BankAccount* account = createBankAccount(number, ownerName, balance, currency);
        
        account->next = accounts;
        accounts = account;
    }
    
    printBankAccounts(accounts);
    
    double total = totalBalance(accounts);
    printf("Total Balance: %.2f\n", total);
    
    BankAccount* max = maxBalance(accounts);

    if (max != NULL) {
        printf("Account with Max Balance: \n");
        printf("Number: %d\n", max->number);
        printf("Owner: %s\n", max->ownerName);
        printf("Balance: %.2lf %s\n", max->balance, max->currency);
    } else {
        printf("No accounts found.\n");
    }

    deinitBankAccounts(accounts);
    
    return 0;
}

// da osvobodq zadalenata pamet 
// da opravq imenata 





