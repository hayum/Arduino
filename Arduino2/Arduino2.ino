#include <CapacitiveSensor.h>

const int fanPin = 3; 
const int brushPin = 6; 
const int clothPin = 5; 
//const int branchPin = 4,2; 
const int ledPin = 13; 
CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2); // 4 & 2, pin 2 is sensor pin,
int fanState,brushState,clothState,branchState,lastState,lastStateF;

int val,old;

void setup()                    
{
  branchState=0;
  lastState=0;
  val=-1;
  old=-1;
   pinMode(fanPin, INPUT_PULLUP);
   pinMode(brushPin, INPUT);//INPUT
   pinMode(clothPin, INPUT_PULLUP);
   pinMode(ledPin,OUTPUT);
   
  cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
   
   digitalWrite(brushPin, HIGH); 
   digitalWrite(fanPin, HIGH); 
}

void loop()                    
{    
    fanState = digitalRead(fanPin);
    brushState = digitalRead(brushPin);
    clothState = digitalRead(clothPin);
    //branchState = digitalRead(branchPin);
    long branch =  cs_4_2.capacitiveSensor(30);
    if(branch>500){
       branchState=true;
    }
    else{
      branchState=false;
    }
    if (fanState && !lastStateF) {
   //Serial.println("Unbroken");
      val=1;
   }
    if(clothState){
    val=2; 
   }
    if (brushState && !lastState) {
   //Serial.println("Unbroken");
    val=3;
   }
    if(branchState){
     val=4;
   }
  
  lastState = brushState;
  lastStateF = fanState;
  if(old!=val){ 
    Serial.write(val);
   //Serial.println(val);
    old=val;
  }

  delay(100);
}
