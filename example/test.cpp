/** 
 * build
 * g++ test.cpp -o test -L../lib/ -I../ -lEscPospp -lusb-1.0
 * 
 * lsusb
 * Bus 020 Device 008: ID 1fc9:2014 NXP Semiconductors Printer-80 
*/

#include <iostream>
#include "escpospp/escpospp.h"

int main(){
    try{
        Printer::initializePrinter(std::pair<int,int>(0x1fc9, 0x2014));
        Printer &printer = Printer::getPrinter();
        printer.text("This is a **sample** text!\n");
        printer.cut();
    } catch (int e){
        //There was an error
    }
    return 0;
}