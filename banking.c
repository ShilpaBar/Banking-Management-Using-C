
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int account_number;
    char name[100];
    float balance;
} Customer;

void add_customer(Customer customers[], int *num_customers);
void display_customers(Customer customers[], int num_customers);
void deposit(Customer customers[], int num_customers);
void withdraw(Customer customers[], int num_customers);

int main() {
    Customer customers[1000];
    int num_customers = 0;
    int choice;

    while (1) {
        printf("1. Add customer\n");
        printf("2. Display customers\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_customer(customers, &num_customers);
                break;
            case 2:
                display_customers(customers, num_customers);
                break;
            case 3:
                deposit(customers, num_customers);
                break;
            case 4:
                withdraw(customers, num_customers);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

void add_customer(Customer customers[], int *num_customers) {
    Customer new_customer;

    printf("Enter account number: ");
    scanf("%d", &new_customer.account_number);
    printf("Enter name: ");
    scanf("%s", new_customer.name);
    printf("Enter balance: ");
    scanf("%f", &new_customer.balance);

    customers[*num_customers] = new_customer;
    (*num_customers)++;
}

void display_customers(Customer customers[], int num_customers) {
	int i;
    for (i = 0; i < num_customers; i++) {
        printf("Account number: %d\n", customers[i].account_number);
        printf("Name: %s\n", customers[i].name);
        printf("Balance: %.2f\n", customers[i].balance);
        printf("\n");
    }
}

void deposit(Customer customers[], int num_customers) {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
	int i=0;
    for (i = 0; i < num_customers; i++) {
    	
        if (customers[i].account_number == account_number) {
            customers[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

void withdraw(Customer customers[], int num_customers) {
    int account_number;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &account_number);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
	int i;
    for (i = 0; i < num_customers; i++) {
    	
        if (customers[i].account_number == account_number) {
            if (customers[i].balance < amount) {
                printf("Insufficient balance!\n");
            } else {
                customers[i].balance -= amount;
                printf("Withdrawal successful!\n");
            }
            return;
        }
    }

    printf("Account not found!\n");
}


