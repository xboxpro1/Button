#include <Button.h>

static Button button1; // not enabled yet, setup has to be called later
static Button button2; // not enabled yet, setup has to be called later
static Button button3; // not enabled yet, setup has to be called later

void setup() {
	button1.setup(2); // Connect your button between pin 2 and GND
	button2.setup(3); // Connect your button between pin 3 and GND
	button3.setup(4); // Connect your button between pin 4 and GND
	
	while (!Serial) { }; // for Leos
	Serial.begin(115200);
}

void loop() {
	if (button1.pressed())
		Serial.println("Button 1 pressed");
	
	if (button2.released())
		Serial.println("Button 2 released");
	
	if (button3.toggled()) {
		if (!button3.read())
			Serial.println("Button 3 has been pressed");
		else
			Serial.println("Button 3 has been released");
	}
}
