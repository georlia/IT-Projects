/* 
    Αυτός ο κώδικας σχεδιάστηκε από τη Γεωργία-Ναταλία Σγουράκη στις 13 Δεκεμβρίου 2023.
    Προορίζεται για ακαδημαϊκή χρήση στο Τμήμα Πληροφορικής και Τηλεπικοινωνιών του Πανεπιστημίου Ιωαννίνων.
   
    Αυτός ο κώδικας σχεδιάστηκε και μεταγλωττίστηκε στην έκδοση Arduino IDE. 1.8.16
    Σχεδιάστηκε για χρήση με το Arduino UNO R3 ATmega328P
   
    Γράψτε ένα πρόγραμμα που θα υλοποιήσει ένα μέρος μιας Έξυπνης Πόλης και θα διαθέτει ένα αισθητήρα ανίχνευσης 
    φωτός, αισθητήρα απόστασης και ένα αισθητήρα ανίχνευσης κίνησης.
*/

#define echoPin 13  //συνδεσα την ακίδα 13 Arduino στην ακίδα Echo του HC-SR04
#define trigPin 11 //συνδέστε την ακίδα -11 Arduino στην ακίδα Trig του HC-SR04

long duration; // μεταβλητή για τη διάρκεια της διαδρομής των ηχητικών κυμάτων
int distance;  // μεταβλητή για τη μέτρηση της απόστασης

const int buzzer =1; //buzzer στο pin 1

int rled = 7;   //To pin που είναι συνδεδεμένο το κόκκινο led 
int gled = 9;   //Το pin που είναι συνδεδεμένο το πορτοκαλί led 
int oled = 8;   //Το pin που είναι συνδεδεμένο το πράσινο led 
int led1 = 2;   //Τα pin που είναι συνδεδεμενα τα 5 πέντε κεντρικά φώτα
int led2 = 3;   
int led3 = 4;  
int led4 = 5;   
int led5 = 6;
int pled =  10;  //Tα pin που είναι συνδεδεμένα τα φωτα στο εσωτερικό του πανεπιστημίου
int pled2 = 10;  
int hour = 24;   //Μεταβλητή που αναπαριστά την ώρα


void setup() //Συνάρτηση αρχικοποίησης παραμέτρων και υλικών συστήματος
{
  pinMode(trigPin, OUTPUT); // Αρχικοποιει το trigPin ως εξοδος
  pinMode(echoPin, INPUT); // Αρχικοποιει το echoPin ως εισοδος
  pinMode(buzzer, OUTPUT); //Αρχικοποιηση buzzer ως εξοδος
  pinMode(rled, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(gled, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(oled, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(led1, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(led2, OUTPUT);  //Αρχικοποιηση led ως έξοδος
  pinMode(led3, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(led4, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(led5, OUTPUT);  //Αρχικοποιηση led ως έξοδος 
  pinMode(pled,OUTPUT);   //Αρχικοποιηση led ως έξοδος
  pinMode(pled2,OUTPUT);  //Αρχικοποιηση led ως έξοδος
  pinMode(12, INPUT);     //Aισθητήρας κίνησης
  Serial.begin(9600);     //Είναι ο ρυθμός μετάδοσης σε  bits ανά δευτερόλεπτο
}

void loop()  //Κύρια επαναλαμβανόμενη συνάρτηση
{
  int value = analogRead(A0);         //Διαβάζει τη τιμή του photoresistor και τη αποθηκεύει σε μεταβλητή
  Serial.println("Analog value : ");
   Serial.println(value);
    delay(300);  //Καθυστέρηση για 30 milliseconds 
  
  do{
  if (value <= 930) //Αν η φωτεινότητα ειναι μικρότερη απο 930 τότε ανάβουν τα 5 Led (κεντρικα φωτα)
  {
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);
     digitalWrite(led3,HIGH);
     digitalWrite(led4,HIGH);
     digitalWrite(led5,HIGH); 
     delay(50);   //Καθυστέρηση για 50 milliseconds 
  }
  else  //Αν η φωτεινότητα δεν ειναι μικρότερη από 930 τοτε τα 5 Led (κεντρικα φωτα)παραμένουν κλειστά
  {
    digitalWrite(led1,LOW);   
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    digitalWrite(led5,LOW);
    delay(50);  //Καθυστέρηση για 50 milliseconds 
   }
  
  while (hour>= 6) //Οσο η ωρα είναι απο 23 εως 6 ο αισθητηρας αποστασης παραμενει ανοιχτος
  {
    digitalWrite(trigPin, LOW);// Αρχικοποίηση του trigPin ως LOW
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);// Θέτουμε το trigPin HIGH  για 10 μικροδευτερόλεπτα
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);// Διαβάζει το echoPin, επιστρέφει το χρόνο διαδρομής του ηχητικού κύματος σε μικροδευτερόλεπτα

    distance = duration * 0.034 / 2;  // Υπολογισμός της απόστασης του εισβολέα

    if (distance <= 25) //αν η αποσταση είναι  μικροτερη απο 25 τοτε αναβει το κοκκινο led
    {
      Serial.println("KATI PLHSIASE ARKETA KONTA PROSOXI !!!");
      digitalWrite(rled,HIGH);
      digitalWrite(gled,LOW); //το πρασινο και το πορτοκαλι led παραμενουν κλειστα
      digitalWrite(oled,LOW);
      tone(A4,999, 10000);  // Αποστολή  ηχητικού σήματος
      delay(1000);  //Καθυστέρηση για 1000 milliseconds 
    }
    
    else if ((distance > 25)&&(distance <= 50) ) //αν η αποσταση είναι αναμεσα απο 25 εως 50 τοτε αναβει το πορτοκαλι led
    {
      Serial.println("KATI PLISIAZEI!!");
      digitalWrite(oled,HIGH);
      digitalWrite(gled,LOW); //το πρασινο και το κοκκινο led παραμενουν κλειστα
      digitalWrite(rled,LOW);
      tone(A4,459, 10000);  // Αποστολή ηχητικού σήματος
      delay(1000);  //Καθυστέρηση για 1000 milliseconds 
    }
   
    else if (distance > 50) //αν η αποσταση είναι μεγαλυτερη απο 50 τοτε αναβει το πρασινο led
    {
      Serial.println("ENTOPISTHKE KINHSH !!");
      digitalWrite(gled,HIGH); //το κοκκινο και το πορτοκαλι led παραμενουν κλειστα
      digitalWrite(rled,LOW);
      digitalWrite(oled,LOW);
      tone(A4,1, 10000);  // Αποστολή ηχητικού σήματος
      delay(1000);  //Καθυστέρηση για 1000 milliseconds
    }
   hour --; //μειωνεται η μεταβλητη της ωρας κατα ενα
  }
    int pirsensor=LOW; //το pir γινεται low
    delay(900); //Καθυστέρηση για 900 milliseconds 
    
    if (pirsensor == LOW) //αν το pir ειναι low τοτε τα 2 led του πανεπιστημιου ειναι σβηστα
   {
     digitalWrite(pled, LOW);
     digitalWrite(pled2, LOW);
      delay(1000);  //Καθυστέρηση για 1000 milliseconds 
     pirsensor =digitalRead(12); //διαβαζει τη κατασταση του pir
   }
   if(pirsensor== HIGH ) //αν το pir ειναι high τοτε τα 2 led του πανεπιστημιου αναβουν
   {
     digitalWrite(pled, HIGH);
     digitalWrite(pled2, HIGH);
     delay(1000); //Καθυστέρηση για 1000 milliseconds 
   }
  delay(100); //Καθυστέρηση για 100 milliseconds 
  value=analogRead(A0); //Διαβάζει τη τιμή του photoresistor και τη αποθηκεύει σε μεταβλητή
  }
  while (value <=930);  //αν δεν ανιχνευτει φως απο το photoresistor τοτε τα 5 Led (κεντρικα φωτα) ειναι κλειστα
  {
     Serial.println("analog value>930 ");
     Serial.println(value);     
     delay(250); //Καθυστέρηση για 250 milliseconds 
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);
     digitalWrite(led3,LOW);
     digitalWrite(led4,LOW);
     digitalWrite(led5,LOW);
}
}
