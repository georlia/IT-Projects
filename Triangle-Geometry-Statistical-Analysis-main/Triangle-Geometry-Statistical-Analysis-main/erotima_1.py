import utils
import random
import statistics
import itertools
count=0
simeia = []
for i in range(100):
    x = random.randint(-100, 100)
    y = random.randint(-100, 100)
    simeia.append([x, y])#λιστα με τα 100 σημεια
egkyra_trigona = []
for sindeseis in itertools.combinations(simeia, 3): #επιστρέφει ολα τα πιθανα combinations απο 3 σημεια σε μια λιστα 
    a, b, c = sindeseis
    if utils.egkuro_tri(a, b, c) > 0:
        egkyra_trigona.append([a, b, c])
areas = []
for trigono in egkyra_trigona:
    x, y, z = trigono
    em = utils.emvado(x, y, z)
    if em != 0:
        areas.append(em)
        count=count+1
mesos_oros = sum(areas) / len(areas)
mesos_timi = statistics.median(areas)
euros = max(areas) - min(areas)
print(count)#εγκυρα τριγωνα
# Εκτύπωση αποτελεσμάτων
print("Αριθμός των έγκυρων τριγώνων:", len(egkyra_trigona))
print("Μέσος όρος των εμβαδών (χειροκίνητα):", mesos_oros)
print("Διάμεσος των εμβαδών (χειροκίνητα):", mesos_timi)
print("Εύρος των εμβαδών (χειροκίνητα):", euros)

# Υπολογισμός στατιστικών με χρήση του module
mesos_oros_module = statistics.mean(areas)
mesos_timi_module = statistics.median(areas)
apoklisi_module = statistics.stdev(areas)
# Εκτύπωση αποτελεσμάτων με τη χρήση του module
print("Μέσος όρος των εμβαδών (με module):", mesos_oros_module)
print("Διάμεσος των εμβαδών (με module):", mesos_timi_module)
print("Απόκλιση των εμβαδών (με module):", apoklisi_module)
