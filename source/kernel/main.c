#include "print.h"
#include "cursor.h"

void main() {
    print_clear();
    print_set_color(WHITE, BLACK);
    print_str("hello");
    print_newline();
    print_set_color(WHITE, BLACK);
    print_str("it works!");
    disable_cursor();
    
}