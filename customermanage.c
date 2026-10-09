

#include <stdio.h>
#include <string.h>
#include "customermanage.h"
#include "roommanage.h"

#define MAX_CUSTOMERS 100

struct Customer customers[MAX_CUSTOMERS];
int customerCount = 0;

extern struct Room rooms[MAX_ROOMS];


void addCustomer(void) {
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Customer storage is full!\n");
        return;
    }

    int roomNumber;
    int roomIndex = -1;

    // Generate customer ID automatically
    customers[customerCount].customerId = customerCount + 1;

    printf("Customer ID: %d\n",
           customers[customerCount].customerId);

    printf("Enter customer name: ");
    scanf(" %49[^\n]", customers[customerCount].name);

    printf("Enter phone number: ");
    scanf("%14s", customers[customerCount].phone);

    printf("Enter room number: ");
    if (scanf("%d", &roomNumber) != 1) {
        printf("Invalid room number.\n");
        return;
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            roomIndex = i;
            break;
        }
    }

    if (roomIndex == -1) {
        printf("Room does not exist.\n");
        return;
    }

    if (!rooms[roomIndex].isAvailable) {
        printf("Room is already occupied.\n");
        return;
    }

    customers[customerCount].roomNumber = roomNumber;
    rooms[roomIndex].isAvailable = 0;
    customerCount++;

    printf("Customer registered successfully!\n");
}


void displayCustomers(void) {
    if (customerCount == 0) {
        printf("No customers registered yet.\n");
        return;
    }

    printf("\n===== CUSTOMER LIST =====\n");

    for (int i = 0; i < customerCount; i++) {
        printf("Customer ID: %d\n", customers[i].customerId);
        printf("Name: %s\n", customers[i].name);
        printf("Phone: %s\n", customers[i].phone);
        printf("Room Number: %d\n", customers[i].roomNumber);
        printf("----------------------\n");
    }
}


void checkoutCustomer(void) {
    int id;
    int customerIndex = -1;
    int roomNumber;

    printf("Enter customer ID for checkout: ");

    if (scanf("%d", &id) != 1) {
        printf("Invalid customer ID.\n");
        return;
    }

    for (int i = 0; i < customerCount; i++) {
        if (customers[i].customerId == id) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex == -1) {
        printf("Customer not found.\n");
        return;
    }

    roomNumber = customers[customerIndex].roomNumber;

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            rooms[i].isAvailable = 1;
            break;
        }
    }

    // Remove the customer by shifting later records
    for (int i = customerIndex; i < customerCount - 1; i++) {
        customers[i] = customers[i + 1];
    }

    customerCount--;

    printf("Checkout successful. Room %d is now available.\n",
           roomNumber);
}


void customerMenu(void) {
    int choice;

    do {
        printf("\n===== CUSTOMER MANAGEMENT =====\n");
        printf("1. Register Customer / Book Room\n");
        printf("2. Display Customers\n");
        printf("3. Customer Checkout\n");
        printf("4. Back to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        
        switch (choice) {
            case 1:
                addCustomer();
                break;

            case 2:
                displayCustomers();
                break;

            case 3:
                checkoutCustomer();
                break;

            case 4:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);
}
