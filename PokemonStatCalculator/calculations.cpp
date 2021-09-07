#include <vector>

using namespace std;

/**
 * @brief findEV - calculates the minimum and maximum EV stat of a Pokemon when given required parameters
 * @param stat - Final Stat of the target Pokemon
 * @param baseStat - Base Stat of the target Pokemon's species
 * @param level - Level value of the target Pokemon
 * @param IV - IV value of the target Pokemon
 * @param isHP - whether or not the calculations should be done for the HP stat (assumed false if no value is given)
 * @param natureMod - Nature modifier (+ is 1.1, - is 0.9, assumed 1 if no value is given)
 * @return a vector containing the minimum and maximum EV values in that order
 */
vector<int> findEV(int stat, int baseStat, int level, int IV, bool isHP = false, double natureMod = 1.0) {
    //HP FORMULA = int((2*Base + IV + int(EV/4)) * Level/100 + Level + 10)
    //OTHER STAT ORMULA = int( (int( (2*Base + IV + int(EV/4) * Level/100) ) + 5) * Nature )

    int temp;
    vector<int> results;

    //Prevents divide by 0 error
    level = level == 0 ? 1 : level;
    natureMod = natureMod == 0 ? 1.0 : natureMod;


    double minEV = static_cast<double>(stat) / natureMod;
    double maxEV = static_cast<double>(stat + 1) / natureMod - 1;


    if(isHP)
        temp = 10 + level;
    else
        temp = 5;

    minEV -= temp;
    maxEV -= temp;

   minEV = minEV * 100 / level;
   maxEV = maxEV * 101 / level - 1;

   temp = 2*baseStat + IV;
   minEV -= temp;
   maxEV -= temp;

   minEV *= 4;
   maxEV = maxEV * 4 + 3;

   results.push_back(static_cast<int>(minEV));
   results.push_back(static_cast<int>(maxEV));

   return results;
}

/**
 * @brief findIV - calculates the minimum and maximum IV stat of a Pokemon when given required parameters
 * @param stat - Final Stat of the target Pokemon
 * @param baseStat - Base Stat of the target Pokemon's species
 * @param level - Level value of the target Pokemon
 * @param EV - EV value of the target Pokemon
 * @param isHP - whether or not the calculations should be done for the HP stat (assumed false if no value is given)
 * @param natureMod - Nature modifier (+ is 1.1, - is 0.9, assumed 1 if no value is given)
 * @return a vector containing the minimum and maximum IV values in that order
 */
vector<int> findIV(int stat, int baseStat, int level, int EV, bool isHP = false, double natureMod = 1.0) {
    //HP FORMULA = int((2*Base + IV + int(EV/4)) * Level/100 + Level + 10)
    //OTHER STAT ORMULA = int( (int( (2*Base + IV + int(EV/4) * Level/100) ) + 5) * Nature )

    int temp;
    vector<int> results;

    //Prevents divide by 0 error
    level = level == 0 ? 1 : level;
    natureMod = natureMod == 0 ? 1.0 : natureMod;


    double minIV = static_cast<double>(stat) / natureMod;
    double maxIV = static_cast<double>(stat + 1) / natureMod - 1;


    if(isHP)
        temp = 10 + level;
    else
        temp = 5;

    minIV -= temp;
    maxIV -= temp;

   minIV = minIV * 100 / level;
   maxIV = maxIV * 101 / level - 1;

   temp = 2*baseStat + EV/4;
   minIV -= temp;
   maxIV -= temp;

   results.push_back(static_cast<int>(minIV));
   results.push_back(static_cast<int>(maxIV));

   return results;
}

/**
* @brief findStat - calculates the minimum and maximum base stat of a Pokemon when given required parameters
* @param stat - Final Stat of the target Pokemon
* @param level - Level value of the target Pokemon
* @param EV - EV value of the target Pokemon
* @param IV - IV value of the target Pokemon
* @param isHP - whether or not the calculations should be done for the HP stat (assumed false if no value is given)
* @param natureMod - Nature modifier (+ is 1.1, - is 0.9, assumed 1 if no value is given)
* @return a vector containing the minimum and maximum IV values in that order
*/
vector<int> findBaseStat(int stat, int level, int EV, int IV, bool isHP = false, double natureMod = 1.0) {
    //HP FORMULA = int((2*Base + IV + int(EV/4)) * Level/100 + Level + 10)
    //OTHER STAT ORMULA = int( (int( (2*Base + IV + int(EV/4) * Level/100) ) + 5) * Nature )

    int temp;
    vector<int> results;

    //Prevents divide by 0 error
    level = level == 0 ? 1 : level;
    natureMod = natureMod == 0 ? 1.0 : natureMod;


    double minStat = static_cast<double>(stat) / natureMod;
    double maxStat = static_cast<double>(stat + 1) / natureMod - 1;


    if(isHP)
        temp = 10 + level;
    else
        temp = 5;

    minStat -= temp;
    maxStat -= temp;

   minStat = minStat * 100 / level;
   maxStat = maxStat * 101 / level - 1;

   temp = IV + EV/4;
   minStat -= temp;
   maxStat -= temp;

   minStat /= 2;
   maxStat /= 2;

   results.push_back(static_cast<int>(minStat));
   results.push_back(static_cast<int>(maxStat));

   return results;
}

