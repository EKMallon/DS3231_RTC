/* ReatTimeClock_reset - Last updated Apr2014
 
 Use this sketch to reset the DS1307 & DS3231 Real Time Clocks. It will grab
 the computer's current time during compilation and send that value
 to the real time clock. 
 
 HAVE THE SERIAL MONITOR OPEN WHEN YOU UPLOAD. You introduce a significant delay if you open it late.
 
 Afterwards, immediately upload a DIFFERENT sketch to the Arduino
 so that it doesn't try to constantly reset the clock when it 
 powers up the next time. If it does reset, the Arduino will reset 
 the clock with the old compile time stamp, which will be out of
 date.
 */

// from https://github.com/MrAlvin/RTClib/blob/master/examples/settime/settime.pde

#include <Wire.h>
#include <SPI.h>    // Not used here but required for this RTClib to compile properly
#include <RTClib.h> // this is the library from https://github.com/MrAlvin/RTClib
#define RTCPOWER_PIN 7

RTC_DS1307 RTC;

boolean resetFlag = false; // flag for clock reset

void setup(void)
{
  pinMode(RTCPOWER_PIN, HIGH);   //some of my units use this pin for powering the RTC, need to set high for I2c coms.
  Wire.begin();
  RTC.begin();  
  RTC.adjust(DateTime(__DATE__, __TIME__));
  DateTime now = RTC.now();
  /*Serial.begin(9600);
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC); 
  */

}

void loop(void)
{
  DateTime now = RTC.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.println(now.second(), DEC);
  //the leds just tell me the time has been updated without opening the serial window, which restarts the application
  digitalWrite(4,HIGH);
  delay(500);
  digitalWrite(4,LOW);
  delay(500);
  digitalWrite(5,HIGH);
  delay(500);
  digitalWrite(5,LOW);
  delay(500);
  digitalWrite(6,HIGH);
  delay(500);
  digitalWrite(6,LOW);
  delay(500);

}

