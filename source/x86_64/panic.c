#include "panic.h"

void panic(char* reason) {
    newline();
    print("kernel panic! ");
    print(reason);
    disablecursor();
}