
#ifndef Day2_h
#define Day2_h

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//The solution for day 2 "advent of code"
//The task can be viewed at this link https://adventofcode.com/2023/day/2

static const char* FILENAME = "InputData/Day2Input.txt";
static const int BUFFER_SIZE = 512;
static const int COLORS_NUMBER = 3;
static const int MAX_LEN_NAME_COLOR = 7; 
typedef struct CubesSet
{
    int RedCubes;
    int GreenCubes;
    int BlueCubes;
} CubesSet;


void GameMaster(void); //Entrance
bool OneGame(const char * const String, const CubesSet* const GameRules);


CubesSet CreateGameRules(void);
bool СheckRules(const CubesSet* const GameRules, const CubesSet* const SetCubes);

void SetMaxValue(CubesSet* SetForMaxValue, const CubesSet* CubesSet);
CubesSet GetMaxSetCubesFromOneGame(const char * const String);

void InitOneAttemptSetCubes(int ColorsCount[3], char ColorsName[3][7], CubesSet* CurrentSet);
CubesSet GetOneAttemptSetCubes(char * String);



#endif /* Day2_h */
