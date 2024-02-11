
#include "../Header/Day2.h"


void GameMaster(void) //Entrance
{
    CubesSet GameRules = CreateGameRules();
    
    char Buffer[BUFFER_SIZE];
    FILE *f1 = fopen(FILENAME, "r");
    if(!f1) return;
    
    int GameID = 0;
    int PossibleGameIDSum = 0;
    while((fgets(Buffer, BUFFER_SIZE, f1))!= NULL)
    {
        if(sscanf(Buffer, "%*s%d", &GameID))
        {
            bool IsPossible = OneGame(Buffer, &GameRules);
            if(IsPossible)
            {
                PossibleGameIDSum += GameID;
            }
            
        }
    }
    fclose(f1);
    printf("%d \n", PossibleGameIDSum);
}


CubesSet CreateGameRules(void)
{
    CubesSet Set = {12, 13, 14};
    return Set;
}


bool OneGame(const char * const String, const CubesSet* const GameRules)
{
    CubesSet MaxSetCubes = GetMaxSetCubesFromOneGame(String);
    return СheckRules(GameRules, &MaxSetCubes);
}


CubesSet GetMaxSetCubesFromOneGame(const char * const String)
{

    CubesSet CurrentMaxSet = {0, 0, 0};
    CubesSet CurrentSet = {0, 0, 0};
    
    char OneGameString[BUFFER_SIZE];
    char* OneGameStrPtr = strcpy(OneGameString, String);
    
    char* Delimiter = ":";
    OneGameStrPtr = strtok(OneGameStrPtr, Delimiter);
    OneGameStrPtr = strtok(NULL, Delimiter);
    
    Delimiter = ";";
    for(OneGameStrPtr = strtok(OneGameStrPtr, Delimiter); OneGameStrPtr; OneGameStrPtr = strtok(NULL, Delimiter))
    {
        CurrentSet = GetOneAttemptSetCubes(OneGameStrPtr);
        SetMaxValue(&CurrentMaxSet, &CurrentSet);
        
    }
    return CurrentMaxSet;
}

CubesSet GetOneAttemptSetCubes(char * String)
{
    CubesSet CurrentSet = {0, 0, 0};
    int ColorsNum[] = {0,0,0};
    char ColorsName[COLORS_NUMBER][MAX_LEN_NAME_COLOR] = {0};
    
    if(sscanf(String, "%d %s %d %s %d %s", &ColorsNum[0], &ColorsName[0], &ColorsNum[1], &ColorsName[1], &ColorsNum[2], &ColorsName[2]))
    {
        InitOneAttemptSetCubes(ColorsNum, ColorsName, &CurrentSet);
    }
    return CurrentSet;
}


void InitOneAttemptSetCubes(int ColorsNum[COLORS_NUMBER], char ColorsName[COLORS_NUMBER][MAX_LEN_NAME_COLOR], CubesSet* CurrentSet)
{
    for(int i = 0;  i < COLORS_NUMBER; i++)
    {
        if(strstr(ColorsName[i], "blue"))
        {
            CurrentSet->BlueCubes = ColorsNum[i];
        }
        else if (strstr(ColorsName[i], "green"))
        {
            CurrentSet->GreenCubes = ColorsNum[i];
        }
        else if(strstr(ColorsName[i], "red"))
        {
            CurrentSet->RedCubes = ColorsNum[i];
        }
    }
}




void SetMaxValue(CubesSet* SetForMaxValue, const CubesSet* CubesSet)
{
    SetForMaxValue->RedCubes = SetForMaxValue->RedCubes > CubesSet->RedCubes ?  SetForMaxValue->RedCubes :  CubesSet->RedCubes;
    SetForMaxValue->BlueCubes = SetForMaxValue->BlueCubes > CubesSet->BlueCubes ?  SetForMaxValue->BlueCubes :  CubesSet->BlueCubes;
    SetForMaxValue->GreenCubes = SetForMaxValue->GreenCubes > CubesSet->GreenCubes ?  SetForMaxValue->GreenCubes :  CubesSet->GreenCubes;
}



bool СheckRules(const CubesSet* const GameRules, const CubesSet* const SetCubes) // return false whet set is wrong
{
    if (GameRules->RedCubes < SetCubes->RedCubes ||
        GameRules->BlueCubes < SetCubes->BlueCubes ||
        GameRules->GreenCubes < SetCubes->GreenCubes)
    {
        return false;
    }
    else
    {
        return true;
    }
}


