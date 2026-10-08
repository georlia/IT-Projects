/* This code was designed by Georgia-Natalia Sgouraki on Octomber 29th 2023.
   It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina.
   
   This code was designed and compiled at Arduino IDE ver. 1.8.16
   It was designed for use with Arduino UNO R3 ATmega328P		
   
   Write a program that will produce values range 0 – 255 and based on the values will check the brightness of a led.
*/

int led = 8;                 //Το pin που είναι συνδεδεμένο το led

void setup()                //Συνάρτηση αρχικοποίησης παραμέτρων και υλικών συστήματος.
{
  pinMode(led, OUTPUT);     //Αρχικοποιηση led ως έξοδος 
} 


void loop()                 //Κύρια επαναλαμβανόμενη συνάρτηση

{ 
  int br = random (0,255);  //Επιλεγει τυχαία  τιμή απο 0 έως το 255
  analogWrite(led,br);      //Ρυθμίζει την φωτεινότητα στο pin  8
  delay(40);                //delay για 40 millisecond

}
