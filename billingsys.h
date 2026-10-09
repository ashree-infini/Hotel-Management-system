

#ifndef BILLINGSYS_H
#define BILLINGSYS_H

#define MAX_BILLS 100

struct Bill {
    int billId;
    int customerId;
    int roomNumber;
    int numberOfNights;

    float roomCharge;
    float foodCharge;
    float serviceCharge;
    float subtotal;
    float tax;
    float total;
};

void billingMenu(void);

#endif
