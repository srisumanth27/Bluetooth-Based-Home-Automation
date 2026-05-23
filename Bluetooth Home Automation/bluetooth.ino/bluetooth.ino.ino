const int relayPin1 = 7; // Relay pin for light
const int relayPin2 = 8; // Relay pin for fan

void setup() {
  Serial.begin(9600);    // Start serial communication at 9600 baud
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  digitalWrite(relayPin1, HIGH);  // Relay off initially (active LOW) for light
  digitalWrite(relayPin2, HIGH);  // Relay off initially (active LOW) for fan
  Serial.println("Bluetooth Relay Control Initialized");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();  // Read the incoming data
    Serial.print("Received command: ");
    Serial.println(command);

    if (command == '1'||command=="Light on") {
      digitalWrite(relayPin1, LOW);  // Turn light relay on
      Serial.println("Light ON");
    } else if (command == '0'||command=="Light off") {
      digitalWrite(relayPin1, HIGH); // Turn light relay off
      Serial.println("Light OFF");
    } else if (command == '3') {
      digitalWrite(relayPin2, LOW);  // Turn fan relay on
      Serial.println("Fan ON");
    } else if (command == '2') {
      digitalWrite(relayPin2, HIGH); // Turn fan relay off
      Serial.println("Fan OFF");
    } else {
      Serial.println("Invalid command");
    }
  }
}