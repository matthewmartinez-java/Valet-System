//
// Created by Ahmad Harris on 12/5/24.
//

#include "Supervisor.h"

Supervisor::Supervisor(std::string name) : Employee(name) {}

Supervisor::Supervisor(std::vector<Valet> valets, std::string name) : Employee(name) {

    for (Valet v : valets) {
        this->valets.append(v);
    }
}

Supervisor::Supervisor(Valet valet, std::string name) : Employee(name) {
    this->valets.append(valet);
}

Supervisor::Supervisor(LinkedList valets, std::string name) : Employee(name) {
    this->valets = valets;
}

Supervisor::Supervisor(std::vector<Ticket> tickets, std::string name) : Employee(name) {
    this->tickets = tickets;
}

int Supervisor::generateTicket() {
    int ticketNumber = createTicketNum();
    Ticket newTicket(ticketNumber);
    assignValet(newTicket, true);
    tickets.push_back(newTicket);
    sortTickets();
    return ticketNumber;
}

std::vector<Ticket> Supervisor::getTickets() {
    return tickets;
}

int Supervisor::findTicket(int ticketNumber) {
    int low = 0, high = tickets.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (tickets[mid].getTicketNum() == ticketNumber) {
            return mid; // Return the index of the ticket
        } else if (tickets[mid].getTicketNum() < ticketNumber) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }
    return -1;
}

void Supervisor::sortTickets() {
    for (size_t i = 0; i < tickets.size(); ++i) {
        for (size_t j = 0; j < tickets.size() - i - 1; ++j) {
            if (tickets[j].getTicketNum() > tickets[j + 1].getTicketNum()) {
                // Swap the tickets
                Ticket temp = tickets[j];
                tickets[j] = tickets[j + 1];
                tickets[j + 1] = temp;
            }
        }
    }
}

void Supervisor::customerReturn(int ticketNumber) {

// Make sure the ticket exists
    int index = findTicket(ticketNumber);
    if (index != -1) {
        Ticket returnTicket = tickets[index];
        tickets.erase(tickets.begin() + index);
        assignValet(returnTicket, false);
    } else {
        std::cout << "Ticket not found! Please file a missing car claim!" << std::endl;
    }

}

void Supervisor::assignValet(Ticket &ticket, bool newArrival) {
    Valet* nextValet = nullptr;

    // Loop to find a working valet
    do {
        nextValet = valets.getNext();
        if (!nextValet) {
            std::cout << "No valets available for assignment!" << std::endl;
            return;
        }
    } while (!nextValet->getStatus());

    std::cout << "Assigning Valet " << nextValet->getName() << " for ticket #: "
              << ticket.getTicketNum() << std::endl;

    if (newArrival) {
        nextValet->parkCar();
        nextValet->fillTicket(ticket);
    } else {
        nextValet->returnCar();
    }
}

int Supervisor::customerArrival() {
    std::string name;
    bool isVip = false;
    std::cout << "----------NEW CAR----------" << std::endl;
    std::cout << "Enter guest name: " << std::endl;
    getline(std::cin, name);
    int num = generateTicket();
    fillCustomerDetails(name, num);
    return num;
}

Supervisor::Supervisor() {}

int Supervisor::createTicketNum() {
    using namespace std::chrono;
    return abs(duration_cast<milliseconds>(
            system_clock::now().time_since_epoch())
            .count());
}

void Supervisor::fillCustomerDetails(std::string name, int ticketNum) {
    bool isVip = false;
    if (name == "Corey Carito")
        isVip = true;
    tickets[findTicket(ticketNum)].setGuestDetails(name, isVip, ticketNum);
}


void Supervisor::setValets(std::vector<Valet> valets) {

    for (Valet v : valets) {
        this->valets.append(v);
    }
}

void Supervisor::setValets(LinkedList valets) {
    this->valets = valets;
}

void Supervisor::addValet(Valet valet) {
    this->valets.append(valet);
}

void Supervisor::setTickets(std::vector<Ticket> tickets) {
    this->tickets = tickets;
}

Ticket &Supervisor::getTicket(int ticketNum) {
    return tickets[findTicket(ticketNum)];
}

