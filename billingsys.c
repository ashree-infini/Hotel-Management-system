

#include <stdio.h>
#include "billingsys.h"
#include "roommanage.h"
#include "customermanage.h"

extern struct Room rooms[MAX_ROOMS];
extern struct Customer customers[MAX_CUSTOMERS];
extern int customerCount;

struct Bill bills[MAX_BILLS];
int billCount = 0;

void generateBill(void) {
    int customerId;
    int customerIndex = -1;
    int roomIndex = -1;
    int nights;
    struct Bill bill = {0};

    if (billCount >= MAX_BILLS) {
        printf("Bill storage is full!\n");
        return;
    }

    printf("Enter customer ID: ");
    if (scanf("%d", &customerId) != 1) {
        printf("Invalid customer ID.\n");
        return;
    }

    // Find the customer
    for (int i = 0; i < customerCount; i++) {
        if (customers[i].customerId == customerId) {
            customerIndex = i;
            break;
        }
    }

    if (customerIndex == -1) {
        printf("Customer not found. Register the customer first.\n");
        return;
    }

    int roomNumber = customers[customerIndex].roomNumber;

    // Find the customer's room
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].roomNumber == roomNumber) {
            roomIndex = i;
            break;
        }
    }

    if (roomIndex == -1) {
        printf("Room information not found.\n");
        return;
    }

    printf("Customer: %s\n", customers[customerIndex].name);
    printf("Room: %d (%s)\n",
           rooms[roomIndex].roomNumber,
           rooms[roomIndex].type);
    printf("Price per night: Rs. %.2f\n",
           rooms[roomIndex].price);

    printf("Enter number of nights: ");
    if (scanf("%d", &nights) != 1 || nights <= 0) {
        printf("Number of nights must be positive.\n");
        return;
    }

    bill.billId = billCount + 1;
    bill.customerId = customerId;
    bill.roomNumber = roomNumber;
    bill.numberOfNights = nights;

    bill.roomCharge = rooms[roomIndex].price * nights;

    printf("Enter food charges (Rs.): ");
    if (scanf("%f", &bill.foodCharge) != 1 ||
        bill.foodCharge < 0) {
        printf("Invalid food charges.\n");
        return;
    }

    printf("Enter service charges (Rs.): ");
    if (scanf("%f", &bill.serviceCharge) != 1 ||
        bill.serviceCharge < 0) {
        printf("Invalid service charges.\n");
        return;
    }

    bill.subtotal = bill.roomCharge
                  + bill.foodCharge
                  + bill.serviceCharge;

    // Example tax rate: 5%. This is a project assumption,
    // not a statement of the applicable hotel tax rate.
    bill.tax = bill.subtotal * 0.05f;
    bill.total = bill.subtotal + bill.tax;

    bills[billCount] = bill;
    billCount++;

    printf("\n========== HOTEL BILL ==========\n");
    printf("Bill ID: %d\n", bill.billId);
    printf("Customer ID: %d\n", bill.customerId);
    printf("Customer Name: %s\n", customers[customerIndex].name);
    printf("Room Number: %d\n", bill.roomNumber);
    printf("Number of Nights: %d\n", bill.numberOfNights);
    printf("Room Charge: Rs. %.2f\n", bill.roomCharge);
    printf("Food Charges: Rs. %.2f\n", bill.foodCharge);
    printf("Service Charges: Rs. %.2f\n", bill.serviceCharge);
    printf("Subtotal: Rs. %.2f\n", bill.subtotal);
    printf("Example Tax (5%%): Rs. %.2f\n", bill.tax);
    printf("--------------------------------\n");
    printf("TOTAL: Rs. %.2f\n", bill.total);
    printf("================================\n");
}

void displayBills(void) {
    if (billCount == 0) {
        printf("No bills generated yet.\n");
        return;
    }

    printf("\n========== BILL HISTORY ==========\n");

    for (int i = 0; i < billCount; i++) {
        printf("Bill ID: %d | Customer ID: %d | Room: %d\n",
               bills[i].billId,
               bills[i].customerId,
               bills[i].roomNumber);

        printf("Nights: %d | Total: Rs. %.2f\n",
               bills[i].numberOfNights,
               bills[i].total);

        printf("----------------------------------\n");
    }
}

void billingMenu(void) {
    int choice;

    do {
        printf("\n===== BILLING SYSTEM =====\n");
        printf("1. Generate Bill\n");
        printf("2. Display Bill History\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        switch (choice) {
            case 1:
                generateBill();
                break;

            case 2:
                displayBills();
                break;

            case 3:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);
}
