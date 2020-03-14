#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10);
volatile int NbTopsFan; //measuring the rising edges of the signal
int Calc;
int hallsensor = 2; //The pin location of the sensor
void rpm ();
void SendMessage();
void setup() //
{
 pinMode(hallsensor, INPUT); 
 digitalWrite(hallsensor,LOW);
 pinMode(hallsensor, INPUT_PULLUP);
 mySerial.begin(9600);   // Setting the baud rate of GSM Module  
 Serial.begin(9600); 
 attachInterrupt(0, rpm, RISING); //and the interrupt is attached
}
void loop ()
{
 
 NbTopsFan = 0; //Set NbTops to 0 ready for calculations
 interrupts();
 delay (1000); //Wait 1 second
 noInterrupts();
 Calc = (NbTopsFan * 60 / 7.5); //(Pulse frequency x 60) / 7.5Q, = flow rate in L/hour
 Serial.println(Calc);
    if(Calc>50)
    SendMessage(Calc);
 }
 
void rpm () //This is the function that the interupt calls
{
 NbTopsFan++; //This function measures the rising and falling edge of the hall effect sensors signal
}

void SendMessage(int Calc)
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918297669741\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println(Calc);// The SMS text you want to send
  mySerial.println("Leak Has Been Detected");// The SMS text you want to send
  delay(1000);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
