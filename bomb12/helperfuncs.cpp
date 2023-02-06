#include <string>
#include <sstream>
#include <stdint.h>
#include <stdlib.h>
#include "helperfuncs.h"


std::string funFuncOne(std::string input) {
    std::string str = "";
    int val = 0;
    
    for (int i = 0; i < (int)input.length(); i++) {
        val = input[i];
        std::stringstream stream;
        stream << std::hex << val;
        std::string result( stream.str() );
        str += result;
    }
    
    return str;
}


int funFuncTwo(int i, int j) {
    
    int k, l;
    
    if (j == 0) goto z;
d:  k = i / j;
    i = i - k * j;
r1: if (i >= j) { i = i - j; goto r1; }
r2: if (i < 0) { i = i + j; goto r2; }
    k = i;
    i = j;
    j = k;
z:  if (j == 0) l = i; else goto d;
    return l;
    
}

int funFuncThree(int a[], int l, int h, int i) {
    
    if (h >= l) {
        
        int m = l + (h - l) / 2;
        
        if (a[m] == i)
            return a[m];
            
        if (a[m] > i)
            return a[m] + funFuncThree(a, l, m-1, i);
        
        if (a[m] < i)
            return a[m] + funFuncThree(a, m+1, h, i);
        
    }
    return -100;
}

struct thing * newThing(int val) {
    
    struct thing *temp = (struct thing *)malloc(sizeof(struct thing));
    temp->val = val;
    temp->mem1 = NULL;
    temp->mem2 = NULL;
    return temp;
    
}

struct thing * funFuncFour(struct thing *t, int val) {
    
    if (t == NULL)
        return newThing(val);   
    
    if (val < t->val)
        t->mem1 = funFuncFour(t->mem1, val);
    else if (val > t->val)
        t->mem2 = funFuncFour(t->mem2, val);
        
    return t;
    
}

int funFuncFive(struct thing *r) {
    if (r == NULL)
        return 0;
    
    if (r->mem1 != NULL)
        return funFuncFive(r->mem1);
    else
        return r->val;
}


