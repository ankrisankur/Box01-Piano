#include <CapacitiveSensor.h>

CapacitiveSensor   cs_8_2 = CapacitiveSensor(8,2);
CapacitiveSensor   cs_8_3 = CapacitiveSensor(8,3);
CapacitiveSensor   cs_8_4 = CapacitiveSensor(8,4);
CapacitiveSensor   cs_8_5 = CapacitiveSensor(8,5);

void setup()                    
{
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_8_2.capacitiveSensor(40);
    long total2 =  cs_8_3.capacitiveSensor(40);
    long total3 =  cs_8_4.capacitiveSensor(40);
    long total4 =  cs_8_5.capacitiveSensor(40);

    Serial.print(millis() - start);
    Serial.print("\t");
    Serial.print(total1);
    Serial.print("\t");
    Serial.print(total2);
    Serial.print("\t");
    Serial.print(total3);
    Serial.print("\t");
    Serial.println(total4);
 
    delay(10);
}

