#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10 megohm between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50 kilohm - 50 megohm. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 * Best results are obtained if sensor foil and wire is covered with an insulator such as paper or plastic sheet
 */
int notes[]={245,257,276,293};

CapacitiveSensor   cs_8_2 = CapacitiveSensor(8,2);        // 10 megohm resistor between pins 4 & 2, pin 2 is sensor pin, add wire, foil
CapacitiveSensor   cs_8_3 = CapacitiveSensor(8,3);        // 10 megohm resistor between pins 4 & 6, pin 6 is sensor pin, add wire, foil
CapacitiveSensor   cs_8_4 = CapacitiveSensor(8,4);        // 10 megohm resistor between pins 4 & 8, pin 8 is sensor pin, add wire, foil
CapacitiveSensor   cs_8_5 = CapacitiveSensor(8,5);

void setup()                    
{
    pinMode(13, OUTPUT);
   //cs_8_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);

}

void loop()                    
{
    long start = millis();
    long total1 =  cs_8_2.capacitiveSensor(40);
    long total2 =  cs_8_3.capacitiveSensor(40);
    long total3 =  cs_8_4.capacitiveSensor(40);
    long total4 =  cs_8_5.capacitiveSensor(40);

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug window spacing
    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.print(total3);                // print sensor output 3
    Serial.print("\t");
    Serial.println(total4);

    if(total1>100)
    tone(13, notes[0],264);
    if(total2>100)
    tone(13, notes[1],264);
    if(total3>100)
    tone(13, notes[2],264);
    if(total4>100)
    tone(13, notes[3],264);
    

    delay(10);                             // arbitrary delay to limit data to serial port 
}
