#include "ars.h"

void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        printf(" ");
    }
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");
    system("clear");
    printf("\n\t\t\t***************************************************************************");
    printf("\n\t\t\t************                                                   ************");
    printf("\n\t\t\t************           Airline Booking System                  ************");
    printf("\n\t\t\t************                                                   ************");
    printf("\n\t\t\t***************************************************************************");
    printMessageCenter(message);
}
void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =              AIRLINE BOOKING              =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getchar();
}