import math

def apostasi(x, y):
    """Υπολογίζει την απόσταση ανάμεσα σε δύο σημεία."""
    return math.sqrt((x[0] - y[0]) ** 2 + (x[1] - y[1]) ** 2)

def emvado(x, y, z):
    """
    Υπολογίζει το εμβαδό τριγώνου χρησιμοποιώντας τον τύπο του Ήρωνα:
    $A = \sqrt{s(s-a)(s-b)(s-c)}$
    """
    a = apostasi(x, y)
    b = apostasi(y, z)
    c = apostasi(z, x)
    s = (a + b + c) / 2
    
    # Έλεγχος για να αποφευχθεί αρνητική τιμή κάτω από τη ρίζα λόγω στρογγυλοποίησης
    arg = s * (s - a) * (s - b) * (s - c)
    return math.sqrt(arg) if arg > 0 else 0

def egkuro_tri(a, b, c):
    """
    Ελέγχει αν τρία σημεία ορίζουν έγκυρο τρίγωνο.
    Επιστρέφει 1 αν το εμβαδόν είναι θετικό, αλλιώς -1.
    """
    return 1 if emvado(a, b, c) > 0 else -1
