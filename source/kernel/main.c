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
    print_str("(!) you've got a new notification! run mail to check all notifications");
    print_newline();
    print_set_color(LIGHT_GREEN, BLACK);
    print_str("root$ >");
    cupdate(7, 4);
}