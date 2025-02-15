This C++ project implements a comprehensive Valet System designed to emulate the efficient operations of a valet system. Employees interact with the system through a menu-driven interface to perform tasks such as clocking in, manage vehicle parking, retrrieval, filing damage claims, and managing shifts. The simulation begins with employees logging in, choosing a role (supervisor or attendee), and inputting their names. Once logged in, employees can access a detailed operations menu, offering options like registering new cars, retrieving vehicles, ending shift, etc. 

The program offers realistic vehicle logging by collecting detailed information about each guest's car, including make, model, color, license plate, and specific attributes like whether the car is manual, electric, or oversized. Tickets are issued for each car, and parking fees are calculated based on the duration of the stay, with VIP guests enjoying free parking. Car retrievals include simulated waiting times, while parking lot contents are dynamically updated as cars are added or removed. Damage claims can also be filed if necessary, ensuring thorough record-keeping.

The simulation is highly interactive, using utility functions like writeToScreen for dynamic ouput and introducing delays with quickDelay, longDelay, and microDelay for a more engaging experience. It includes robust error handling for invalid inputs, ensuring smooth operation. The system also maintains a parking lot inventory and employee logs, demonstrating a practical application of object-oriented programming. Overall, this simulation is a comprehensive tool for training, offering a realistic and engaging experience in valet management.


Features:
-Vehicle Management: Handles dynamic parking of vehicles, keeping track of details like vehicle ID, owner name, parking spot, etc.
-Efficient Retrieval System: Allows for quick retrieval of vehicles by parking spot or ID, minimizing retrieval time

Technologies Used:
-Programming Language: C++
-Data Structures: Linked Lists, arrays, vectors, inheritance

Future Enhancements:
-Integration with databases for long-term vehicle data storage
-Web-based or mobile application for ease of user access
-Implementing automatic parking assistance using sensors (conceptually)


Credits: Matthew Martinez, Ahmad Harris, William Wong
