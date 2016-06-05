// #include <Arduino.h>
#include <Servo.h>
#include "octosnake.h"
#include "minikame.h"
#include "MaxMatrix.h"

MiniKame robot;
bool running=0;

int data = 12;    // DIN pin of MAX7219 module
int load = 10;    // CS pin of MAX7219 module
int clock = 11;  // CLK pin of MAX7219 module
int maxInUse = 1;    //change this variable to set how many MAX7219's you'll use
int brightness = 5;

MaxMatrix m(data, load, clock, maxInUse); // define module

void setup() {
    Serial.begin(19200);
    delay(1000);
    robot.init();

    m.init(); // module initialize
    m.setIntensity(brightness); // dot matix intensity 0-15
}

void parseData(char data){

    //switch (data.substring(0,plusIndex).toInt()){
    switch (data){

        case 'w':
            robot.walk(1,550);
            running = 1;
            break;

        case 'a':
            robot.turnL(1,550);
            running = 1;
            break;

        case 'd':
            robot.turnR(1,550);
            running = 1;
            break;

        case 's':
            //STOP
            running = 0;
            break;

        case '1': //heart
            robot.pushUp(2,1400);
            break;

        case '2': //fire
            robot.upDown(4,250);
            break;

        case '3': //skull
            robot.jump();
            break;

        case '4': //cross
            robot.hello();
            break;

        case '5': //punch
        //robot.moonwalkL(4,2000);
        robot.frontBack(4,200);
            break;

        case '6': //mask
            robot.dance(2,1000);
            break;

        default:
            robot.home();
            break;
    }
}

char input;

void loop() {
    if (running){
        Serial.println("running");
        if (Serial.available()) {
            input = Serial.read();
            delay(10);
            parseData(input);
        }
        else {
            Serial.println("Keep Moving");
            parseData(input);
        }
    }
    else{
        Serial.println("Normal mode");
        delay(100);
        if (Serial.available()) {
            input = Serial.read();
            delay(10);
            parseData(input);
            Serial.println(input);
        }
        else robot.home();
    }

    // int blink = 50;
    // m.setColumn(0, B01000000);
    // m.setColumn(1, B10111100);
    // m.setColumn(2, B10111100);
    // m.setColumn(3, B00000000);
    // m.setColumn(4, B00000000);
    // m.setColumn(5, B10111100);
    // m.setColumn(6, B10111100);
    // m.setColumn(7, B01000000);
    // delay(2000);
    //
    // m.setColumn(0, B01000000);
    // m.setColumn(1, B10011000);
    // m.setColumn(2, B10011000);
    // m.setColumn(3, B00000000);
    // m.setColumn(4, B00000000);
    // m.setColumn(5, B10011000);
    // m.setColumn(6, B10011000);
    // m.setColumn(7, B01000000);
    // delay(blink);
    //
    // m.setColumn(0, B01000000);
    // m.setColumn(1, B10000000);
    // m.setColumn(2, B10000000);
    // m.setColumn(3, B00000000);
    // m.setColumn(4, B00000000);
    // m.setColumn(5, B10000000);
    // m.setColumn(6, B10000000);
    // m.setColumn(7, B01000000);
    // delay(blink);
    //
    // m.setColumn(0, B01000000);
    // m.setColumn(1, B10011000);
    // m.setColumn(2, B10011000);
    // m.setColumn(3, B00000000);
    // m.setColumn(4, B00000000);
    // m.setColumn(5, B10011000);
    // m.setColumn(6, B10011000);
    // m.setColumn(7, B01000000);
    // delay(blink);
}
