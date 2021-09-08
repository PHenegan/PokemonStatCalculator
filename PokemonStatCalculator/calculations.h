#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <vector>

std::vector<int> findEV(int stat, int baseStat, int level, int IV, bool isHP = false, double natureMod = 1.0);
std::vector<int> findIV(int stat, int baseStat, int level, int IV, bool isHP = false, double natureMod = 1.0);
std::vector<int> findBaseStat(int stat, int baseStat, int level, int IV, bool isHP = false, double natureMod = 1.0);
#endif // CALCULATIONS_H
