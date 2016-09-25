
import vsync.*;
import processing.serial.*;
import oscP5.*;
import netP5.*;
OscP5 oscP5;
NetAddress dest;

// This variable is specific to my project, but it could be any type of information you're sending via Wekinator
public int wave;

ValueSender sender;

void setup() 
{
  // To find out what your version of "/dev/cu.usbmodem1421" should be, in the Arduino editor, 
  // go to the "Tools" menu and find the port of your Arduino. Make sure it's plugged in.
  Serial serial = new Serial(this, "/dev/cu.usbmodem1421", 19200);
  
  sender = new ValueSender(this, serial);
  
  // Tell the ValueSender what variables to synchronize from the arduino to the Processing sketch.
  // Be careful to always use the same order as on the other side!
  wave = 0;
  sender.observe("wave");
  
  
  // This hooks up the sketch to Wekinator: listen on port 1200, return messages on port 6448
  oscP5 = new OscP5(this, 12000); 
  dest = new NetAddress("127.0.0.1", 6448);
}


// Recieve OSC messages from Wekinator
void oscEvent(OscMessage theOscMessage) {
  if (theOscMessage.checkAddrPattern("/wek/outputs") == true) {
    // YOU WILL HAVE TO EDIT THIS depending on the type of output you're sending from Wekinator! 
    // This is very specific to my program :)
    float value = theOscMessage.get(0).floatValue();
    
    if (int(value) == 1) {
      wave = 1;
    } else {
      wave = 0;
    }
  }
}

void draw() 
{
  //  Nothing to be drawn for this example
}