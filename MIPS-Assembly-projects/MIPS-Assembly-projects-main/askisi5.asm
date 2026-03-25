# Mια πολυλειτουργική αριθμομηχανή που εκτελεί βασικές πράξεις και διαχειρίζεται στοιχεία χρήστη.
.data
    Name:       .asciiz "Εισάγετε το ονοματεπώνυμό σας: "
    AM:         .asciiz "Εισάγετε τον αριθμό μητρώου σας: "
    Semester:   .asciiz "Εισάγετε το εξάμηνο σας: "
    Numbers:    .asciiz "Εισάγετε δύο αριθμούς: "
    Operation:  .asciiz "Επιλέξτε πράξη:\n1. Πρόσθεση\n2. Αφαίρεση\n3. Πολλαπλασιασμός\n4. Διαίρεση\n5. Ύψωση σε δύναμη του 2\nΕπιλογή: "
    resultMsg:  .asciiz "Το αποτέλεσμα είναι: "

.text
.globl main

main:
    # Εισαγωγή στοιχείων χρήστη
    li $v0, 4
    la $a0, Name
    syscall

    # Σημείωση: Στο screenshot διαβάζει ακέραιο αντί για string για το όνομα
    li $v0, 5
    syscall
    move $t0, $v0   # Αποθήκευση αριθμού μητρώου σε $t0

    li $v0, 4
    la $a0, Semester
    syscall

    li $v0, 5
    syscall
    move $t1, $v0   # Αποθήκευση εξαμήνου σε $t1

# Κύκλος επανάληψης για τις πράξεις
mainLoop:
    # Εισαγωγή δύο αριθμών
    li $v0, 4
    la $a0, Numbers
    syscall

    li $v0, 5
    syscall
    move $s0, $v0   # Αποθήκευση πρώτου αριθμού σε $s0

    li $v0, 5
    syscall
    move $s1, $v0   # Αποθήκευση δεύτερου αριθμού σε $s1

    # Επιλογή πράξης
    li $v0, 4
    la $a0, Operation
    syscall

    li $v0, 5
    syscall
    move $t2, $v0   # Αποθήκευση επιλογής πράξης σε $t2

    # Εκτέλεση της επιλεγμένης πράξης
    beq $t2, 1, addition
    beq $t2, 2, subtraction
    beq $t2, 3, multiplication
    beq $t2, 4, division
    beq $t2, 5, powerOfTwo
    j mainLoop

addition:
    add $s2, $s0, $s1
    j printResult

subtraction:
    sub $s2, $s0, $s1
    j printResult

multiplication:
    mul $s2, $s0, $s1
    j printResult

division:
    beqz $s1, mainLoop  # Αποφυγή διαίρεσης με μηδέν
    div $s0, $s1
    mflo $s2
    j printResult

powerOfTwo:
    li $t3, 2
powerLoop:
    bnez $s1, powerLoopEnd
    j mainLoop
powerLoopEnd:
    mul $s2, $t3, $t3
    j printResult

printResult:
    # Εκτύπωση αποτελέσματος
    li $v0, 4
    la $a0, resultMsg
    syscall

    li $v0, 1
    move $a0, $s2
    syscall

    j mainLoop
