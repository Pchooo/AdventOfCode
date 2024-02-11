
#include "../Header/Day1.h"


int GetSumCalibrationValue(void)
{
    int Sum = 0;
    int CalibrationNumber = 0;
    bool IsNotEOF = true;
    
    while (IsNotEOF){
        IsNotEOF = GetTwoDigitNumFromString(&CalibrationNumber);
        Sum += CalibrationNumber;
    }
    
    return Sum;
}


bool GetTwoDigitNumFromString(int* TwoDigitNum) // return false when EOF
{
    char Tmp;
    int FirstDigit = -1;
    int LastDigit = -1;
    *TwoDigitNum = 0;
    
    while ((Tmp = getchar()) != EOF)
    {
        if(Tmp == '\n')
        {
            return true;
        }
        else
        {
            if(isdigit(Tmp)){
                if(FirstDigit == -1)
                {
                    FirstDigit = atoi(&Tmp);
                    
                }
                else
                {
                    LastDigit = atoi(&Tmp);
                    *TwoDigitNum = FirstDigit * 10 + LastDigit;
                }
              
            }
      }
    }
    return false;
}



