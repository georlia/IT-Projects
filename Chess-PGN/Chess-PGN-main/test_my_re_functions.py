import unittest
import my_re_functions

class TestChessFunctions(unittest.TestCase):
    """Κλάση για τον έλεγχο των συναρτήσεων επεξεργασίας PGN"""

    def setUp(self):
        """Προετοιμασία δεδομένων για τις δοκιμές"""
        self.sample_game = (
            '[Event "WCh 2023"]\n'
            '[Date "2023.04.09"]\n'
            '[Result "1/2-1/2"]\n'
            '[WhiteElo "2795"]\n'
            '[BlackElo "2788"]\n\n'
            '1.e4 e5 2.Nf3 Nc6 3.Bb5 a6 4.Ba4 Nf6 5.O-O 49.Ke3 1/2-1/2'
        )

    def test_result(self):
        """Έλεγχος επιστροφής αποτελέσματος"""
        self.assertEqual(my_re_functions.result(self.sample_game), "ΙΣΟΠΑΛΙΑ")

    def test_elodifr(self):
        """Έλεγχος υπολογισμού διαφοράς Elo"""
        self.assertEqual(my_re_functions.elodifr(self.sample_game), 7)

    def test_get_date(self):
        """Έλεγχος μορφής ημερομηνίας (ΗΗ-ΜΜ-ΕΕΕΕ)"""
        self.assertEqual(my_re_functions.get_date(self.sample_game), "09-04-2023")

    def test_plithosk(self):
        """Έλεγχος καταμέτρησης κινήσεων"""
        self.assertEqual(my_re_functions.plithosk(self.sample_game), 49)

if __name__ == '__main__':
    unittest.main()
