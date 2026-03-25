# ♟️Chess PGN Analyzer
Αυτό το project εστιάζει στην ανάλυση αρχείων σκακιού μορφής **PGN (Portable Game Notation)** χρησιμοποιώντας Regular Expressions

Χαρακτηριστικά
---
* **Ανάλυση Παρτίδας**: Εξαγωγή νικητή, ημερομηνίας και πλήθους κινήσεων
* **Υπολογισμός Elo**: Εύρεση της διαφοράς δυναμικότητας των αντιπάλων
* **Στατιστική Οπτικοποίηση**: Δημιουργία ιστογράμματος με τη χρήση της βιβλιοθήκης matplotlib για την εμφάνιση των παρτίδων ανά ημέρα της εβδομάδας
* **Unit Testing**: Πλήρης έλεγχος των συναρτήσεων με τη βιβλιοθήκη unittest

Τεχνολογίες & Εργαλεία
---
* **Python 3.x**
* **Libraries**: re, python-chess, matplotlib
* **Code Quality**: Χρήση των black και isort για τη μορφοποίηση του κώδικα

Δομή Αρχείων
---
* [my_re_functions.py](my_re_functions.py): Οι βασικές συναρτήσεις επεξεργασίας κειμένου
* [erotima1.py](erotima1.py): Script για την επεξεργασία αρχείων PGN μέσω γραμμής εντολών
* [erotima2.py](erotima2.py): Παραγωγή γραφημάτων για στατιστική ανάλυση
* [test_my_re_functions.py](test_my_re_functions.py): Unit tests για την επαλήθευση της ορθότητας
* [WorldChamp2023.pgn](WorldChamp2023.pgn): Περιέχει τις παρτίδες από το Παγκόσμιο Πρωτάθλημα Σκακιού 2023
* [RetiKIA.zip](RetiKIA.zip): Ένα συμπιεσμένο αρχείο που περιέχει συνολικά 54.727 παρτίδες σκακιού

Οδηγίες Εγκατάστασης:
---
1. Δημιουργία εικονικού περιβάλλοντος (virtual environment):
   python -m venv venv

2. Ενεργοποίηση εικονικού περιβάλλοντος:
   - Windows: venv\Scripts\activate
   - Linux/Mac: source venv/bin/activate

3. Εγκατάσταση απαραίτητων βιβλιοθηκών:
   pip install python-chess matplotlib

Οδηγίες Εκτέλεσης:
---
1. Εκτέλεση Unit Tests:
   python test_my_re_functions.py

2. Εκτέλεση Ερωτήματος 1 (Απαιτείται το αρχείο .pgn ως όρισμα):
   python erotima1.py WorldChamp2023.pgn

3. Εκτέλεση Ερωτήματος 2 (Απαιτείται το αρχείο Retikia.pgn στον ίδιο φάκελο):
   python erotima2.py

