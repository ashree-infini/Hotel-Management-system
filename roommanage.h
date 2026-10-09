
#ifndef ROOMMANAGE_H
#define ROOMMANAGE_H

#define MAX_ROOMS 20

struct Room {
    int roomNumber;
    char type[20];
    float price;
    int isAvailable;
};

void roomMenu(void);
void initializeRooms(void);
void searchRoom(void);

#endif
