// https://www.hackerrank.com/challenges/beautiful-string/
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the beautifulStrings function below.
 */
long beautifulStrings(char* s) {
    /*
     * Write your code here.
     */
    int cntString = 0;
    int i = 0;
    int j = 0;
    char **bufString;
    long cntBStr = 0;
    int firstPos = 0;
    int secondPos = 0;
    
    while(s[cntString] != NULL)
        cntString++;
    
    bufString = (char**)malloc(sizeof(char*)*(cntString + 1));
    
    for(i = 0; i < cntString; i++)
    {
        for(j = 1; j < cntString; j++)
        {
            bufString[cntBStr] = (char*)malloc(sizeof(char)*(cntString + 1));
            memset(bufString[cntBStr], 0, sizeof(char)*(cntString +1));
            if(i==0)
            {
                memcpy(&bufString[cntBStr][0], &s[j+1],sizeof(char)*(cntString - 2));
                //memcpy(&bufString[cntBStr][j], &s[j+1],sizeof(char)*(cntString - 2));
                //memcpy(&bufString[cntBStr][j], &s[j+1],sizeof(char)*(cntString - 2));
            }
            else
            {
                memcpy(&bufString[cntBStr][0], &s[0],sizeof(char)*i);
                memcpy(&bufString[cntBStr][i], &s[j+1],sizeof(char)*(cntString - 2));
                memcpy(&bufString[cntBStr][j], &s[j+1],sizeof(char)*(cntString - 2));
            }
            memcpy(&bufString[cntBStr][0], &s[j],sizeof(char)*(cntString - 2));
            memcpy(&bufString[cntBStr][j], &s[j+1],sizeof(char)*(cntString - 2));
            memcpy(&bufString[cntBStr][j], &s[j+1],sizeof(char)*(cntString - 2));
        }
    }
    
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    long result = beautifulStrings(s);

    fprintf(fptr, "%ld\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
