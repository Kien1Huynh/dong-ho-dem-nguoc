#include "SevSeg.h"

SevSeg myDisplay;

int bientro = A0;


int maxTime = 9999;
int timeLeft;
int defaultTime = 99;
int second, minute;
unsigned long milli, milli2;
boolean startCounting = true;
char buf[5];

int buttonPin[3] = {A3, A2, A1}; // các nút chức năng sẽ làm sau
int button[3];


void setup()
{

    int displayType = COMMON_ANODE;
    int digit1 = 8;
    int digit2 = 12;
    int digit3 = 13;
    int digit4 = 2;

    int segA = 9;
    int segB = 11;
    int segC = 4;
    int segD = 6;
    int segE = 7;
    int segF = 10;
    int segG = 3;
    int segDP = 5;

    int numberOfDigits = 4;

    myDisplay.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);

    myDisplay.SetBrightness(100);

    milli = milli2 = millis();
    timeLeft = defaultTime;

}


void loop()
{
    
    myDisplay.SetBrightness(getBrightness());

    minute = timeLeft / 100;
    second = timeLeft % 100;

    sprintf(buf, "%02d%02d", minute, second);
    myDisplay.DisplayString(buf, 00000010);

    if (startCounting && timeLeft > 0 && (millis() - milli) > 1000)
    {
        milli = millis();
        timeLeft--;
    }

    delay(5);

}


int getBrightness()
{
    int value = analogRead(bientro);
    value = map(value, 0, 1023, 0, 100);
    Serial.println(value);
    return value;
}
