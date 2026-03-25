# Ένας μετατροπέας βάσης αριθμών που επιτρέπει στον χρήστη να εισάγει έναν αριθμό σε δυαδική μορφή και να δει την αντίστοιχη αξία του στο δεκαδικό σύστημα.
.data
    input_buffer: .space 32
    prompt: .ascii "Enter a binary number: "
    invalid_msg: .asciiz "\nInvalid input. Please enter a valid binary number.\n"
    result_msg: .asciiz "Decimal equivalent: "

.text
.globl main

main:
    # Print prompt
    li $v0, 4
    la $a0, prompt
    syscall

    # Read string
    li $v0, 8
    la $a0, input_buffer
    li $a1, 32
    syscall

    # Το a0 περιέχει τη διεύθυνση του buffer, τη χρειαζόμαστε για το loop
    la $a0, input_buffer

convert_binary_to_decimal:
    li $t0, 0        # Initialize result (decimal) to 0

convert_loop:
    lb $t1, 0($a0)   # Load current character

    # Έλεγχος για null terminator (τέλος συμβολοσειράς)
    beqz $t1, print_result
    
    # Έλεγχος για χαρακτήρα αλλαγής γραμμής '\n' (ASCII 10) που προσθέτει η syscall 8
    li $t2, 10
    beq $t1, $t2, print_result

    # Check if the character is '0' or '1'
    li $t2, '0'
    sub $t1, $t1, $t2     # Μετατροπή ASCII σε ακέραιο (π.χ. '1' -> 1)
    
    # Αν το αποτέλεσμα δεν είναι 0 ή 1, το input είναι άκυρο
    bltz $t1, invalid_input
    li $t2, 1
    bgt $t1, $t2, invalid_input

    # Multiply current result by 2 (Shift left)
    mul $t0, $t0, 2

    # Add current digit to result
    add $t0, $t0, $t1

    # Move to the next character
    addi $a0, $a0, 1
    j convert_loop

invalid_input:
    # Print invalid input message
    li $v0, 4
    la $a0, invalid_msg
    syscall
    
    j main           # Return to main to get a new input

print_result:
    # Print result message
    li $v0, 4
    la $a0, result_msg
    syscall

    # Print decimal result
    li $v0, 1
    move $a0, $t0
    syscall

    # Exit program
    li $v0, 10
    syscall

# "1. Να αναφέρετε και να εξηγήσετε το “προγραμματιστικό μπλοκ (σύνολο εντολών)” που απαιτείται, για να στείλετε μηνύματα στην κονσόλα – χρήστη."
# Στο πρόγραμμα, το μήνυμα αποθηκεύεται στην ενότητα δεδομένων (.data) και στη συνέχεια εκτυπώνεται στην κονσόλα χρησιμοποιώντας τη συνάρτηση εκτύπωσης (syscall). Τέλος, το πρόγραμμα τερματίζεται με την εντολή syscall .

# "2. Να αναφέρετε το “προγραμματιστικό μπλοκ” που απαιτείται, για να εισάγετε δεδομένα από το πληκτρολόγιο -χρήστη."
# Για να εισαγάγετε δεδομένα από το πληκτρολόγιο ή το χρήστη χρησιμοποιείτε τη εντολή  syscall. Για την είσοδο δεδομένων από το πληκτρολόγιο, χρησιμοποιείται ο κατάλογος 5 (για integers) ή 8 (για strings).

# "3. Μόλις ανακτηθούν τα δεδομένα από το πληκτρολόγιο, που τοποθετούνται; "
# Όταν ανακτώνται τα δεδομένα από το πληκτρολόγιο συνήθως τοποθετούνται σε μια προκαθορισμένη θέση μνήμης, buffer . 

# "4. Όταν θέλουμε να εμφανίσουμε δεδομένα που τοποθετούνται;"
# Μέσα στο τμήμα κώδικα (.text) όπου βρίσκονται οι εντολές εκτέλεσης. 
