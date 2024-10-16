#include <stdio.h>

// Define structures for customer and call details
typedef struct {
    char name[50];
    char phoneNumber[15];
    float balance;
} Customer;

typedef struct {
    char phoneNumber[15];
    float duration; // in minutes
    float cost;
} CallDetail;

// Function prototypes
void initializeCustomer(Customer *customer);
void makeCall(Customer *customer, CallDetail *call);
void displayCustomer(Customer customer);

int main() {
    Customer customer;
    CallDetail call;
    
    initializeCustomer(&customer);
    makeCall(&customer, &call);
    displayCustomer(customer);

    return 0;
}

// Initialize customer details
void initializeCustomer(Customer *customer) {
    printf("Enter customer name: ");
    scanf("%s", customer->name);
    printf("Enter customer phone number: ");
    scanf("%s", customer->phoneNumber);
    customer->balance = 0.0; // starting with zero balance
}

// Make a call and update balance
void makeCall(Customer *customer, CallDetail *call) {
    printf("Enter call duration (in minutes): ");
    scanf("%f", &call->duration);
    printf("Enter call cost per minute: ");
    scanf("%f", &call->cost);

    // Update balance
    customer->balance -= call->duration * call->cost;
}

// Display customer details
void displayCustomer(Customer customer) {
    printf("\nCustomer Details:\n");
    printf("Name: %s\n", customer.name);
    printf("Phone Number: %s\n", customer.phoneNumber);
    printf("Balance: %.2f\n", customer.balance);
}
