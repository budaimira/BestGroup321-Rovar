byte directionPin = 5;  // ************** cnc shield x direction
byte stepPin = 2;                 // ***************cnc shield x step
byte enablePin = 8;              // ***************  cnc shield enable pin
int numberOfSteps = 200;
byte ledPin = 13;
int pulseWidthMicros = 20;  // microseconds
int millisbetweenSteps = 250; // milliseconds - or try 1000 for slower steps


void setup()
{

   Serial.begin(9600);
   Serial.println("Starting StepperTest");
   digitalWrite(ledPin, LOW);

   delay(2000);
   pinMode(enablePin, OUTPUT);  //******* enable pin
   pinMode(directionPin, OUTPUT);
   pinMode(stepPin, OUTPUT);
   pinMode(ledPin, OUTPUT);

   digitalWrite(enablePin, LOW); // ********** enable motors
   digitalWrite(directionPin, HIGH);
   for (int n = 0; n < numberOfSteps; n++)
   {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(pulseWidthMicros); // this line is probably unnecessary
      digitalWrite(stepPin, LOW);
      delay(millisbetweenSteps);
      digitalWrite(ledPin, !digitalRead(ledPin));
   }
   delay(3000);
   digitalWrite(directionPin, LOW);
   for (int n = 0; n < numberOfSteps; n++)
   {
      digitalWrite(stepPin, HIGH);
      // delayMicroseconds(pulseWidthMicros); // probably not needed
      digitalWrite(stepPin, LOW);
      delay(millisbetweenSteps);
      digitalWrite(ledPin, !digitalRead(ledPin));
   }
}

void loop()
{
}