const int button = 2;
const int led = 6;

int buttonState = 0;
int sequence[200];
int seq_length = 0;
int i, j;

void setup() {
  Serial.begin(9600);
  
  pinMode(led, OUTPUT);
  pinMode(led+1, OUTPUT);
  pinMode(led+2, OUTPUT);
  pinMode(led+3, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button+1, INPUT);
  pinMode(button+2, INPUT);
  pinMode(button+3, INPUT);
  
  playSequence();
}

void loop() {
  for (i = 0; i < seq_length; i++) {
    buttonState = 0;
    waitForInput();
    
    if (sequence[i] != buttonState) {
      Serial.println("You lose!");
      seq_length = 0;
      blinkAll(3);
      break;
    }
    else {
      Serial.println("You got it right!");
    }
  }
  
  playSequence();
}

void addNumber() {
  sequence[seq_length] = random(1, 5);
  seq_length++;
}

void playSequence() {
  blinkAll(2);
  addNumber();
  
  for (i = 0; i < seq_length; i++) {
    Serial.println(sequence[i]);
    blink(sequence[i]);
  }
}

void waitForInput() {
  while (!buttonState) {
    if (digitalRead(button)) buttonState = 1;
    else if (digitalRead(button+1)) buttonState = 2;
    else if (digitalRead(button+2)) buttonState = 3;
    else if (digitalRead(button+3)) buttonState = 4;
    else buttonState = 0;
  }
  
  while (digitalRead(button) || digitalRead(button+1) || digitalRead(button+2) || digitalRead(button+3));
}

void blink (int number) {
  digitalWrite(led + number - 1, HIGH);
  delay(500);
  digitalWrite(led + number - 1, LOW);
  delay(500);
}

void blinkAll(int number) {
  for (j = 0; j < number; j++) {
    digitalWrite(led, HIGH);
    digitalWrite(led+1, HIGH);
    digitalWrite(led+2, HIGH);
    digitalWrite(led+3, HIGH);
    delay(200);
    
    digitalWrite(led, LOW);
    digitalWrite(led+1, LOW);
    digitalWrite(led+2, LOW);
    digitalWrite(led+3, LOW);
    delay(200);
  }
}
