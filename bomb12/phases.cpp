/*
 * The bomb phases!
 */

#include <string>
#include <sstream>
#include <stdint.h>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "helperfuncs.h"
#include "bombdriver.h"
#include "hiddenhelpers.h"
 

std::string userid = "riddickws";


void phase_1(std::string linein) {
    
    std::string correctStr = getPhase1String(userid);
    
    if (linein.compare(correctStr) != 0) {
        detonate(1);
    }
    
}


void phase_2(std::string linein) {
    
    std::string one = funFuncOne(linein);
    std::string two = getPhase2String(userid);
    //hint: p/c 0x68 displays 'h' because 0x68 
    //is the ASCII encoding of 'h'
    
    if (one.compare(two) != 0) {
        detonate(2);
    }
    
}

void phase_3(std::string linein) {
    
    int num1, num2, num3;
    std::stringstream ss(linein);
    
    ss >> num1 >> num2 >> num3;
    
    int nums[7];
    int *ptr[3] = {nums + 2};
    int size1 = sizeof(nums);
    int size2 = sizeof(ptr[1]);
    initPhase3Array(size1, size2, nums + 2, nums, 7, userid);
    
    if (num1 != size1 || num2 != size2 || num3 != *ptr[0])
        detonate(3);
    
}

void phase_4(std::string linein) {
    
    std::stringstream ss(linein);
    
    int i, j;
    
    ss >> i >> j;
   
    if (i == j || i == 1 || j == 1)  
        detonate(4);
    int thing = funFuncTwo(i, j);
    int result = getPhase4Result(userid);
    
    if (thing != result || i == result || j == result)
        detonate(4);
    
}

void phase_5(std::string linein) {
    
    std::stringstream ss(linein);
    
    int i, j, k;
    
    ss >> i >> j >> k;
    if (i < 5 || i > 20) detonate(5);
    
    int a[i];
    initPhase5Array(a, i, userid);
        
    if (k != funFuncThree(a, 0, i-1, j))
        detonate(5);
    
}

void phase_6(std::string linein) {
    
    int i;
    std::stringstream ss(linein);
    ss >> i;

    if (i < 10 || i > 20) detonate(6);
    
    int a[i];
    
    for (int j = 0; j < i; j++)
        ss >> a[j];
    
    for (int j = 0; j < i; j++)
    {
        if (a[j] <= 0) 
            detonate(6);
        for (int k = 0; k < j; k++)
           if (a[k] == a[j])
               detonate(6);
    }
    
    struct thing *r = NULL;
    
    r = funFuncFour(r, a[0]);
    for (int j = 1; j < i; j++)
        funFuncFour(r, a[j]);
    
    int result = getPhase6Result(userid);
    if (funFuncFive(r) != result)
        detonate(6);
    
}

