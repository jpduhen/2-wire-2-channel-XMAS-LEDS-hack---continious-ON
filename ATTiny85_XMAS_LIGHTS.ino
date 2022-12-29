/*
  ATTiny85 XMAS light Continious ON
  for 2-wire 2 channel LED XMAS lights
  removes irritating flikkering, all lights stay always "ON"
  
  see https://github.com/jpduhen/2-wire-2-channel-XMAS-LEDS-hack---continious-ON/blob/main/README.md
  
  version 28-12-2022
  by J.P. Duhen 
*/
  
// constants won't change. Used here to set a pin number:
const int ledPin0 =  2;          // the number of the LED pin
const int ledPin1 =  1
;          // the number of the LED pin

// Variables will change:
int ledState0 = HIGH;            // ledState used to set the 0-LEDs
int ledState1 = LOW;             // ledState used to set the 1-LEDs

void setup() {
  // set the digital pins as output:
  pinMode(ledPin0, OUTPUT);
  pinMode(ledPin1, OUTPUT);
}

void loop() {

  // alternate 0- and 1-LEDs ON-OFF-ON very quickly, both seem continious ON 
  
  if (ledState0 == HIGH) {
    // if 0-LEDs are ON
    
    ledState0 = LOW;
    digitalWrite(ledPin0, ledState0);
    // first turn 0-LEDs OFF, 
    // some time needed to reverse polarity 
    // before 1-LEDs can turn ON
    
    ledState1 = HIGH;
    digitalWrite(ledPin1, ledState1);
    // now turn 1-LEDs on 
    
  } else {
    // 0-LEDs are NOT ON (e.g. OFF) => 1-LEDs are ON
    
    ledState1 = LOW;
    digitalWrite(ledPin1, ledState1);
    // first turn 1-LEDs OFF, 
    // some time needed to reverse polarity 
    // before 0-LEDs can turn ON
    
    ledState0 = HIGH;
    digitalWrite(ledPin0, ledState0);
    // turn 0-LEDs ON      
  }

}
