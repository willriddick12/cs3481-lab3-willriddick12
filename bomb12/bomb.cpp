
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "bombdriver.h"
#include "phases.h"


FILE *input;
extern std::string userid;
void displayGDBHint();

int main(int argc, char * argv[]) {
    
    std::string linein;
    
    /* 
     * Determine whether to read input from stdin
     * or from an input file.
     */
    if (argc == 1) {
        input = stdin;
    }
    else if (argc == 2) {
        if (!(input = fopen(argv[1], "r"))) {
            printf("Couldn't open %s file.\n", argv[1]);
            printf("Reading instead from stdin.\n\n");
            input = stdin;
        }
    }
    else {
        printf("Usage: %s may be called with no args (input entered manually)", argv[0]);
        printf("or with one arg (input entered via a text file).");
    }
    
    // No sneaky business. :(
    validate();
    
    displayGDBHint();

    printf("This gdb bomb belongs to %s.\n", userid.c_str());
    printf("The bomb is live. You'd better be careful...\n");

    
    // Phase one.
    linein = read_line();
    phase_1(linein);
    defuse(1, linein);
    printf("One down.\n");
    
    // Phase two.
    linein = read_line();
    phase_2(linein);
    defuse(2, linein);
    printf("Two down.\n");
    
    // Phase three.
    linein = read_line();
    phase_3(linein);
    defuse(3, linein);
    printf("Three down.\n");
    
    // Phase four.
    linein = read_line();
    phase_4(linein);
    defuse(4, linein);
    printf("Four down.\n");
    
    // Phase five.
    linein = read_line();
    phase_5(linein);
    defuse(5, linein);
    printf("Five down.\n");
    
    // Phase six.
    linein = read_line();
    phase_6(linein);
    defuse(6, linein);
    printf("Six down.\n");
    printf("Congratulations!  You have defused the gdb bomb!\n"); 
    return 0;
    
}

#define HINTCT 20
const char * hints[HINTCT] =
{
"To display the variable num in hex type: p/x num",
"You can't start stepping through instructions without typing r (for run) first.",
"You can load the executable into gdb by typing: file <executable>",
"To set a breakpoint at the beginning of a C function type: b <function>",
"To set a breakpoint at the beginning of a C++ method type: b <classname>::<method>",
"To set a breakpoint at a particular line number type: b <lineNo>",
"To display the value of a variable type: p <varName>",
"To display the value of a variable every type a breakpoint is reached type: display <varName>",
"To continue execution to the end of the current function type: finish",
"To see the list of functions called to get to current instruction type: where",
"To execute an function in its entirety without stepping into it type: n",
"To execute the next statement type: s", 
"To go up a stack frame to the calling function type: up",
"To delete all breakpoints type: d",
"To set a breakpoint at line <n> in file <fileName>, type: b <fileName>:<n>",
"To continue execution to the next breakpoint type: c",
"To get information about the breakpoints type: info breakpoints",
"To display the arguments of the current function type: info args",
"To get gdb to run the program passing it command line arguments type: r <command line args>",
"To exit gdb type: quit",
};

void displayGDBHint()
{
   srand (time(NULL));
   int hintNo = rand() % HINTCT;
   printf("\nGDB Tip:\n");
   printf("%s\n\n", hints[hintNo]);
}
