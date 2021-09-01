// Taser defines
#define TASER 17

void TaserTest() {
    SaySomething("Exterminate!");
    digitalWrite(TASER, HIGH);
    delay(1000);
    digitalWrite(TASER, LOW);
}
