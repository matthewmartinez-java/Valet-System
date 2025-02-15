//
// Created by Ahmad Harris on 12/5/24.
//

#ifndef CSC340_VALET_SYSTEM_TICKET_H
#define CSC340_VALET_SYSTEM_TICKET_H
#include "Car.h"
#include "Guest.h"
class Ticket : public ValetCompany {
public:
    Ticket();
    Ticket(int ticketNum);
    int getTicketNum() const;
    void setCarDetails(std::string make, std::string model, std::string color, std::string licensePlate);
    void setGuestDetails(std::string name, bool isVip, int ticketNum);
    void setGuestDetails(std::string name, bool isVip);
    void setTicketNum(int ticketNum);
    double getPrice();
    void print();
    Car getCarDetails();
    Guest getGuestDetails();
private:
    int ticketNum;
    double price;
    Car carDetails;
    Guest guestDetails;

};


#endif //CSC340_VALET_SYSTEM_TICKET_H
