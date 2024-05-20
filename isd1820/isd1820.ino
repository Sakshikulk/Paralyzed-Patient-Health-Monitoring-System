
 /*
 * ISD1820 Arduino Voice Recorder
 * to record and playback sound using Arduino and ISD1820 Sound Recorder

 * Watch the video https://youtu.be/IfK8z_o5vbk
 * get this code from http://robojax.com/learn/arduino/
 * Get this code and other Arduino codes from Robojax.com
 
Learn Arduino step by step in structured course with all material, wiring diagram and library
all in once place. Purchase My course on Udemy.com http://robojax.com/L/?id=62

Get early access to my videos and have your name shown at the end of my vidoes by joining on  Patreon http://robojax.com/L/?id=63

/*
 * ISD1820 Arduino Voice Recorder
 * Code Written by Ahmad Shamshiri for Robojax.com
 * on Jan 04, 2018 at 08:57, in Ajax, Ontario, Canada
  * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 */
#define REC 2 // pin 2 is used for recording
#define PLAY_E 3 // pin 3 is used for playback-edge trigger
// when PLAY_E goes HIGH device will playbak STARTS and continues
// ISD1820 Arduino Voice Recorder for Robojax.com 

#define PLAY_L 4 // pin 4 is used for playback  
// when PLAY_L is HIGH it will playback. As soon as it goes LOW playback STOPS
// So you have to keep it HIGH to keep playing


#define FT 5 // pin 5 is used for feed through
// if the SPI (speaker) pin is used to send Audio to other device, 
// set FT to high and any audio from microphone will pass through the SPI connector
// and will NOT record

#define playTime 5000 // playback time 5 seconds
#define recordTime 3000 // recording time 3 seconds
#define playLTime 900 // press and release playback time 0.9 seconds

void setup() 
{
  // ISD1820 Arduino Voice Recorder for Robojax.com 
  pinMode(REC,OUTPUT);// set the REC pin as output
  pinMode(PLAY_L,OUTPUT);// set the PLAY_L pin as output
  pinMode(PLAY_E,OUTPUT);// set the PLAY_e pin as output
  pinMode(FT,OUTPUT);// set the FT pin as output  
  Serial.begin(9600);// set up Serial monitor   
}

void loop() {
  // ISD1820 Arduino Voice Recorder for Robojax.com 
    while (Serial.available() > 0) {
          char inChar = (char)Serial.read();
            if(inChar =='p' || inChar =='P'){
            digitalWrite(PLAY_E, HIGH);
            delay(50);
            digitalWrite(PLAY_E, LOW);  
              Serial.println("Playbak Started");  
            delay(playTime);
            
              Serial.println("Playbak Ended");
            break; 
            }// if          
            else if(inChar =='r' || inChar =='R'){
              digitalWrite(REC, HIGH);
              Serial.println("Recording started");
              delay(recordTime);
              digitalWrite(REC, LOW);
              Serial.println("Recording Stopped ");              
            } 
            else if(inChar =='l' || inChar =='L'){
            digitalWrite(PLAY_L, HIGH); 
              Serial.println("Playbak L Started");  
            delay(playLTime);
            digitalWrite(PLAY_L, LOW);
              Serial.println("Playbak L Ended");            
            }             
    // ISD1820 Arduino Voice Recorder for Robojax.com         
      Serial.println("**** Serial Monitor Exited");      
    }// wihile
Serial.println("**** Enter r to record, p to play");

  delay(500);
}
