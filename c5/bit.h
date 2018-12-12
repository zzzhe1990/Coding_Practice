#ifndef _BIT_H
#define _BIT_H
#include <iostream>
#include <stack>
using namespace std;

int getBit(int num, int idx);
int setBit(int num, int idx);
int clearBit(int num, int idx);
int updateBit(int num, int idx, bool isBit1);
void printBits(int num, int size);
int len(int num);

#endif
