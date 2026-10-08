/* This code was designed by Georgia-Natalia Sgouraki on Octomber 29th 2023.
   It is intended for academic use at the Department of Informatics and Telecommunication of University of Ioannina.
   This code was designed and compiled at Arduino IDE ver. 1.8.16
   It was designed for use with Arduino UNO R3 ATmega328P		   
   Write a program that will simulate the operation of a traffic light and will display some warning messages.
   Then if the user inserts the word stop , the traffic light has to become red and the traffic light of pedestrians 
   will become green.*/

String A;        //Δήλωση μιας μεταβλητής χρησιμοποιώντας ένα τύπο δεδομένων string
int RLED = 12;   //To pin που είναι συνδεδεμένο το κόκκινο led (φανάρι αμαξιών)
int OLED = 8;    //Το pin που είναι συνδεδεμένο το πορτοκαλί led (φανάρι αμαξιών) 
int GLED = 7;    //Το pin που είναι συνδεδεμένο το πράσινο led (φανάρι αμαξιών)
int RLED2 = 2;   //Το pin που είναι συνδεδεμένο το άλλο κόκκινο led (φανάρι πεζών)
int GLED2 = 13;  //Το pin που είναι συνδεδεμένο το άλλο πράσινο led (φανάρι πεζών)

  
void setup()              //Συνάρτηση αρχικοποίησης παραμέτρων και υλικών συστήματος.
{ 
  Serial.begin(9600);     //Είναι ο ρυθμός μετάδοσης σε bits ανά δευτερόλεπτο (για Serial)
  	
  pinMode(RLED, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(OLED, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(GLED, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(RLED2, OUTPUT); //Αρχικοποιηση led ως έξοδος 
  pinMode(GLED2, OUTPUT); //Αρχικοποιηση led ως έξοδος 
 
}

void loop()      //Κύρια επαναλαμβανόμενη συνάρτηση
{ 
 
  digitalWrite(RLED, LOW);   //Κλειστό led
  digitalWrite(OLED, LOW);   //Κλειστό led
  digitalWrite(GLED, HIGH);  //Αναμμένο led
  digitalWrite(RLED2, HIGH); //Αναμμένο led
  digitalWrite(GLED2 ,LOW);  //Κλειστό led
  Serial.println("OI ODHGOI MPOREITE NA PERASETE PRASINO FANARI");
  Serial.println("OI PEZOI PERIMENETE");
  delay(5000);              //Καθυστέρηση για 5000 milliseconds 
  
  delay(30);                 //Καθυστέρηση για 30 milliseconds
  digitalWrite(RLED, LOW);   //Κλειστό led
  digitalWrite(OLED, HIGH);  //Αναμμένο led
  digitalWrite(GLED, LOW);   //Κλειστό led
  digitalWrite(RLED2, HIGH); //Αναμμένο led
  digitalWrite(GLED2 ,LOW);  //Κλειστό led
  Serial.println("PROSOXI PORTOKALI FANARI!");
  Serial.println("PEZOI PERIMENETE");
  delay(2000);               //Καθυστέρηση για 2000 milliseconds
  
  delay(30);                  //Καθυστέρηση για 30 milliseconds
  digitalWrite(RLED, HIGH);   //Αναμμένο led
  digitalWrite(OLED, LOW);    //Κλειστό led
  digitalWrite(GLED, LOW);    //Κλειστό led
  digitalWrite(RLED2, LOW);   //Αναμμένο led
  digitalWrite(GLED2 ,HIGH);  //Κλειστό led
  Serial.println("PROSOXI KOKKINO FANARI ODHGOI STAMATHSTE!");
  Serial.println("OI PEZOI MPOREITE NA PERASETE");
  delay(7000);                //Καθυστέρηση για 7000 milliseconds
  
  
  Serial.println("KOUMPI STOP");
  A = Serial.readString();       //Διαβάζει χαρακτήρες από το buffer και τα αποθηκεύει  σε ένα String
  delay(500);                    //Kαθυστέρηση για 500 milliseconds
  
  if(A == "stop")  
  {
    Serial.println(A);
    digitalWrite(RLED, HIGH);    //Αναμμένο led
    digitalWrite(OLED, LOW);     //Κλειστό led
    digitalWrite(GLED, LOW);     //Κλειστό led
    digitalWrite(RLED2, LOW);    //Κλειστό led
    digitalWrite(GLED2 , HIGH);  //Αναμμένο led
    Serial.println("KOKKINO FANARI, OI ODHGOI STAMATHSTE!");
    Serial.println("OI PEZOI MPOREITE NA PERASETE");
    delay(7000);   //Καθυστέρηση για 7000 milliseconds
  }
  
}  
