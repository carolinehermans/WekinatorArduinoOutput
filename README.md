# WekinatorArduinoOutput
This repo contains Processing and Arduino code in order to get Wekinator output into an Arduino without using a Wifi module. This code is also specific to a project I was working on, so modifications and circuit building and such will be required to get your Arduino to do what you want!

## Installation

### VSync
In Processing, go to Sketch>Import Library>Add Library and search for Vsync.
In Arduino, download the zip of this repository: https://github.com/erniejunior/VSync and then add it as a library.

### Wekinator
This repo only contains code to manage Wekinator output: you will still need to hook up inputs to a Wekinator project.

## Running It
In order to run this, you need to first compile and upload your code to the Arduino board, and then run the Processing sketch, in that order.


## How It Works
Since Arduino can't directly recieve wireless information without a Wifi module, we instead have a Processing sketch recieving information directly from Wekinator via OSC. Meanwhile, the VSync library allows Processing and Arduino to talk to each other via the Serial USB port. The Processing sketch interprets the OSC Message and syncs it with Arduino via VSync.
