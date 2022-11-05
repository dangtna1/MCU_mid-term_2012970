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
        case 7:
            result[0] = strNumberAfterProcessing[0];
            result[1] = '.';
            int indexOfResult7 = 2;
            int indexOfStr7 = 1;
            for (indexOfStr7; indexOfStr7<countOfDouble; indexOfStr7++) {
                if (strNumberAfterProcessing[indexOfStr7] != '.') {
                    result[indexOfResult7] =  strNumberAfterProcessing[indexOfStr7];
                    indexOfResult7++;
                }
            }
            result[indexOfResult7] = ' ';
            result[indexOfResult7+1] = 'M';
            result[indexOfResult7+2] = 'e';
            result[indexOfResult7+3] = 'g';
            result[indexOfResult7+4] = 'a';
            result[indexOfResult7+5] = '\0';
        break;
        case 8:
            result[0] = strNumberAfterProcessing[0];
            result[1] = strNumberAfterProcessing[1];
            result[2] = '.';
            int indexOfResult8 = 3;
            int indexOfStr8 = 2;
            for (indexOfStr8; indexOfStr8<countOfDouble; indexOfStr8++) {
                if (strNumberAfterProcessing[indexOfStr8] != '.') {
                    result[indexOfResult8] =  strNumberAfterProcessing[indexOfStr8];
                    indexOfResult8++;
                }
            }
            result[indexOfResult8] = ' ';
            result[indexOfResult8+1] = 'M';
            result[indexOfResult8+2] = 'e';
            result[indexOfResult8+3] = 'g';
            result[indexOfResult8+4] = 'a';
            result[indexOfResult8+5] = '\0';
        break;
        case 9:
            result[0] = strNumberAfterProcessing[0];
            result[1] = strNumberAfterProcessing[1];
            result[2] = strNumberAfterProcessing[2];
            result[3] = '.';
            int indexOfResult9 = 4;
            int indexOfStr9 = 3;
            for (indexOfStr9; indexOfStr9<countOfDouble; indexOfStr9++) {
                if (strNumberAfterProcessing[indexOfStr9] != '.') {
                    result[indexOfResult9] =  strNumberAfterProcessing[indexOfStr9];
                    indexOfResult9++;
                }
            }
            result[indexOfResult9] = ' ';
            result[indexOfResult9+1] = 'M';
            result[indexOfResult9+2] = 'e';
            result[indexOfResult9+3] = 'g';
            result[indexOfResult9+4] = 'a';
            result[indexOfResult9+5] = '\0';
        break;
        default: 
            printf("\n%s\n", "The number you input is not valid for the type 'double'. Maybe it can be too long or something!");
        break;
    }
    return result;
}
int main()
{
    //do not change
    printf("\n%s", suffixWithUnit(0));
    printf("\n%s", suffixWithUnit(0.5));
    printf("\n%s", suffixWithUnit(1));
    printf("\n%s", suffixWithUnit(1.2345670));
    printf("\n%s", suffixWithUnit(10));
    printf("\n%s", suffixWithUnit(12.34567));
    printf("\n%s", suffixWithUnit(123));
    printf("\n%s", suffixWithUnit(123.4567));

    //change into Kilo
    printf("\n%s", suffixWithUnit(1234));
    printf("\n%s", suffixWithUnit(1234.00));
    printf("\n%s", suffixWithUnit(12345));
    printf("\n%s", suffixWithUnit(12345.98706));
    printf("\n%s", suffixWithUnit(123456));
    printf("\n%s", suffixWithUnit(123456.1230));

    //change into Mega
    printf("\n%s", suffixWithUnit(9876543));
    printf("\n%s", suffixWithUnit(9876543.0123));
    printf("\n%s", suffixWithUnit(98765432));
    printf("\n%s", suffixWithUnit(98765432.1230));
    printf("\n%s", suffixWithUnit(987654321));
    printf("\n%s", suffixWithUnit(987654321.9));

    //test negative number
    printf("\n%s", suffixWithUnit(-9876543));
    printf("\n%s", suffixWithUnit(-9876543.0123));
    printf("\n%s", suffixWithUnit(-98765432));
    printf("\n%s", suffixWithUnit(-98765432.1230));

    //test exception:
    printf("\n%s", suffixWithUnit(-98765432123.1230));
    return 0;
}