
# Airline Booking System 

The Airline Booking System project is the application based mini project, which is used to book airline ticket and cancelling booked ticket. The tool used for writing the code in this project is visual studio code. This project has multi file and multiplatform approach (Linux and Windows).





## Identifying Features

- Book tickets
- Search tickets
- View all booking records
- Cancel tickets 
- Updated your login id and password  


## State of art/Research 
People who have technical knowledge of booking the airline ticket in online, can use this application to booking ticket, search the ticket, view the passenger details, cancelling the ticket and used for updating username and password for login.
## SWOT analysis

Strengths: 
An Airline booking system is very important because it has the strong ability to reduce errors that might have occurred when using a manual system of reservation  and  helps  speed  up  the  boarding  process.


Weakness: 
The problems are inability of passengers to select their preferred  seat(s) from the  reservation system, No option of passengers printing  their boarding pass, non-notification  of passengers of flight cancellation or delays and passengers don‘t  have access to  aircraft  maintenance  report  to  ease the fears associated with air travel and its disasters.


Opportunities: 
The need of this system was realized since the beginning stages of the airline industry when information such as routes, aircrafts, schedules and fares about flights was published by airlines in large books. Travel agents had the difficult task of looking into separate books for reservations that involve multiple airlines. It was a dream to get a real time picture of available seats because airlines share information at day end only.


Threats: 
Slower growth in an innovation always threat for the company in this dynamic world.


## 4W's  1-H

What: Airline Booking System**

Where: Anywhere

When: Need for Airline Ticket.

How: By creating a system which will provide all the functionalities required, the booking of, cancelling of the tickets and other actions will be take more time and system needs more workers for these actions.
## High Level Requirements:

| ID        |  Description                                       | Category                   |  Status         |
| :-------- | :--------------------------------                  | :------------------------- | :-------------- |
| `HR01`    | `User shall be able to login to the system`        | `Techincal`                |  `IMPLEMENTED ` |
|  `HR02`   | `User shall be able to book a ticket`              |   `Techincal`              | `IMPLEMENTED `  |   
|`HR03`     | `User shall be able to get summary of the ticket booked`|	`Techincal`	          |`IMPLEMENTED`    |
|`HR04`	    |`User shall be able to cancel a ticket`             |	`Techincal`	              |`IMPLEMENTED`    |
|`HR05`     |`User shall be able to view the reserved seats`     |	`Techincal`	              |`IMPLEMENTED`    |



## low level Requriments  

|  ID   |  Description                                          |  HLR ID              | Status (Implemented/Future)|           
| :-----| :---------------------------------------------------- | :--------------------| :-------------------|
| `LR01`|	`User shall be able to login to the system with correct login details`	|`HR01`|	`IMPLEMENTED`|
|`LR02`	|  `User need to book a ticket in a user entry mode`|     ` HR01`	|`IMPLEMENTED`
|`LR03` |	`If appropriate login details are not entered a message is displayed-"wrong password"`|  `HR01`|	`IMPLEMENTED`|
|`LR04`|	`User can view the booked details `	                             |       `HR02`	|`IMPLEMENTED`|
|`LR05`|	`User can change the login id and password`	                      |      `HR02`|	`IMPLEMENTED`|

## Best Methods followed

Best method to followed is high level method.




# Behaviour Diagrams

## Low level Diagram
![lowlevel_beh](https://github.com/delliganesh2409/M1_Airline_Booking_System/blob/main/2_Architecture/structure%20Diagrams/lowlevel_behaviour.png)

## High level Diagram
![highlevel_beh](https://github.com/delliganesh2409/M1_Airline_Booking_System/blob/main/2_Architecture/structure%20Diagrams/highlevel_behaviour.png)



# Structure Diagrams

## Low Level Diagram

![Low_structure](https://github.com/delliganesh2409/M1_Airline_Booking_System/blob/main/2_Architecture/structure%20Diagrams/lowlevel.png)

## High Level Diagram

![High_level](https://github.com/delliganesh2409/M1_Airline_Booking_System/blob/main/2_Architecture/structure%20Diagrams/highlevel.png)




# Test plan and Output

|  TEST ID  |  HLT ID |                        Description                              |  Exp input          |    Exp output       |     Actual Output   |  Pass/Fail  | 
| :---------| :------ | :---------------------------------------------------------------| :--------------     |:----------------    | :-------------------| :-----------|
|  T_01     |  H_01   |  Provide required details for login to book a airline ticket    |      password       |successfully logined in |Successfully logined in| Pass   |
|  T_02     |  H_01   |  When wrong password is entered                                 |      password       |Login failed Enter again| Login failed Enter again| Pass|
|  T_03     |  H_02   |   Dispaly the details of main menu                              |  Press any key      | Display List     | Display list| Pass|
|  T_04     |  H_03   |   Book a airline ticket                                         |  Enter Choice :1    | Enter your details below| Enter your details below| Pass |
|  T_05     |  H_03   |   When you want to book ticket and enter wrong details          |  Enter choice : 1 and enter wrong details |  Name cointain invalid character and please enter again | Name cointain invalid character and please enter again | Pass|
|   T_06    |  H_04   |  When you enter the choice which is not available in main menu|   Enter the choice which is not in main menu| Invalid input!! try again|Invalid input!! try again| Pass|
|  T_07     |  H_05    | When you want search a ticket | Enter choice :2 | Enter passenger passport no|Enter passenger passport no| Pass |
|  T_08     |  H_05    | When you want search a ticket and enter invalid passport no | Enter choice :2 and enter invalid password number|No Record|No Record |Pass|
|  T_09     |  H_06    | when you want see all passenger details with count and seat no | Enter choice :3 | View passenger details|  View passenger details | Pass |
|  T_10     |  H_07    | when you want cancel ticket | Enter choice :4 | Enter passenger passport no|Enter passenger passport no|Pass|
|  T_11     |  H_07    | when you want cancel ticket and enter the invalid passport no | Enter choice :4 and enter invalid passport no|Ticket not found| Ticket not found| Pass|
|  T_12     |  H_08    | When you want to change your username and password | Enter choice :5|Enter new username and enter new password| Enter new username and enter new password|Pass|
|  T_13     |  H_09    |   when you want to exit | Enter choice : 0| Thank You!!! | Thank You !!!| Pass |
