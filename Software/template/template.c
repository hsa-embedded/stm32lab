#include "template.h"

int main(void){

    uart_debug_init();

    while(1)
        uart_debug_putString("TEMPLATE\r\n");

   

}



/*
vim: et sw=4 ts=4
*/
