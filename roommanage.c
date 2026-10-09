
#include <stdio.h>
#include "roommanage.h"

struct Room rooms[MAX_ROOMS];


    

void initializeRooms(void) {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = 101 + i;
        rooms[i].isAvailable = 1;

        if (i < 8) {
            snprintf(rooms[i].type, sizeof(rooms[i].type), "Standard");
            rooms[i].price = 1500;
        } else if (i < 15) {
            snprintf(rooms[i].type, sizeof(rooms[i].type), "Deluxe");
            rooms[i].price = 2500;
        } else {
            snprintf(rooms[i].type, sizeof(rooms[i].type), "Suite");
            rooms[i].price = 4000;
        }
    }
}

void displayRooms(void) {
    printf("\n========== ROOM LIST ==========\n");

    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("Room: %d | Type: %s | Price: Rs. %.2f | %s\n",
               rooms[i].roomNumber,
               rooms[i].type,
               rooms[i].price,
               rooms[i].isAvailable ? "Available" : "Occupied");
    }
}


void searchRoom(void) {
    int number;

    printf("Enter room number to search: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return;
    }

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].roomNumber == number) {
            printf("\nRoom Number: %d\n", rooms[i].roomNumber);
            printf("Type: %s\n", rooms[i].type);
            printf("Price per night: Rs. %.2f\n", rooms[i].price);
            printf("Availability: %s\n",
                   rooms[i].isAvailable ? "Available" : "Occupied");
            return;
        }
    }

    printf("Room number not found.\n");
}


void roomMenu(void) {
    int choice;

    do {
        printf("\n===== ROOM MANAGEMENT =====\n");
        printf("1. Display All Rooms\n");
        printf("2. Search Room\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            return;
        }

        switch (choice) {
            case 1:
               displayRooms();
               break;
            case 2:
                searchRoom();
                break;
            case 3:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice!\n");
    }}while (choice != 3);
}