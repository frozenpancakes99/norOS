#include "print.h"
#include "cursor.h"

void main() {
    print_clear();
    print_set_color(WHITE, BLACK);
    print_str("welcome to norOS!");
    print_newline();
    print_str("running norOS kernel v0.0.1");
    print_newline();
    print_newline();
    print_set_color(YELLOW, BLACK);
    print_str("(!) to install norOS, try running ");
    print_set_color(LIGHT_BLUE, BLACK);
    print_str("installer");
    print_newline();
    print_set_color(LIGHT_RED, BLACK);
    print_str("root");
    print_set_color(WHITE, BLACK);
    print_str("@norOS #");
    cupdate(13, 4);
}