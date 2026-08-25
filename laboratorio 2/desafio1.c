#include <stdio.h>

struct packet{
    char mystring;
    int  myNumber;
    short myshort;
    double  myDouble;
};


int main(void){
    struct packet packet;

    packet.mystring = "B";
    packet.myNumber = 24;
    packet.myshort = packet.myNumber;
    packet.myDouble= packet.myNumber;
    

    
}