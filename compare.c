#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

bool compare_string(char* var1, char* var2)
{

    if(var1 != NULL && var2 != NULL)
    {
        size_t var1_byte_lenght = strlen(var1);
        size_t var2_byte_lenght = strlen(var2);

        int var1_lenght = var1_byte_lenght / sizeof(char);
        int var2_lenght = var2_byte_lenght / sizeof(char);

        int mini = MIN(var1_lenght, var2_lenght);

        for(int i = 0; i < mini; i++)
        {
            if(var1[i] != var2[i])
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

int sizeOfInteger(int integer)
{
    if(integer == 0)
    {
        return 1;
    }
    else if (integer > 0)
    {
        int n = (int) log10((double) integer) + 1;
        return n;
    }
    else
    {
        printf("Line :%d\n", __LINE__ );
        printf("sizeOfInteger is not implemented for negative number, the returned value is 0\n");
        return 0;
    }
}

int* intToListOfDigits(int integer)
{
    int n = sizeOfInteger(integer);
    if(n==0)
    {
        return NULL;
    }
    else
    {
        // The malloc is only used in compare_int function and is freed with freeIntList function
        int* listDigit =  (int *) malloc(sizeof(int));
        for(int i = n-1; i>=0; i--)
        {
            int modInt = integer % 10;
            listDigit[i] = modInt;

            integer = (int) ((integer - modInt) / 10);
        }

        return listDigit;
    }
}

void freeIntList(int * ptrInt)
{
    if(ptrInt != NULL)
    {
        free(ptrInt);
    }
    else
    {
        printf("Line: %d\n", __LINE__);
        printf("\nThe pointer ptrInt in freeIntList method is already NULL\n");
    }

}

bool compare_int(int var1, int var2)
{
    int* var1_array = intToListOfDigits(var1);
    int* var2_array = intToListOfDigits(var2);

    int var_1_lenght = sizeOfInteger(var1);
    int var_2_lenght = sizeOfInteger(var2);

    int mini = MIN(var_1_lenght, var_2_lenght);

    bool result = true;
    for(int i = 0; i < mini; i++)
    {
        if(var1_array[i] != var2_array[i])
        {
            result = false;
            break;
        }
    }

    freeIntList(var1_array);
    freeIntList(var2_array);

    return result;
}
