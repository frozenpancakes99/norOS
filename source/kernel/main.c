#include "print.h"
#include "cursor.h"

void main() {
    clear();
    color(WHITE, BLACK);
    prints("welcome to norOS!");
    nline();
    prints("running norOS kernel v0.0.1");
    nline();
    nline();
    color(YELLOW, BLACK);
    prints("(!) to install norOS, try running ");
    color(LIGHT_BLUE, BLACK);
    prints("installer");
    nline();
    color(LIGHT_RED, BLACK);
    prints("welcome to norOS!");
    nline();
    palette();
    nline();
    color(LIGHT_RED, BLACK);
    prints("root");
    color(WHITE, BLACK);
    prints("@norOS #");
    cupdate(13, 7);
}