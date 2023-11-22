#ifndef PROG2_NHF_RPSLS_PLAYER_H
#define PROG2_NHF_RPSLS_PLAYER_H

#include "rules.h"
#include <cstring>
#define MAX_NAME_LEN 50
#define MAX_SHAPES_ARRAY 100

class Game;

class Player{
protected:
    char name[MAX_NAME_LEN + 1];
    int points;
public:
    Player() {
        points = 0;
    }

    virtual bool Interactive() {return false;};

    virtual int GetNextShape(Rules &) = 0;

    virtual void OpponentsShape(int s) {}

    virtual void StartGame(Game *g) {}

    char* GetPlayerName() {return name;}

    virtual const char* GetStrategyName() = 0;

    void SetPlayerName(char* n);

    void AddPoints(int p) {points += p;}

    int GetPoints() {return points;}

    virtual ~Player() {}
};

class Human : public Player{
public:
    Human() : Player() {
        strcpy(name, "Human");
    }
    virtual bool Interactive() {return true;};

    virtual int GetNextShape(Rules &);

    virtual const char* GetStrategyName() {return "Human";}

};

class CleverStrat : public Player{
    int myShapes[MAX_SHAPES_ARRAY];
    int mscount;
    int opponentShapes[MAX_SHAPES_ARRAY];
    int oscount;
public:
    CleverStrat() : Player() {
        mscount = 0;
        oscount = 0;
        strcpy(name, "Clever Strategy");
    }

    virtual void StartGame(Game *g) {
        mscount = 0;
        oscount = 0;
    }

    virtual void OpponentsShape(int s);

    virtual int GetNextShape(Rules &);

    virtual const char* GetStrategyName() {return "Clever Strategy";}

};

class CopyStrat : public Player{
    int opponentShape;
public:
    CopyStrat() : Player() {
        strcpy(name, "Copy Strategy");
        opponentShape = 0;
    }

    virtual void StartGame(Game *g) {
        opponentShape = 0;
    }

    virtual void OpponentsShape(int s);

    virtual int GetNextShape(Rules &);

    virtual const char* GetStrategyName() {return "Copy Strategy";}
};

class RandomStrat : public Player{
public:
    RandomStrat() : Player() {
        strcpy(name, "Random Strategy");
    }

    virtual int GetNextShape(Rules &);

    virtual const char* GetStrategyName() {return "Random Strategy";}

};

class PredictiveStrat : public Player{
    int opponentShape;
    int myShape;
    Game *actualGame;
public:
    PredictiveStrat() : Player() {
        strcpy(name, "Predictive Strategy");
        opponentShape = 0;
        myShape = 0;
        actualGame = NULL;
    }

    virtual void StartGame(Game *g) {
        opponentShape = 0;
        actualGame = g;
    }

    virtual void OpponentsShape(int s);

    virtual int GetNextShape(Rules &);

    virtual const char* GetStrategyName() {return "Predictive Strategy";}
};

#endif //PROG2_NHF_RPSLS_PLAYER_H
