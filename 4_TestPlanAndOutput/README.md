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
|  T_11     |  h_07    | when you want cancel ticket and enter the invalid passport no | Enter choice :4 and enter invalid passport no|Ticket not found| Ticket not found| Pass|
