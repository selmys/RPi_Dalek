// Sonar defines
#define SONAR_ECHO  4
#define SONAR_TRIG 11
// Get sonar distance in centimeters
int GetDistance() {
    long startTime;
    // TRIG pin must start LOW
    digitalWrite(SONAR_TRIG, LOW);
    delay(100); //delay 1/10 second    
    // Send trig pulse
    digitalWrite(SONAR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(SONAR_TRIG, LOW);

    while(digitalRead(SONAR_ECHO) == LOW);

    startTime = micros();

    // Wait for echo
    while(digitalRead(SONAR_ECHO) == HIGH);

    return  (micros() - startTime)/ 58;
}
