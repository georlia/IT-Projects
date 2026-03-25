import re
import sys  
import chess.pgn
from datetime import datetime
import my_re_functions 

# Έλεγχος αν δόθηκε όνομα αρχείου στη γραμμή εντολών 
if len(sys.argv) < 2:
    print("Usage: python erotima1.py <filename.pgn>")
    sys.exit(1)

# Χρήση του ορίσματος sys.argv[1] αντί για σταθερό όνομα αρχείου 
filename = sys.argv[1]
fakelos = open(filename, "r")

while True: 
    game = chess.pgn.read_game(fakelos) 
    if game is None: 
        break 
    else: 
        game_str = str(game) 
        
        # Κλήση συναρτήσεων και αποθήκευση αποτελεσμάτων 
        winner = my_re_functions.result(game_str) 
        date = my_re_functions.get_date(game_str)
        elo_diff = my_re_functions.elodifr(game_str)
        moves = my_re_functions.plithosk(game_str)

        # Εμφάνιση αποτελεσμάτων για κάθε παρτίδα 
        print("-" * 30)
        print(f"Νικητής: {winner}")
        print(f"Ημερομηνία: {date}")
        print(f"Διαφορά Elo: {elo_diff}")
        print(f"Πλήθος κινήσεων: {moves}")

fakelos.close()
