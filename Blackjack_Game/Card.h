#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card {
private:
    string suit;
    string rank;
    int value;

public:
    Card(string s, string r, int v) : suit(s), rank(r), value(v) {}
    
    int getValue() const { return value; }
    string getRank() const { return rank; }
    
    void display() const { 
        cout << "[" << suit << rank << "] "; 
    }
};
#endif
