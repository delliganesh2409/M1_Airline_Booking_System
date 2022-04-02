#ifndef ARS_H
#define ARS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
void welcomeMessage();
void headMessage(const char *message);
void printMessageCenter(const char* message);
#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20
#define FILE_NAME  "AirlineRecordSystem.bin"
#define MAX_DESTINATION 50
#define MAX_PASSENGER_NAME 50
#define MAX_PASSENGER_ADDRESS 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[MAX_SIZE_USER_NAME];
    char password[MAX_SIZE_PASSWORD];
} sFileHeader;
typedef struct
{
    unsigned int Passenger_id;
    char Destination[MAX_DESTINATION];
    char PassengerName[MAX_PASSENGER_NAME];
    char PassengerAddr[MAX_PASSENGER_ADDRESS];
    Date PassengertravellingDate;
} s_PassengerInfo;
void addPassengerInDataBase();
int isNameValid(const char *name);
int  IsLeapYear(int year);
int isValidDate(Date *validDate);
#endif