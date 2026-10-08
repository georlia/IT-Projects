import re

def result(strng):
    """
    Επιστρέφει το χρώμα του νικητή της παρτίδας: ΛΕΥΚΑ, ΜΑΥΡΑ ή ΙΣΟΠΑΛΙΑ
    """
    match = re.search(r'\[Result\s+"(.*?)"\]', strng)
    if match:
        res = match.group(1)
        if res == "1-0":
            return "ΛΕΥΚΑ"
        elif res == "0-1":
            return "ΜΑΥΡΑ"
        elif res == "1/2-1/2":
            return "ΙΣΟΠΑΛΙΑ"
    return "ΑΓΝΩΣΤΟ"

def elodifr(game):
    """
    Υπολογίζει και επιστρέφει τη διαφορά δυναμικότητας των δύο αντιπάλων
    """
    white_elo = re.search(r'\[WhiteElo\s+"(\d+)"\]', game)
    black_elo = re.search(r'\[BlackElo\s+"(\d+)"\]', game)
    if white_elo and black_elo:
        diff = abs(int(white_elo.group(1)) - int(black_elo.group(1)))
        return diff
    return 0

def get_date(game):
    """
    Επιστρέφει την ημερομηνία της παρτίδας στη μορφή ΗΗ-ΜΜ-ΕΕΕΕ
    """
    # Αναζήτηση της ημερομηνίας YYYY.MM.DD στο PGN
    match = re.search(r'\[Date\s+"(\d{4})\.(\d{2})\.(\d{2})"\]', game)
    if match:
        # Μετατροπή σε DD-MM-YYYY όπως ζητάει η εκφώνηση
        return f"{match.group(3)}-{match.group(2)}-{match.group(1)}"
    return None

def plithosk(game):
    """
    Επιστρέφει το πλήθος των κινήσεων της παρτίδας
    """
    # Εντοπισμός του αριθμού της τελευταίας κίνησης
    matches = re.findall(r'(\d+)\.', game)
    if matches:
        return int(matches[-1])
    return 0
