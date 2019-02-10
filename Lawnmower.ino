/* Lawnmower Control Module 
 * 2018/06/17
 * 
 * Purpose: 
 * The frsky reciever will run in pwm mode sending output on channel 1,4-8
 * The ardino takes input on pins 8-13 
 * 
 * 
 * Ardunio - Mega2560
 * RelayBoard - sainsmart
 * Channel 1 - relay pin - 8 - Throttle - on/off relay for engine
 * Channel 2 - relay pin -  - Elevon to drive servo (not sent to arduino)
 * Channel 3 - relay pin -  - Elevon to drive servo (not sent to arduino)
 * Channel 4 - relay pin - 9 - PTO
 * Channel 5 - relay pin - 10 - gain for gyro
 * Channel 6 - relay pin - 11 - Option
 * Channel 7 - relay pin - 12 - Option
 * Channel 8 - relay pin - 13 - Option
 * 
 */
#define SLEEP 500

//Variables
boolean pin;
int relaypin;

int init_throttle;
int init_pto;
int init_ch5;
int init_ch6;
int init_ch7;
int init_ch8;

int throttle;
int pto;
int trigger;
int ch5;
int ch6;
int ch7;
int ch8;

// byte PWM_PIN = 3;
byte THROTTLE_PIN = 8;
byte PTO_PIN =  9;
byte CHANNEL5_PIN = 10;
byte CHANNEL6_PIN = 11;
byte CHANNEL7_PIN = 12;
byte CHANNEL8_PIN = 13;

void setup() {
  // put your setup code here, to run once:


 //Relay Board - set the pin to a value for initalization
  for (relaypin=22; relaypin<28; relaypin++) {
    pinMode(relaypin,OUTPUT);
    digitalWrite(relaypin,HIGH);  
  }

 
  // Frsky reciever setup
  //pinMode(PWM_PIN, INPUT);
  pinMode(THROTTLE_PIN, INPUT);
  pinMode(PTO_PIN, INPUT);
  pinMode(CHANNEL5_PIN, INPUT);
  pinMode(CHANNEL6_PIN, INPUT);
  pinMode(CHANNEL7_PIN, INPUT);
  pinMode(CHANNEL8_PIN, INPUT);

  
  //Serial Output
  Serial.begin(115000);



  //Init Variables
  init_throttle=1;  
  init_pto=1;
  init_ch5=1;
  init_ch5=1;
  init_ch6=1;
  init_ch7=1;
  init_ch8=1;
}

void loop() {

// Listen for channel 1 - Throttle slider change <Engine Kill>


// If channel 1 > 1500 then turn on relay 1 (port 22) continuously until throttle drops or failsafe is triggered.
// This will connect to the ground of the engine, killing the motor if the throttle drops or failsafe is enguaged.

  throttle = pulseIn(THROTTLE_PIN, HIGH);


  if ( (throttle - init_throttle) >7 or (throttle - init_throttle) <-7 ) {
//if (throttle != init_throttle) { //detect stick movement, serial write it, and update init value for next loop.
  Serial.print ("Throttle = ");
  Serial.println (throttle);
  init_throttle = throttle;

  if (throttle > 1500) {
    //activate relay to switch ground off
    digitalWrite (22,LOW); //LOW turns relay on
  } else {
    digitalWrite (22, HIGH); //high turns relay off
  }
}




// Listen for channel 4 - PTO switch change
// If channel 4 >1500 then turn on relay 2 (port 23) for <PTO>.

  pto = pulseIn(PTO_PIN, HIGH);


if ( (pto - init_pto) >7 or (pto - init_pto) <-7 )  { //detect stick movement, serial write it, and update init value for next loop.
  Serial.print ("PTO = ");
  Serial.println (pto);
  init_pto = pto;

  if (pto > 1500) {
    //activate relay to switch pto on
    digitalWrite (23,LOW); //LOW turn relay on
  } else {
    digitalWrite (23,HIGH); //HIGH turns relay off
  }
}

// Listen for channel 5
// If channel 5 >1500 then turn on relay 2 (port 23) for <XXX>.

  ch5  = pulseIn(CHANNEL5_PIN, HIGH);


if ( (ch5 - init_ch5) >7 or (ch5 - init_ch5) <-7 )  { //detect stick movement, serial write it, and update init value for next loop.
  Serial.print ("ch5 = ");
  Serial.println (ch5);
  init_ch5 = ch5;

  if (ch5 > 1500) {
    //activate relay to switch pto on
    digitalWrite (24,LOW); //LOW turn relay on
  } else {
    digitalWrite (24,HIGH); //HIGH turns relay off
  }
}

// Listen for channel 6
// If channel 6 >1500 then turn on relay 2 (port 23) for <XXX>.

  ch6  = pulseIn(CHANNEL6_PIN, HIGH);


if ( (ch6 - init_ch6) >7 or (ch6 - init_ch6) <-7 )  { //detect stick movement, serial write it, and update init value for next loop.
  Serial.print ("ch6 = ");
  Serial.println (ch6);
  init_ch6 = ch6;

  if (ch6 > 1500) {
    //activate relay to switch pto on
    digitalWrite (25,LOW); //LOW turn relay on
  } else {
    digitalWrite (25,HIGH); //HIGH turns relay off
  }
}


// Listen for channel 7
// If channel 7 >1500 then turn on relay 2 (port 23) for <XXX>.

  ch7  = pulseIn(CHANNEL7_PIN, HIGH);


if ( (ch7 - init_ch7) >7 or (ch7 - init_ch7) <-7 )  { //detect stick movement, serial write it, and update init value for next loop.
  Serial.print ("ch7 = ");
  Serial.println (ch7);
  init_ch7 = ch7;

  if (ch7 > 1500) {
    //activate relay to switch pto on
    digitalWrite (26,LOW); //LOW turn relay on
  } else {
    digitalWrite (26,HIGH); //HIGH turns relay off
  }
}



// Listen for channel 8
// If channel 8 >1500 then turn on relay 2 (port 23) for <XXX>.

  ch8  = pulseIn(CHANNEL8_PIN, HIGH);


if ( (ch8 - init_ch8) >7 or (ch8 - init_ch8) <-7 )  { //detect stick movement, serial write it, and update init value for next loop.
  Serial.print ("ch8 = ");
  Serial.println (ch8);
  init_ch8 = ch8;

  if (ch8 > 1500) {
    //activate relay to switch pto on
    digitalWrite (27,LOW); //LOW turn relay on
  } else {
    digitalWrite (27,HIGH); //HIGH turns relay off
  }
}







}
