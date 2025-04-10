#define BUTTON_PIN 9       // Button pin (interrupt)
#define PIR_SENSOR_PIN 10  // PIR motion sensor pin (interrupt)
#define LED_OUTPUT_PIN 11  // LED output pin

volatile bool isLedOn = false;  // Track LED state (must be volatile for ISR)

// Interrupt Service Routine for button press
void onButtonPress() {
  isLedOn = !isLedOn;
  digitalWrite(LED_OUTPUT_PIN, isLedOn);
  Serial.println("Button interruption");
}

// Interrupt Service Routine for motion detection
void onMotionDetected() {
  isLedOn = !isLedOn;
  digitalWrite(LED_OUTPUT_PIN, isLedOn);
  Serial.println("Motion interruption");
}

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);     // Internal pull-up resistor for button
  pinMode(PIR_SENSOR_PIN, INPUT);        // PIR sensor as input
  pinMode(LED_OUTPUT_PIN, OUTPUT);       // LED as output

  // Attach interrupt handlers
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), onButtonPress, FALLING);
  attachInterrupt(digitalPinToInterrupt(PIR_SENSOR_PIN), onMotionDetected, RISING);
}

void loop() {
  // Main loop left empty because interrupts handle the logic
}
