////Accident Avoidance System////
//// Sanyam Dawar////
const int trigPin = 7;
const int echoPin = 4;
int buzz = 10;
long duration;
int distance; 
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(13, OUTPUT);            // initialize digital pin 13 as an output.
pinMode(2, OUTPUT);
Serial.begin(9600);
}

void loop()
{

digitalWrite(trigPin, LOW);     // Clears the trigPin
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor , We can change this to print distance at any display screen inside the car
if(distance <= 50 && distance >= 20)
{
digitalWrite(13, HIGH);
// turn the LED on (HIGH is the voltage level)
}
else
{
digitalWrite(13, LOW); // turn the LED off by making the voltage LOW
// wait for a second
}
if(distance <= 20)
{
digitalWrite(2, HIGH);
// Making the audio cue to alert the driver
tone(buzz, 2000);
delay(100);
noTone(buzz);
delay(100);
tone(buzz, 2000);
delay(100);
noTone(buzz);
delay(100);
tone(buzz, 2000);
delay(100);
noTone(buzz);
tone(buzz, 2000);
delay(100);
noTone(buzz);
delay(100);
}
else
{
digitalWrite(2, LOW); // turn the LED off by making the voltage LOW
// wait for a second
}
}
