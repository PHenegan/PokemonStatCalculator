import math
def findEVs(stat, baseStat, level, IV, isHP = False, natureMod = 1):
    MAX = 252
    #HP FORMULA = int((2*Base + IV + int(EV/4)) * Level/100 + Level + 10)
    #OTHER FORMULA = int( (int( (2*Base + IV + int(EV/4) * Level/100) ) + 5) * Nature )
    
    minEV = stat / natureMod
    maxEV = (stat + 1) / natureMod - 1

    if (isHP):
        minEV -= (10 + level)
        maxEV -= (10 + level)
    else:
        minEV -= 5
        maxEV -= 5

    minEV = minEV * 100 / level
    maxEV = maxEV * 101 / level - 1
    
    minEV -= (2*baseStat + IV)
    maxEV -= (2*baseStat + IV)


    minEV = round(minEV * 4)
    maxEV = round(maxEV * 4 + 3)

    if (minEV > MAX):
        minEV = MAX
        maxEV = MAX
    elif(maxEV > MAX):
        maxEV = MAX
    
    print("minimum EV value:", minEV, "\tmaximum EV value:", maxEV)
    
def findIVs(stat, baseStat, level, EV, isHP = False, natureMod = 1):
    MAX = 31
    #HP FORMULA = int((2*Base + IV + int(EV/4)) * Level/100 + Level + 10)
    #OTHER FORMULA = int( (int( (2*Base + IV + int(EV/4) * Level/100) ) + 5) * Nature )

    minIV = stat / natureMod
    maxIV = (stat + 1) / natureMod - 1

    if (isHP):
        minIV -= (10 + level)
        maxIV -= (10 + level)
    else:
        minIV -= 5
        maxIV -= 5

    minIV = minIV * 100 / level
    maxIV = maxIV * 101 / level - 1
    
    minIV -= (2*baseStat + EV//4)
    maxIV -= (2*baseStat + EV//4)

    minIV = round(minIV)
    maxIV = round(maxIV)

    if (minIV > MAX):
        minIV = MAX
        maxIV = MAX
    elif(maxIV > MAX):
        maxIV = MAX
    
    print("minimum IV value:", minIV, "\tmaximum IV value:", maxIV)
    


#Examples with a Garchomp taken from Bulbapedia
findEVs(289,108,78,24,True)
findEVs(278,130,78,12,False,1.1)
findEVs(171,102,78,5,False)

#findIVs(141,90,53,252,False,1.1)
findIVs(85,70,53,)

