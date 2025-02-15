//
// Created by Ahmad Harris on 12/5/24.
//

#ifndef CSC340_VALET_SYSTEM_GUEST_H
#define CSC340_VALET_SYSTEM_GUEST_H
#include "ValetCompany.h"

class Guest : public  ValetCompany {
public:
    Guest();
    Guest(std::string name);
    Guest(int ticketNum, std::string name);
    std::string getName();
    int requestCar();
    void getStatus();
    void print();
    void setName(std::string name);
    void setVIP(bool vip);
    void setTicketNum(int ticketNum);
private:
    int ticketNum;
    std::string name;
    bool isVIP;

};


#endif //CSC340_VALET_SYSTEM_GUEST_H
