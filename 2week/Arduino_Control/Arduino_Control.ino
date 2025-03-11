// C++ code
//
#define TRIG 12 	// TRIG pin
#define ECHO 11		// ECHO pin

// global 
int led_r = 7;
int led_g = 9;

void setup()
{
  Serial.begin(9600);
  
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop()
{
  long duration, distance;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2); // = delay(2)
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); // = delay(10)
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn(ECHO, HIGH); // Echo pin High stance time
  distance = duration * 17 / 1000;
  
  Serial.println(duration);
  Serial.print("\nDistance : ");
  Serial.print(distance);
  Serial.println(" Cm");
  
  
  digitalWrite(led_r, HIGH);
  delay(200); // Wait for 1000 millisecond(s)
  digitalWrite(led_r, LOW);
  delay(200);
  digitalWrite(led_g, HIGH);
  delay(200);
  digitalWrite(led_g, LOW);
  delay(200); // Wait for 1000 millisecond(s)
}