/* This is my Arduino sketch! It waves a Servo to say hello whenever I get a "1" from the Processing sketch.
 *  You could do anything here though, just change out the Servo code for whatever you want.
 */

#include <VSync.h>
#include <Servo.h>

//  Create a new receiver that can receive up to two values.
//  Always put the number of values to sync in the pointy brackets.
ValueReceiver<2> receiver;

//  The variable that will be synced with the Processing sketch.
int wave;

// Servo stuff
int pos;
int minPos = 50;
int maxPos = 200;

Servo myservo;

void setup()
{
  //  You need to call Serial.begin() in order for value syncing to work.
  //  Make sure to use the same baudrate on both ends. More baud = more speed
  Serial.begin(19200);
  
  // Initialize Servo
  pos = minPos;
  myservo.attach(9);
  
  //  Tell the receiver what variables to sync. It must be int variables!
  //  Also take care that you observe the variables in the same order
  //  as on the sending (Processing) side!
  receiver.observe(wave);
}

void loop()
{
  //  You need to call sync() once every loop.
  //  It does not matter where in the loop you call it, 
  //  but receiving at the start makes most sense.
  receiver.sync();
  
  // Check for the info we're looking for from Processing
  if (wave == 1) {
    sayHi();
  }
}


// Servo wave code
void sayHi() {
  int waves = 0;
  while (waves < 2) {
      for (pos = minPos; pos <= maxPos; pos += 1) { 
        myservo.write(pos);             
        delay(2);                      
      }
      for (pos = maxPos; pos >= minPos; pos -= 1) { 
        myservo.write(pos);             
        delay(2);                       
      }
      waves++;
  }
}




