/* This code was designed by Georgia-Natalia Sgouraki on Octomber 29th 2023.
   It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina.
   
   This code was designed and compiled at Arduino IDE ver. 1.8.16
   It was designed for use with Arduino UNO R3 ATmega328P		
   
   Write a program which will simulate the operation of a lock system and will have three buttons (corresponding to the numbers 1, 2, 3). 
   When the user chooses the correct combination, a green led will light up, otherwise if he presses the wrong one, the red led
*/

//ο κωδικός μου είναι 3 1 2
int Button1 = 2;        //Το pin που είναι συδεδεμένο το button 1
int Button2 = 4;       //Το pin που είναι συνδεδεμένο το button 2
int Button3 = 8;       //Το pin που είναι συνδεδεμένο το button 3
int RLED = 7;          //To pin που είναι συνδεδεμένο το κόκκινο led 
int GLED = 12;         //To pin που είναι συνδεδεμένο το πράσινο led 
int buttonState1 = 0;  //Μεταβλητή που αποθηκεύει τη κατάσταση του button 1 
int buttonState2 = 0;  //Μεταβλητή που αποθηκεύει τη κατάσταση του button 2
int buttonState3 = 0;  //Μεταβλητή που αποθηκεύει τη κατάσταση του button 3
int number = 0;        //Μεταβλητή που μετράει τα κουμπία που πατήθηκαν

void setup()                //Συνάρτηση αρχικοποίησης παραμέτρων και υλικών συστήματος.
 {
  Serial.begin(9600);        //Είναι ο ρυθμός μετάδοσης σε bits ανά δευτερόλεπτο (για Serial)
  pinMode(Button1, INPUT);   //Αρχικοποίηση button ως είσοδος
  pinMode(Button2, INPUT);   //Αρχικοποίηση button ως είσοδος
  pinMode(Button3, INPUT);   //Αρχικοποίηση button ως είσοδος
  pinMode(RLED, OUTPUT);     //Αρχικοποιηση led ως έξοδος 
  pinMode(GLED, OUTPUT);     //Αρχικοποιηση led ως έξοδος 
  digitalWrite(RLED, HIGH);  //Αναμμένο κόκκινο led 
 }

void loop()                            //Κύρια επαναλαμβανόμενη συνάρτηση
{
  buttonState1 = digitalRead(Button1);   //Διαβάζει και αποθηκεύει τη κατάσταση των κουμπιών 1,2,3 σε μεταβλητές
  buttonState2 = digitalRead(Button2); 
  buttonState3 = digitalRead(Button3); 
 
  if (buttonState3 == HIGH && number == 0)
  {
    number=1;

  }

  if (buttonState1 == HIGH && number == 1)
  {
    number=2;
  }


   if (buttonState2 == HIGH && number == 2)
   {
    number=3;
   }

 
  if (number == 3)
  {
    digitalWrite(GLED, HIGH); //Αναμμένο πράσινο led
    digitalWrite(RLED, LOW); //Κλειστό κόκκινο led
    delay(10000);             //Καθυστέρηση για 10000 milliseconds
  }
  

     
}
