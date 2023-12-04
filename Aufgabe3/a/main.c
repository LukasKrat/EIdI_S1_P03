#include <stdio.h>
#include "myDateFunctions.h"

#define DAILY 0;
#define WEEKLY 1;
#define TWEEKLY 2;

/// @brief This function prompts the user to provide a year, month and day via the console/terminal.
/// @param output The array in which the values of the user-input should be stored.
/// @return The number of input-parameters recognized and read from the console.
int requestInput(int output[1])
{
    puts("Bitte geben Sie <Startdatum(<JAHR> <Monat> <Tag> <Stunde> <Minute> <Sekunde>)> <Haeufigkeit> <Terminanzahl> ein:");
    /// @brief This scanf-call is used the receive a the user-input (as decimals) from standard-in and stores the values in the provided output-array via dereferencing. This way it is not necessary to return the values via a return-statement.
    return scanf("%d %d %d %d %d %d %d %d", &output[0], &output[1], &output[2], &output[3], &output[4], &output[5], &output[6], &output[7]);


}

int createAppointmentsSeries(int input[8], int output[]) {
    int year = input[0];
    int month = input[1];
    int day = input[2];
    int hour = input[3];
    int minute = input[4];
    int second = input[5];

    int modeIndex = input[6];
    int appc = input[7];

    
}

int main()
{
    int input[8] = {2000, 1, 1, 14, 05, 0};

    printf("%lld\n", toUnixtime(input));
    long long ts = toUnixtime(input);
    printf("%lld\n", toUnixtime(input));
    printf("%lld\n", ts);
    printf("%s\n", unixtimeToString(ts));

    long long int terminserie[365];
    //----------

    int exitFlag = 0;
    do
    {

        int parsedArgumentsCount = requestInput(input);

        if (parsedArgumentsCount < 8)
        {
            /// Move the "console-cursor" to the end.
            while (getchar() != '\n')
                continue;
        }

        createAppointmentsSeries(input, terminserie);


    } while (exitFlag == 0);

    return 0;
}