import calendar
from datetime import datetime

import chess.pgn
import matplotlib.pyplot as plt

import my_re_functions

def create_histogram():
    """
    Διαβάζει το αρχείο Retikia.pgn, υπολογίζει τις ημέρες της εβδομάδας
    και εμφανίζει το αντίστοιχο ιστόγραμμα.
    """
    # Αρχικοποίηση μετρητών για κάθε ημέρα (0=Δευτέρα, 6=Κυριακή)
    day_counts = [0] * 7
    
    try:
        with open("Retikia.pgn", "r") as games_file:
            print("Ανάγνωση παρτίδων... Παρακαλώ περιμένετε.")
            
            while True:
                game = chess.pgn.read_game(games_file)
                if game is None:
                    break
                
                game_str = str(game)
                game_date = my_re_functions.get_date(game_str)
                
                if game_date:
                    try:
                        # Χρήση της νέας μορφής DD-MM-YYYY που επιστρέφει η my_re_functions
                        date_obj = datetime.strptime(game_date, "%d-%m-%Y")
                        day_index = date_obj.weekday()  # Επιστρέφει 0 για Monday, 6 για Sunday
                        day_counts[day_index] += 1
                    except ValueError:
                        # Προσπέραση αν η ημερομηνία δεν είναι έγκυρη (π.χ. 31 Φεβρουαρίου)
                        continue
                        
    except FileNotFoundError:
        print("Σφάλμα: Το αρχείο Retikia.pgn δεν βρέθηκε.")
        return

    # Σχεδίαση γραφήματος με matplotlib
    days_labels = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
    
    plt.figure(figsize=(10, 6))
    plt.bar(days_labels, day_counts, color='skyblue', edgecolor='navy')
    plt.xlabel("Ημέρες της Εβδομάδας")
    plt.ylabel("Πλήθος Παιχνιδιών")
    plt.title("Παρτίδες ανά Ημέρα (Reti & KIA Openings)")
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    plt.show()

if __name__ == "__main__":
    create_histogram()
