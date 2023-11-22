#include "player.h"
#include "game.h"
#include <iostream>
#include <cstring>

//PLAYER
void Player::SetPlayerName(char* n) {
    if (strlen(n) > MAX_NAME_LEN){
        strncpy(name, n, MAX_NAME_LEN);
        name[MAX_NAME_LEN] = '\0';
    }
    else{
        strcpy(name, n);
    }
}

//HUMAN
int Human::GetNextShape(Rules &r){
    int shape;
    bool validshape = false;
    while (!validshape){
        std::cout << "Enter your shape (0 = Main Menu, ";
        for (int i = 1; i <= r.NumberofShapes(); i++) {
            std::cout << i << " = " << r.GetShapeName(i);
            if (i < r.NumberofShapes()) {
                std::cout << ", ";
            }
        }
        std::cout << "): ";
        std::cin >> shape;
        if(shape == 0){
            return 0;
        }

        if (shape >= 1 && shape <= r.NumberofShapes()){
            validshape = true;
        }
        else{
            std::cout << "Invalid input!" << std::endl;
        }
    }
    return shape;
}


//CLEVER STRATEGY
int CleverStrat::GetNextShape(Rules &r) {
    int actualShape;
    if (mscount == 0){
        actualShape = rand() % r.NumberofShapes() + 1;
        myShapes[mscount] = actualShape;
        mscount++;
        return actualShape;
    }
    int frequency[r.NumberofShapes()];
    memset(frequency, 0, sizeof(frequency));
    for (int i = 0; i < oscount; i++){
        frequency[opponentShapes[i] - 1]++;
    }
    int freqMax = -1;
    int freqShape = -1;
    for (int i = 0; i < r.NumberofShapes(); i++) {
        if (frequency[i] > freqMax) {
            freqMax = frequency[i];
            freqShape = i + 1;
        }
    }
    return freqShape;
}

void CleverStrat::OpponentsShape(int s){
    opponentShapes[oscount] = s;
    oscount++;
}


//COPY STRATEGY
int CopyStrat::GetNextShape(Rules &r){
    if(opponentShape == 0){
        return rand() % r.NumberofShapes() + 1;
    }
    return opponentShape;
}

void CopyStrat::OpponentsShape(int s){
    opponentShape = s;
}

//RANDOM STRATEGY
int RandomStrat::GetNextShape(Rules &r){
    return rand() % r.NumberofShapes() + 1;
}

//PREDICTIVE STRATEGY
void PredictiveStrat::OpponentsShape(int s) {
    opponentShape = s;
}

int PredictiveStrat::GetNextShape(Rules &r){
    if(opponentShape == 0 || actualGame->GetActualRule().Result(myShape, opponentShape) == 0){
        return rand() % r.NumberofShapes() + 1;
    }
    else if(actualGame->GetActualRule().Result(myShape, opponentShape) == 1){
        return opponentShape;
    }
    else {
        return actualGame->GetActualRule().WhoBeats(opponentShape);
    }
}

