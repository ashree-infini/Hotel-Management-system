

#ifndef CUSTOMERMANAGE_H
#define CUSTOMERMANAGE_H
#define MAX_CUSTOMERS 100

struct Customer {
    int customerId;
    char name[50];
    char phone[15];
    int roomNumber;
};

void customerMenu(void);
void checkoutCustomer(void);

#endif
