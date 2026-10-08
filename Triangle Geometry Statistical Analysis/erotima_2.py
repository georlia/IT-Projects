import itertools
import statistics
from unittest import TestCase
import utils

class TestEmvadon(TestCase):
    def setUp(self):
        """Προετοιμασία δεδομένων και υπολογισμός εμβαδών από το points.txt."""
        self.points = []
        try:
            with open("points.txt", 'r') as file:
                for line in file:
                    # Μετατροπή κάθε γραμμής σε συντεταγμένες [x, y]
                    coords = list(map(int, line.split()))
                    if len(coords) == 2:
                        self.points.append(coords)
        except FileNotFoundError:
            self.fail("Το αρχείο points.txt δεν βρέθηκε!")

        # Εύρεση όλων των έγκυρων τριγώνων και των εμβαδών τους
        self.valid_trigona_count = 0
        self.emvada = []
        
        combinations = itertools.combinations(self.points, 3)
        for a, b, c in combinations:
            if utils.egkuro_tri(a, b, c) > 0:
                self.valid_trigona_count += 1
                self.emvada.append(utils.emvado(a, b, c))

    def test_statistics(self):
        """Επαλήθευση των στατιστικών αποτελεσμάτων με τις αναμενόμενες τιμές."""
        # 1. Έλεγχος πλήθους τριγώνων
        self.assertEqual(161673, self.valid_trigona_count, msg="Ο αριθμός τριγώνων δεν ταιριάζει")

        # 2. Έλεγχος Μέσου Όρου
        mean_val = statistics.mean(self.emvada)
        self.assertAlmostEqual(3206.82, mean_val, places=2, msg="Το μέσο εμβαδόν δεν ταιριάζει")

        # 3. Έλεγχος Διαμέσου (Χρήση statistics.median)
        median_val = statistics.median(self.emvada)
        self.assertAlmostEqual(2392.50, median_val, places=2, msg="Η διάμεσος δεν ταιριάζει")

        # 4. Έλεγχος Τυπικής Απόκλισης
        stdev_val = statistics.stdev(self.emvada)
        self.assertAlmostEqual(2843.24, stdev_val, places=2, msg="Η τυπική απόκλιση δεν ταιριάζει")
