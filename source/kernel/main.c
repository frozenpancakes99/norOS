char* version = "1.0 x86_64\n";
char* currentuser = "root";

#include "print.h"
#include "panic.h"

void main() {
    print("norOS kernel");
    print(version);
    color(YELLOW, BLACK);
    print("new login at ");
    print(currentuser);
    color(WHITE, BLACK);
    newline();
    print("# ");
    cursorlocation();
}