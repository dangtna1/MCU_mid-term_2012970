#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
char* suffixWithUnit ( double number ) {
    char *strNumber = (char*)malloc ( 100 * sizeof (char));
    char *strNumberAfterProcessing = (char*)malloc ( 100 * sizeof (char));
    char *result = (char*)malloc ( 100 * sizeof (char));
    //start processing the strNumber: erase the 0s which do not necessary after the comma
    snprintf(strNumber, 100, "%f", number); //convert double to string
    int count = 0;
    int indexOfComma = 0;
    int index = 0;
    while (strNumber[index] != '\0') {
        if (strNumber[index] == '.') indexOfComma = index;
        count++;
        index++;
    }
    int indexOfStart0 = indexOfComma + 1;

    //find index of the first 0 after the comma to erase (becasuse erasing this 0 and 0s after that do not affect the number)
    for (int m = indexOfComma+1; m < count; m++) { //xem coi ddko
        if (strNumber[m] != '0') indexOfStart0 = m+1;
    }
    int n = 0;
    for (n; n < indexOfStart0; n++) {
        strNumberAfterProcessing[n] = strNumber[n]; 
    }
    // printf("%d", indexOfStart0);
    strNumberAfterProcessing[n] = '\0';
    if (indexOfStart0 == indexOfComma+1) strNumberAfterProcessing[n-1] = '\0'; //erase '.' in case the number is integer 

    // printf("%c", strNumber[count-1]);

    //update cound after processing
    count = indexOfComma;
    // printf("%d", count);
    index = 0;
    int countOfDouble = 0;
    while (strNumberAfterProcessing[index] != '\0') {
        countOfDouble++;
        index++;
    }
    // printf("%d", countOfDouble);
    switch(count) {
        case 0:
        case 1:
        case 2:
        case 3:
            result = strNumberAfterProcessing;
        break;
        case 4:
            result[0] = strNumberAfterProcessing[0];
            result[1] = '.';
            int indexOfResult4 = 2;
            int indexOfStr4 = 1;
            for (indexOfStr4; indexOfStr4<countOfDouble; indexOfStr4++) {
                if (strNumberAfterProcessing[indexOfStr4] != '.') {
                    result[indexOfResult4] =  strNumberAfterProcessing[indexOfStr4];
                    indexOfResult4++;
                }
            }
            result[indexOfResult4] = ' ';
            result[indexOfResult4+1] = 'K';
            result[indexOfResult4+2] = 'i';
            result[indexOfResult4+3] = 'l';
            result[indexOfResult4+4] = 'o';
            result[indexOfResult4+5] = '\0';
        break;
        case 5:
            result[0] = strNumberAfterProcessing[0];
            result[1] = strNumberAfterProcessing[1];
            result[2] = '.';
            int indexOfResult5 = 3;
            int indexOfStr5 = 2;
            for (indexOfStr5; indexOfStr5<countOfDouble; indexOfStr5++) {
                if (strNumberAfterProcessing[indexOfStr5] != '.') {
                    result[indexOfResult5] =  strNumberAfterProcessing[indexOfStr5];
                    indexOfResult5++;
                }
            }
            result[indexOfResult5] = ' ';
            result[indexOfResult5+1] = 'K';
            result[indexOfResult5+2] = 'i';
            result[indexOfResult5+3] = 'l';
            result[indexOfResult5+4] = 'o';
            result[indexOfResult5+5] = '\0';
        break;
        case 6:
            result[0] = strNumberAfterProcessing[0];
            result[1] = strNumberAfterProcessing[1];
            result[2] = strNumberAfterProcessing[2];
            result[3] = '.';
            int indexOfResult6 = 4;
            int indexOfStr6 = 3;
            for (indexOfStr6; indexOfStr6<countOfDouble; indexOfStr6++) {
                if (strNumberAfterProcessing[indexOfStr6] != '.') {
                    result[indexOfResult6] =  strNumberAfterProcessing[indexOfStr6];
                    indexOfResult6++;
                }
            }
            result[indexOfResult6] = ' ';
            result[indexOfResult6+1] = 'K';
            result[indexOfResult6+2] = 'i';
            result[indexOfResult6+3] = 'l';
            result[indexOfResult6+4] = 'o';
            result[indexOfResult6+5] = '\0';
        break;
    }
    return result;
}
int main()
{
    printf("\n%s", suffixWithUnit(1.2345670));
    printf("\n%s", suffixWithUnit(12.34567));
    printf("\n%s", suffixWithUnit(123.4567));
    printf("\n%s", suffixWithUnit(123000));
    printf("\n%s", suffixWithUnit(1234));
    printf("\n%s", suffixWithUnit(12345));
    printf("\n%s", suffixWithUnit(1123.23239));
    printf("\n%s", suffixWithUnit(123456));
    return 0;
}