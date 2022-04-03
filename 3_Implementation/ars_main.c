#include "src/ars.h"
//extern void welcomeMessage();
//extern void headMessage(const char *message);
//extern void printMessageCenter(const char* message);

int searchPassenger()
{
    int found = 0;
    int PassengerId =0;
    s_PassengerInfo addPassengerInfoInDataBase = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("\nSEARCH PASSENGER");
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter Passenger passport ID NO to search:");
    fflush(stdin);
    scanf("%u",&PassengerId);
    while (fread (&addPassengerInfoInDataBase, sizeof(addPassengerInfoInDataBase), 1, fp))
    {
        if(addPassengerInfoInDataBase.Passenger_id == PassengerId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tPassenger id = %d\n",addPassengerInfoInDataBase.Passenger_id);
        printf("\n\t\t\tPassenger name = %s",addPassengerInfoInDataBase.PassengerName);
        printf("\t\t\tPassenger Destination = %s",addPassengerInfoInDataBase.Destination);
        printf("\n\t\t\tPassenger Address = %s",addPassengerInfoInDataBase.PassengerAddr);
        printf("\t\t\tPassenger Travelling Date(day/month/year) =  (%d/%d/%d)",addPassengerInfoInDataBase.PassengertravellingDate.dd,
               addPassengerInfoInDataBase.PassengertravellingDate.mm, addPassengerInfoInDataBase.PassengertravellingDate.yyyy);
    fflush(stdin);
    getchar();
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
    if(found){
        return 1;
    }
}
void viewPassenger()
{
    int found = 0;
    s_PassengerInfo addPassengerInfoInDataBase = {0};
    FILE *fp = NULL;
    unsigned int countPassenger = 1;
    headMessage("\nVIEW PASSENGER DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread (&addPassengerInfoInDataBase, sizeof(addPassengerInfoInDataBase), 1, fp))
    {
        printf("\n\t\t\tPassenger Count = %d\n\n",countPassenger);
        printf("\t\t\tPassenger id = %u\n",addPassengerInfoInDataBase.Passenger_id);
        printf("\t\t\tPassenger Name = %s",addPassengerInfoInDataBase.PassengerName);
        printf("\t\t\tPassenger Destination = %s",addPassengerInfoInDataBase.Destination);
        printf("\t\t\tPassenger Address = %s",addPassengerInfoInDataBase.PassengerAddr);
        printf("\n\t\t\tPassenger Seat no = %d\n\n",countPassenger);
        printf("\t\t\tPassenger Travelling Date(day/month/year) =  (%d/%d/%d)\n\n",addPassengerInfoInDataBase.PassengertravellingDate.dd,
               addPassengerInfoInDataBase.PassengertravellingDate.mm, addPassengerInfoInDataBase.PassengertravellingDate.yyyy);
        found = 1;
        ++countPassenger;
    }
    fflush(stdin);
    getchar();
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}
int deletePassenger()
{
    int found = 0;
    int PassengerDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    s_PassengerInfo addPassengerInfoInDataBase = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    headMessage("\nDelete Passenger Details");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter Passenger Passport ID NO. for delete:");
    scanf("%d",&PassengerDelete);
    while (fread (&addPassengerInfoInDataBase, sizeof(addPassengerInfoInDataBase), 1, fp))
    {
        if(addPassengerInfoInDataBase.Passenger_id != PassengerDelete)
        {
            fwrite(&addPassengerInfoInDataBase,sizeof(addPassengerInfoInDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fflush(stdin);
    getchar();
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_NAME);
    rename("tmp.bin",FILE_NAME);
    printf("\n\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
    if(found){
        return 1;
    }
}
void updateCredential(void)
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    headMessage("\nUpdate Credential");
    fp = fopen(FILE_NAME,"rb+");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    getchar();
    fgets(userName,MAX_SIZE_USER_NAME,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password,MAX_SIZE_PASSWORD,stdin);
    strncpy(fileHeaderInfo.username,userName,sizeof(userName));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\t\t\tLogin Again:");
    fflush(stdin);
    getchar();
    exit(1);
}
void menu()
{
    int choice = 0;
    do
    {
        headMessage("\nMAIN MENU");
        printf("\n\t\t\t1.BOOKING TICKET");
        printf("\n\t\t\t2.SEARCH TICKET");
        printf("\n\t\t\t3.VIEW PASSENGER DETAILS");
        printf("\n\t\t\t4.CANCELLING THE TICKET");
        printf("\n\t\t\t5.UPDATE PASSWORD");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            addPassengerInDataBase();
            break;
        case 2:
            searchPassenger();
            break;
        case 3:
            viewPassenger();
            break;
        case 4:
            deletePassenger();
            break;
        case 5:
            updateCredential();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! Try again...");
        }                                            
    }
    while(choice!=0);                                        
}
void login()
{
    unsigned char userName[MAX_SIZE_USER_NAME] = {0};
    unsigned char password[MAX_SIZE_PASSWORD] = {0};
    int L=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    headMessage("\nLOGIN DETAILS");
    fp = fopen(FILE_NAME,"rb");
    if(fp == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName,MAX_SIZE_USER_NAME,stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password,MAX_SIZE_PASSWORD,stdin);
        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        headMessage("\nLogin Failed");
        printf("\t\t\t\tSorry,Unknown User.");
        getchar();
        system("cls");
    }
}
int isFileExists(const char *path)
{
    FILE *fp = fopen(path, "rb");
    int status = 0;
    if (fp != NULL)
    {
        status = 1;
        fclose(fp);
    }
    return status;
}
void init()
{
    FILE *fp = NULL;
    int status = 0;
    const char defaultUsername[] ="user\n";
    const char defaultPassword[] ="pass\n";
    sFileHeader fileHeaderInfo = {0};
    status = isFileExists(FILE_NAME);
    if(!status)
    {
        fp = fopen(FILE_NAME,"wb");
        if(fp != NULL)
        {
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}
//#if 0
int main()
{
    init();
    welcomeMessage();
    login();
    return 0;
}
/*#endif
void test_search_passenger(){
    if(1==searchPassenger()){
        printf("Passenger exist");
    }
    else{
        printf("Not exist");
    }
}
void test_delete_passenger(){
    if(1==deletePassenger()){
        printf("Passenger record delete");
    }
    else{
        printf("Passenger record not found");
    }
}*/