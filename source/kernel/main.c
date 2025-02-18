#include "print.h"
#include "cursor.h"

void main() {
    print_clear();
    print_set_color(YELLOW, BLACK);
    print_str("welcome to norOS!");
    print_newline();
    print_set_color(WHITE, BLACK);
    print_str("running norOS kernel v0.0.1");
    cupdate(27, 1);
}