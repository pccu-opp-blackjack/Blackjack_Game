#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

class Card {
private:
    std::string suit;
    std::string rank;
    int value;

public:
    Card(std::string s, std::string r, int v) : suit(s), rank(r), value(v) {}
    
    int getValue() const { return value; }
    std::string getRank() const { return rank; }
    
    void display() const { 
        std::cout << "[" << suit << rank << "] "; 
    }
};
#endif