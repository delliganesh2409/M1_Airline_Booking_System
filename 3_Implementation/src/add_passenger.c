#include "ars.h"

int isNameValid(const char *name)
{
    int validName = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            validName = 0;
            break;
        }
    }
    return validName;
}
int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
int isValidDate(Date *validDate)
{
    if (validDate->yyyy > MAX_YR ||
            validDate->yyyy < MIN_YR)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}
void addPassengerInDataBase()
{
    s_PassengerInfo addPassengerInfoInDataBase = {0};
    FILE *fp = NULL;
    int status = 0;
    fp = fopen(FILE_NAME,"ab+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("\nAdd Passenger Details");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\tPassenger Passport ID  = ");
    fflush(stdin);
    scanf("%u",&addPassengerInfoInDataBase.Passenger_id);
    do
    {
        printf("\n\t\t\tPassenger Name  = ");
        fflush(stdin);
        getchar();
        fgets(addPassengerInfoInDataBase.PassengerName,MAX_PASSENGER_NAME,stdin);
        status = isNameValid(addPassengerInfoInDataBase.PassengerName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tEnter Passenger Destination  = ");
        fflush(stdin);
        fgets(addPassengerInfoInDataBase.Destination,MAX_DESTINATION,stdin);
        status = isNameValid(addPassengerInfoInDataBase.Destination);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tPassenger Address  = ");
        fflush(stdin);
        fgets(addPassengerInfoInDataBase.PassengerAddr,MAX_PASSENGER_ADDRESS,stdin);
        status = isNameValid(addPassengerInfoInDataBase.PassengerAddr);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tEnter date in format (day/month/year): ");
        scanf("%d/%d/%d",&addPassengerInfoInDataBase.PassengertravellingDate.dd,&addPassengerInfoInDataBase.PassengertravellingDate.mm,&addPassengerInfoInDataBase.PassengertravellingDate.yyyy);
        status = isValidDate(&addPassengerInfoInDataBase.PassengertravellingDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&addPassengerInfoInDataBase,sizeof(addPassengerInfoInDataBase), 1, fp);
    fclose(fp);
}