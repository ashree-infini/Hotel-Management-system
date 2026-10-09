
#include <stdio.h>
#include <stdio.h>
#include "roommanage.h"
#include "customermanage.h"
#include "billingsys.h"

int main(void) {
    int choice;
    initializeRooms();

    do {
        printf("\n===== HOTEL MANAGEMENT SYSTEM =====\n");
        printf("1. Room Management\n");
        printf("2. Customer Management\n");
        printf("3. Billing System\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                roomMenu();
                break;

            case 2:
                customerMenu();
                break;

            case 3:
                billingMenu();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
