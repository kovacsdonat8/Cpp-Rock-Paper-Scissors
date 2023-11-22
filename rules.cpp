#include "rules.h"
#include <iostream>

//Rock-Paper-Scissors
const char* RPS::GetShapeName(int i) {
    switch (i) {
        case Rock:
            return "Rock";
        case Paper:
            return "Paper";
        case Scissors:
            return "Scissors";
        default:
            return "Undefined";
    }
}

int RPS::Result(int i, int j){
    static int rtable[3][3] = {
    { 0,-1, 1} ,
    { 1, 0,-1} ,
    {-1, 1, 0}
    };
    return rtable[i - 1][j - 1];
}

int RPS::WhoBeats(int shape){
    switch (shape){
        case Rock:
            return Paper;
        case Paper:
            return Scissors;
        case Scissors:
        default:
            return Rock;
    }
}

//Rock-Paper-Scissors-Lizard-Spock
const char* RPSLS::GetShapeName(int i) {
    switch (i) {
        case Rock:
            return "Rock";
        case Paper:
            return "Paper";
        case Scissors:
            return "Scissors";
        case Lizard:
            return "Lizard";
        case Spock:
            return "Spock";
        default:
            return "Undefined";
    }
}

int RPSLS::Result(int i, int j){
    static int rtable[5][5] = {
    { 0,-1, 1, 1,-1} ,
    { 1, 0,-1,-1, 1} ,
    {-1, 1, 0, 1,-1} ,
    {-1, 1,-1, 0, 1} ,
    { 1,-1, 1,-1, 0}
    };
    return rtable[i - 1][j - 1];
}


int RPSLS::WhoBeats(int shape) {
    int beaters[2];
    switch (shape) {
        case Rock:
            beaters[0] = Paper;
            beaters[1] = Spock;
            return beaters[rand() % 2];
        case Paper:
            beaters[0] = Scissors;
            beaters[1] = Lizard;
            return beaters[rand() % 2];
        case Scissors:
            beaters[0] = Rock;
            beaters[1] = Spock;
            return beaters[rand() % 2];
        case Lizard:
            beaters[0] = Rock;
            beaters[1] = Scissors;
            return beaters[rand() % 2];
        case Spock:
        default:
            beaters[0] = Paper;
            beaters[1] = Lizard;
            return beaters[rand() % 2];
    }
}