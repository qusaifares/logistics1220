##### Student: Qusai Fares

##### Professor Muzhgan Manati

##### COP1220

##### 20 July 2020

# Logistics1220

In this project, I built a program to handle and manage shipping orders made by a customer who inputs his information, as well as information on the shipping origin and destination.

## Tracking Number

Below is an example of a tracking number.
`QF-FLMIA-NYNEW-072020-0001`

The first two characters are the user's initials, then an abbreviation of the origin state and city, then the destination state and city, after that is the current month and year in MMYYYY format and finally, an identifier that starts at 0001 and increases with the package count to make sure every tracking number is unique.

## Logic

This program incorporates variable usage, conditionals, comparison operators, recursion and more.

Below is a code sample that served to validate that our services are available at the location provided. If the address is invalid, the `validFrom` variable will be assigned the value `0` and will inform the user that our services are unavailable then end the function altogether.

```C
    int validFrom = 1;

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
```

Another piece of code I want to highlight is the use of the `packageCount` parameter when recursively calling the `shipPackage` function. When the a shipment is submitted successfully, the `packageCount` variable is incremented by 1, then the user has the option to ship another package, where the function will be called as:
`shipPackage(packageCount);`

Where `packageCount` will continue to be incremented as long as more packages are being shipped.

All of this would put me above my competitors in terms of reliability and accuracy.

## If it was for a real company

One thing I definitely would have added if this was for a real company is input validation.

Currently the program only functions properly if valid inputs are given. A professional program should expect any input from a user and have appropriate responses and logic carried out for different inputs.
