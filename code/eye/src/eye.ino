#include <Servo.h>
#include <MaxMatrix.h>

Servo test;

int data = 12;    // DIN pin of MAX7219 module
int load = 10;    // CS pin of MAX7219 module
int clock = 11;  // CLK pin of MAX7219 module
int maxInUse = 1;    //change this variable to set how many MAX7219's you'll use
int brightness = 5;

MaxMatrix m(data, load, clock, maxInUse); // define module

void setup() {
    test.attach(2);
    test.write(90);
    m.init(); // module initialize
    m.setIntensity(brightness); // dot matix intensity 0-15
}

void loop() {
    int blink = 50;
    m.setColumn(0, B01000000);
    m.setColumn(1, B10111100);
    m.setColumn(2, B10111100);
    m.setColumn(3, B00000000);
    m.setColumn(4, B00000000);
    m.setColumn(5, B10111100);
    m.setColumn(6, B10111100);
    m.setColumn(7, B01000000);
    delay(3000);

    m.setColumn(0, B01000000);
    m.setColumn(1, B10011000);
    m.setColumn(2, B10011000);
    m.setColumn(3, B00000000);
    m.setColumn(4, B00000000);
    m.setColumn(5, B10011000);
    m.setColumn(6, B10011000);
    m.setColumn(7, B01000000);
    delay(blink);

    m.setColumn(0, B01000000);
    m.setColumn(1, B10000000);
    m.setColumn(2, B10000000);
    m.setColumn(3, B00000000);
    m.setColumn(4, B00000000);
    m.setColumn(5, B10000000);
    m.setColumn(6, B10000000);
    m.setColumn(7, B01000000);
    delay(blink);

    m.setColumn(0, B01000000);
    m.setColumn(1, B10011000);
    m.setColumn(2, B10011000);
    m.setColumn(3, B00000000);
    m.setColumn(4, B00000000);
    m.setColumn(5, B10011000);
    m.setColumn(6, B10011000);
    m.setColumn(7, B01000000);
    delay(blink);

}
