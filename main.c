#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "affichage.h"
#include "books.h"
#include "compare.h"

#if defined(_WIN32)
    #define PLATFORM_NAME "windows"
#elif defined(_WIN64)
    #define PLATFORM_NAME "windows"
#elif defined(__CYGWIN__) && !defined(_WIN32)
    #define PLATFORM_NAME "windows" // Windows (Cygwin POSIX under Microsoft Window)
#elif defined(__ANDROID__)
    #define PLATFORM_NAME "android" // Android (implies Linux, so it must come first)
#elif defined(__linux__)
    #define PLATFORM_NAME "linux" // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos and other
#endif


#define MAXCHAR 1000

// Return a name of platform, if determined, otherwise - an empty string
const char *get_platform_name() {
    return (PLATFORM_NAME == NULL) ? "" : PLATFORM_NAME;
}

int main(int argc, char** argv)
{

    /*
    puts(get_platform_name());
    FILE *fp = NULL;
    char row[MAXCHAR];
    char *token = NULL;

    fp = fopen("books.csv","r");

    bool firstLine = true;
    while (feof(fp) != true)
    {
        if(!firstLine)
        {
            fgets(row, MAXCHAR, fp);
            printf("Row: %s", row);


            token = strtok(row, ",");

            while(token != NULL)
            {
                printf("Token: %s\n", token);
                token = strtok(NULL, ",");
            }

        }
        else
        {
            fgets(row, MAXCHAR, fp);
            //printf("Row: %s", row);
            firstLine = false;
        }
    }

    fclose(fp);
    */

    char userChoice[1];
    bool inloop = true;
    Library library = {};
    initializeLibrary(&library);

    while(inloop)
    {
        getUserInput(userChoice);
        interactionWithTheUser(&inloop, userChoice[0], &library);
    }

    freeLibrary(&library);

    return 0;
}
