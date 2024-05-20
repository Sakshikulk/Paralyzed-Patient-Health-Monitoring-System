// DEFINING VARIABLES FOR FLEX SENSOR
int flex = A0;
int data = 0;

// DEFINING VARIABLES FOR VOICE MODULE
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

#define playTime 10000 // playback time 5 seconds
#define recordTime 10000 // recording time 3 seconds
#define playLTime 900 // press and release playback time 0.9 seconds


// DEFINING VARIABLES FOR STORING FIRST VALUE FROM SERIAL MONITOR
bool dataReceived = false; // Flag to check if data has been received
int receivedValue; // Variable to store the received integer value
const unsigned int MAX_MESSAGE_LENGTH = 12;
const unsigned int MAX_MESSAGE_LENGTH1 = 12;
int number1;
int number;


void setup()
{
  Serial.begin(9600);
  pinMode(flex, INPUT);


  // ISD1820 Arduino Voice Recorder for Robojax.com 
  pinMode(REC,OUTPUT);// set the REC pin as output
  pinMode(PLAY_L,OUTPUT);// set the PLAY_L pin as output
  pinMode(PLAY_E,OUTPUT);// set the PLAY_e pin as output
  pinMode(FT,OUTPUT);// set the FT pin as output  
  Serial.begin(9600);// set up Serial monitor   
}

void loop(){
  data = analogRead(flex);
  Serial.println(data);
  
  if (dataReceived == false ) {
// check to see if anything is available int the serial buffer
     number = data;
    Serial.print("the valye is :");
    Serial.println(number);
    dataReceived = true;
  }
  // ISD1820 Arduino Voice Recorder for Robojax.com 
  number1 = data;

  Serial.print("number1 is");
  Serial.println(number1);
  Serial.print("number is");
  Serial.println(number);
  if(number1 >= number+5 || number1<=number-5){
    digitalWrite(PLAY_E, HIGH);
    delay(50);
    digitalWrite(PLAY_E, LOW);  
    Serial.println("Playbak Started");  
    delay(playTime);
    Serial.println("Playbak Ended");
  }    
     delay(1000);
}
