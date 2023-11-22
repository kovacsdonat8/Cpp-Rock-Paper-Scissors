#ifndef PROG2_NHF_RPSLS_RULES_H
#define PROG2_NHF_RPSLS_RULES_H

class Rules{
public:
    virtual int NumberofShapes() = 0;

    virtual const char* GetShapeName(int i) = 0;

    virtual int Result(int i, int j) = 0;

    virtual const char *GetRuleName() = 0;

    virtual int WhoBeats(int shape) = 0;

    virtual ~Rules() {}
};

enum Shapes{
    Rock = 1,
    Paper,
    Scissors,
    Lizard,
    Spock
};

class RPS : public Rules{
public:
    virtual int NumberofShapes() {return 3;}

    virtual const char* GetShapeName(int i);

    virtual int Result(int i, int j);

    virtual const char *GetRuleName() {return "Rock-Paper-Scissors";}

    virtual int WhoBeats(int shape);

};

class RPSLS : public Rules{
public:
    virtual int NumberofShapes() {return 5;}

    virtual const char* GetShapeName(int i);

    virtual int Result(int i, int j);

    virtual const char *GetRuleName() {return "Rock-Paper-Scissors-Lizard-Spock";}

    virtual int WhoBeats(int shape);

};
#endif //PROG2_NHF_RPSLS_RULES_H
