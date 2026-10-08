import math

def get_color_distance(rgb1, rgb2):
    """
    Υπολογίζει την Ευκλείδεια απόσταση μεταξύ δύο χρωμάτων RGB.
    rgb1, rgb2: tuples της μορφής (r, g, b)
    """
    r1, g1, b1 = rgb1
    r2, g2, b2 = rgb2
    
    # Τύπος Ευκλείδειας απόστασης: $d = \sqrt{(r_1-r_2)^2 + (g_1-g_2)^2 + (b_1-b_2)^2}$
    distance = math.sqrt((r1 - r2)**2 + (g1 - g2)**2 + (b1 - b2)**2)
    return distance

def get_score(distance):
    """
    Μετατρέπει την απόσταση σε ποσοστό επιτυχίας (%).
    Η μέγιστη δυνατή απόσταση είναι $\sqrt{255^2 + 255^2 + 255^2} \approx 441.67$.
    """
    max_distance = math.sqrt(3 * (255**2))
    score = (1 - (distance / max_distance)) * 100
    return round(score, 2)
