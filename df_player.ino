#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  pinMode(13, OUTPUT);

  // Turn on immediately to confirm chip is running
  digitalWrite(13, HIGH);
  delay(2000);
  digitalWrite(13, LOW);

  mySoftwareSerial.begin(9600);

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    // fast blink = DFPlayer not found
    while (true) {
      digitalWrite(13, HIGH); delay(100);
      digitalWrite(13, LOW);  delay(100);
    }
  }

  // slow blink = DFPlayer found, attempting to play
  digitalWrite(13, HIGH); delay(500);
  digitalWrite(13, LOW);  delay(500);

  myDFPlayer.volume(30);
  delay(500);
  myDFPlayer.play(1);
}

void loop() {
}