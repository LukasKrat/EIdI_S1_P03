#include <stdio.h>
#include "myDateFunctions.h"

#define DAILY 1
#define WEEKLY 2
#define TWEEKLY 3

#define MAXAPPOINTMENTSERIES 5
#define MAXAPPOINTMENTSPERSERIES 365

/// @brief This function prompts the user to provide a year, month and day via the console/terminal.
/// @param output The array in which the values of the user-input should be stored.
/// @return The number of input-parameters recognized and read from the console.
int requestInput(int output[])
{
    puts("Bitte geben Sie <Startdatum(<JAHR> <Monat> <Tag> <Stunde> <Minute> <Sekunde>)> <Haeufigkeit> <Terminanzahl> ein:");
    /// @brief This scanf-call is used the receive a the user-input (as decimals) from standard-in and stores the values in the provided output-array via dereferencing. This way it is not necessary to return the values via a return-statement.
    return scanf("%d %d %d %d %d %d %d %d", &output[0], &output[1], &output[2], &output[3], &output[4], &output[5], &output[6], &output[7]);
}

int getUserInputMainMenu()
{
    int input;
    printf("1. Terminserie erstellen\n"
           "2. Terminserie anzeigen\n"
           "9. Programm beenden\n");
    scanf("%d", &input);
#if WIN32 || WIN64
    fflush(stdin);
#else
    getchar();
#endif
    return input;
}

/// @brief This function sets all elements of the passed integer-array to the value of 0.
/// @param days The integer-array which's elements should be set to the value of 0.
void setAppArrayToZero(long long int days[MAXAPPOINTMENTSPERSERIES])
{
    for (int w = 0; w < MAXAPPOINTMENTSPERSERIES; w++)
    {
        days[w] = 0;
    }
}

int createAppointmentsSeries(int input[8], long long int output[])
{
    int year = input[0];
    int month = input[1];
    int day = input[2];
    int hour = input[3];
    int minute = input[4];
    int second = input[5];

    int modeIndex = input[6];
    int appc = input[7];

    printf("%d\n", modeIndex);

    switch (modeIndex)
    {
    case DAILY:
    {
        /* code */
        for (int i = 0; i < appc; i++)
        {
            int d[] = {year, month, day + i, hour, minute, second};
            output[i] = toUnixtime(d);
            printf("%d\n", d[0]);
        }

        break;
    }
    case WEEKLY:
    {
        for (int i = 0; i < appc; i++)
        {
            int d[] = {year, month, day + (i * 7), hour, minute, second};
            output[i] = toUnixtime(d);
        }

        break;
    }
    case TWEEKLY:
    {
        for (int i = 0; i < appc; i++)
        {
            int d[] = {year, month, day + (i * 14), hour, minute, second};
            output[i] = toUnixtime(d);
        }

        break;
    }
    default:
        break;
    }
}

int main()
{
    // int input[8] = {2000, 1, 1, 14, 05, 0};
    int input[8];

    printf("%lld\n", toUnixtime(input));
    long long ts = toUnixtime(input);
    printf("%lld\n", toUnixtime(input));
    printf("%lld\n", ts);
    printf("%s\n", unixtimeToString(ts));

    long long int terminserie[MAXAPPOINTMENTSERIES][MAXAPPOINTMENTSPERSERIES];
    //----------
/*
    setAppArrayToZero(terminserie);

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

        for (int i = 0; i < sizeof(terminserie) / sizeof(long long int); i++)
        {
            printf("%lld -> %s\n", terminserie[i], unixtimeToString(terminserie[i]));
        }

    } while (exitFlag == 0);
*/
    //-------------

    for (int i = 0; i < sizeof(terminserie) / sizeof(long long int[MAXAPPOINTMENTSPERSERIES]); i++) {
        setAppArrayToZero(terminserie[i]);
    }

    while (1)
    {
        int userInputMainMenu = getUserInputMainMenu();
        switch (userInputMainMenu)
        {
        case 1:
        {
            int emptySeriesIndex = -1;

            for (int i = 0; i < sizeof(terminserie) / sizeof(long long int[MAXAPPOINTMENTSPERSERIES]); i++)
            {
                if (terminserie[i][0] == 0)
                {
                    emptySeriesIndex = i;
                    break;
                }
            }

            int parsedArgumentsCount = requestInput(input);

            if (checkDateValid(input[0],input[1],input[2] != 1) ||
                input[3] > 23 || input[3] < 0 ||
                input[4] > 59 || input[4] < 0 ||
                input[5] > 59 || input[5] < 0
                ) break;

            if (parsedArgumentsCount < 8)
            {
                /// Move the "console-cursor" to the end.
                while (getchar() != '\n')
                    continue;
            }

            createAppointmentsSeries(input, terminserie[emptySeriesIndex]);
        }
        break;
        case 2:
        {
            int seriesIndex = -1;

            for (int i = 0; i < sizeof(terminserie) / sizeof(long long int[MAXAPPOINTMENTSPERSERIES]); i++)
            {
                if (terminserie[i][0] > 0) printf("%d)\n", i);
            }

            printf("%d) Cancel\n", MAXAPPOINTMENTSERIES);
            
            scanf("%d", &seriesIndex);
            getchar();
            
            if (seriesIndex >= MAXAPPOINTMENTSERIES || seriesIndex < 0) break;

            for (int i = 0; i < MAXAPPOINTMENTSPERSERIES; i++)
            {
                if (terminserie[seriesIndex][i] > 0) printf("%s\n", unixtimeToString(terminserie[seriesIndex][i]));
            }
            
        }
        break;
        case 9:
            return 0; // programm beenden
        default:
            puts("Ungueltige Eingabe!");
        }
    }

    return 0;
}