
int flex = A0;
int data = 0;
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
}

void loop()
{
  data = analogRead(flex);
  Serial.println(data);
 
//Serial.println(Serial.available(data));

 6+
   delay(1000);
}
