#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *shipPackage(int packageCount)
{
    char trackingNumber[26];
    char firstName[15], lastName[15];
    char street[15];
    char cityFrom[15], cityTo[15];
    char stateFrom[2], stateTo[2];
    int validFrom = 1, validTo = 1;
    char zipFrom[5], zipTo[5];

    printf("Enter your first name.\n");
    scanf("%s", firstName);

    trackingNumber[0] = firstName[0];

    printf("Enter your last name.\n");
    scanf("%s", lastName);

    trackingNumber[1] = lastName[0];

    trackingNumber[2] = '-';

    printf("Enter your street address.\n");
    scanf("%s", street);

    printf("Enter your city.\n");
    scanf("%s", cityFrom);

    printf("Enter your state.\n");
    scanf("%s", stateFrom);

    trackingNumber[3] = stateFrom[0];
    trackingNumber[4] = stateFrom[1];
    trackingNumber[5] = cityFrom[0];
    trackingNumber[6] = cityFrom[1];
    trackingNumber[7] = cityFrom[2];

    trackingNumber[8] = '-';

    printf("Enter your zip code.\n");
    scanf("%s", zipFrom);

    // if all of these statements return true

    if (strcmp(stateFrom, "FL") == 0 || strcmp(stateFrom, "NY") == 0)
    {

        if (strcmp(zipFrom, "33130") == 0 || strcmp(zipFrom, "33132") == 0 || strcmp(zipFrom, "10001") == 0 || strcmp(zipFrom, "10005") == 0)
        {
            validFrom = 1;
        }
        else
        {
            validFrom = 0;
        }
    }
    else
    {
        validFrom = 0;
    }

    if (validFrom == 0)
    {
        printf("Our services are unavailable at your location.");
        return "Services unavailable";
    }

    // Destination information

    printf("Enter destination city.\n");
    scanf("%s", cityTo);

    printf("Enter destination state.\n");
    scanf("%s", stateTo);

    printf("Enter destination zip code.\n");
    scanf("%s", zipTo);

    trackingNumber[9] = stateTo[0];
    trackingNumber[10] = stateTo[1];
    trackingNumber[11] = cityTo[0];
    trackingNumber[12] = cityTo[1];
    trackingNumber[13] = cityTo[2];

    trackingNumber[14] = '-';

    if (strcmp(stateTo, "FL") == 0 || strcmp(stateTo, "NY") == 0)
    {

        if (strcmp(zipTo, "33130") == 0 || strcmp(zipTo, "33132") == 0 || strcmp(zipTo, "10001") == 0 || strcmp(zipTo, "10005") == 0)
        {
            validTo = 1;
        }
        else
        {
            validTo = 0;
        }
    }
    else
    {
        validTo = 0;
    }

    if (validTo == 0)
    {
        printf("We do not ship to that location.\n");
        return "Services unavailable";
    }

    char monthYear[6];
    printf("Enter todays month and year in this format: MMYYYY\n");
    scanf("%s", monthYear);

    trackingNumber[15] = monthYear[0];
    trackingNumber[16] = monthYear[1];
    trackingNumber[17] = monthYear[2];
    trackingNumber[18] = monthYear[3];
    trackingNumber[19] = monthYear[4];
    trackingNumber[20] = monthYear[5];

    trackingNumber[21] = '-';

    packageCount++;
    char packageCountString[4];
    snprintf(packageCountString, 4, "%d", packageCount);

    trackingNumber[22] = '0';
    trackingNumber[23] = '0';
    trackingNumber[24] = '0';
    trackingNumber[25] = packageCountString[0];

    char option[1];

    printf("What would you like to do next?\n1. View tracking number\n2. Ship another package\n3. Exit");
    scanf("%s", option);

    if (strcmp(option, "1") == 0)
    {

        printf("Your tracking number is %s\n", trackingNumber);
    }
    else if (strcmp(option, "2") == 0)
    {
        // recursion
        shipPackage(packageCount);
    }
    else if (strcmp(option, "3") == 0)
    {

        printf("Goodbye");
        return "Shipped";
    }

    return "Shipped";
}

int main(void)
{
    printf("Hello world");
    shipPackage(0);
    return 0;
}