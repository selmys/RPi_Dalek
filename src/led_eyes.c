// LED defines
#define RED_LEFT    27
#define GREEN_RIGHT 22

// Control LEDs in robot head
// 'L' left LED, 'R' right LED
// mode 0 is OFF, 1 is ON, 2 is BLINK
void LED_Control(char led, int mode) {
    switch (led) {
        case 'L':   switch (mode) {
                        case 0: softToneWrite(RED_LEFT, 0);
                                break;
                        case 1: softToneWrite(RED_LEFT, 100);
                                break;
                        case 2: softToneWrite(RED_LEFT, 2);
                                break;
                    }
                    break;
        case 'R':   switch (mode) {
                        case 0: softToneWrite(GREEN_RIGHT, 0);
                                break;
                        case 1: softToneWrite(GREEN_RIGHT, 100);
                                break;
                        case 2: softToneWrite(GREEN_RIGHT, 2);
                                break;
                    }
                    break;
    }
}
