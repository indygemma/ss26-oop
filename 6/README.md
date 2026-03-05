# Tierheim-Zählung
### Ein Verwaltungssystem mit `static` und Vererbung

*C++ Programmierung | Praktische Übung — Thema: Static-Variablen & Vererbung | Bearbeitungszeit: ca. 60 Minuten*

---

## Lernziele

Nach dieser Übung können Sie:

- `static`-Membervariablen in einer Klassenhierarchie einsetzen
- Den Unterschied zwischen `static`-Variablen der Basis- und der abgeleiteten Klasse erklären
- Konstruktoren und Destruktoren zum Zählen von Objekten verwenden
- Eine `static`-Methode schreiben, die klassenübergreifende Informationen ausgibt

---

## Szenario

Sie entwickeln ein einfaches Verwaltungssystem für ein Tierheim. Das System soll jederzeit wissen, wie viele Tiere insgesamt und wie viele Tiere pro Tierart im Heim untergebracht sind — ohne dass man dafür alle Objekte manuell durchzählen muss.

---

## Klassenstruktur

Erstellen Sie folgende Klassen:

| Klasse | Beschreibung |
|---|---|
| `Animal` (Basis) | Enthält `static int totalAnimals` sowie `static void census()` |
| `Dog : Animal` | Enthält `static int dogCount` |
| `Cat : Animal` | Enthält `static int catCount` |
| `Bird : Animal` | Enthält `static int birdCount` |

---

## Aufgaben

### Aufgabe 1 — Basisklasse `Animal`

Erstellen Sie die Klasse `Animal` mit folgenden Eigenschaften:

- Ein `private`-Attribut: `string name` (Name des Tieres)
- Eine `static int totalAnimals` (zählt alle Tiere, egal welcher Art)
- Konstruktor: erhöht `totalAnimals` um 1 und gibt eine Meldung aus
- Destruktor: verringert `totalAnimals` um 1 und gibt eine Meldung aus
- Eine `static void census()` Methode — vorerst leer lassen
- Einen Getter `getName()` sowie eine virtuelle Methode `getType()`

> **Hinweis: Definition außerhalb der Klasse**
> `static`-Membervariablen müssen außerhalb der Klasse definiert werden, z. B.:
> `int Animal::totalAnimals = 0;` — sonst gibt es einen Linker-Fehler!

---

### Aufgabe 2 — Abgeleitete Klassen

Erstellen Sie die drei Unterklassen `Dog`, `Cat` und `Bird`. Jede Klasse soll:

- Von `Animal` erben
- Eine eigene `static int` (z. B. `dogCount`) besitzen
- Im Konstruktor: eigenen Zähler erhöhen und den Eltern-Konstruktor aufrufen
- Im Destruktor: eigenen Zähler verringern
- `getType()` überschreiben und den Tiernamen als String zurückgeben (`"Hund"`, `"Katze"`, `"Vogel"`)

> **Wichtige Frage zum Nachdenken**
> Warum teilen sich `Dog`, `Cat` und `Bird` **nicht** den `static`-Zähler von `Animal`?
> Was passiert, wenn Sie in einer Unterklasse auf `Animal::totalAnimals` zugreifen?

---

### Aufgabe 3 — `census()` Methode

Implementieren Sie die Methode `static void census()` in der Klasse `Animal`. Die Ausgabe soll so aussehen:

```
=== Tierheim-Zählung ===
Hunde:  3
Katzen: 1
Vögel:  2
Gesamt: 6
```

> **Hinweis**
> `census()` ist eine `static`-Methode in `Animal`. Sie kann trotzdem auf `Dog::dogCount`,
> `Cat::catCount` und `Bird::birdCount` zugreifen, weil es sich um `public static`-Member handelt.

---

### Aufgabe 4 — Testen mit `main.cpp`

Die folgende `main.cpp` ist bereits vorgegeben. Ihre Aufgabe ist es, die Klassen so zu implementieren, dass alle `assert`-Prüfungen bestehen und das Programm fehlerfrei durchläuft.

> **Was ist `assert()`?**
> `assert(bedingung)` aus `<cassert>` prüft zur Laufzeit, ob eine Bedingung wahr ist.
> Ist sie falsch, bricht das Programm sofort mit einer Fehlermeldung ab. So können Sie
> sicherstellen, dass Ihre Zähler korrekt funktionieren.

```cpp
#include <cassert>
#include <iostream>
#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"

int main() {
    // Zu Beginn sind keine Tiere vorhanden
    assert(Animal::totalAnimals == 0);
    assert(Dog::dogCount        == 0);
    assert(Cat::catCount        == 0);
    assert(Bird::birdCount      == 0);

    // Tiere aufnehmen
    Dog  d1("Bello");
    Dog  d2("Max");
    Dog  d3("Bruno");
    Cat  c1("Mimi");
    Bird b1("Tweety");
    Bird b2("Fips");

    // Zähler nach der Aufnahme prüfen
    assert(Animal::totalAnimals == 6);
    assert(Dog::dogCount        == 3);
    assert(Cat::catCount        == 1);
    assert(Bird::birdCount      == 2);

    Animal::census();   // Erste Ausgabe

    // Einige Tiere in einem inneren Block anlegen
    {
        Dog  d4("Rex");
        Cat  c2("Luna");
        assert(Animal::totalAnimals == 8);
        assert(Dog::dogCount        == 4);
        assert(Cat::catCount        == 2);
    }   // d4 und c2 werden hier automatisch zerstört

    // Nach dem Block müssen die Zähler wieder stimmen
    assert(Animal::totalAnimals == 6);
    assert(Dog::dogCount        == 3);
    assert(Cat::catCount        == 1);

    Animal::census();   // Zweite Ausgabe — gleich wie die erste

    // getType() prüfen
    assert(d1.getType() == "Hund");
    assert(c1.getType() == "Katze");
    assert(b1.getType() == "Vogel");

    std::cout << "Alle Tests bestanden!" << std::endl;
    return 0;
}
```

---

## Erwartete Konsolenausgabe

Wenn Ihre Implementierung korrekt ist, sieht die Ausgabe des Programms in etwa so aus:

```
Hund 'Bello' wurde aufgenommen.
Hund 'Max' wurde aufgenommen.
Hund 'Bruno' wurde aufgenommen.
Katze 'Mimi' wurde aufgenommen.
Vogel 'Tweety' wurde aufgenommen.
Vogel 'Fips' wurde aufgenommen.

=== Tierheim-Zählung ===
Hunde:  3
Katzen: 1
Vögel:  2
Gesamt: 6

Hund 'Rex' wurde aufgenommen.
Katze 'Luna' wurde aufgenommen.
Katze 'Luna' hat das Heim verlassen.
Hund 'Rex' hat das Heim verlassen.

=== Tierheim-Zählung ===
Hunde:  3
Katzen: 1
Vögel:  2
Gesamt: 6

Alle Tests bestanden!
```

---

## Bonusaufgabe (optional)

**Eindeutige Tier-ID** — Fügen Sie in `Animal` eine `static int nextId` hinzu. Jedes neue Tier bekommt im Konstruktor automatisch eine aufsteigende ID zugewiesen (1, 2, 3, ...). Erweitern Sie die `assert`-Tests entsprechend.

---

## Checkliste

- [ ] Kompiliert das Programm ohne Warnungen?
- [ ] Laufen alle `assert`-Prüfungen fehlerfrei durch?
- [ ] Werden die Zähler beim Zerstören von Objekten korrekt verringert?
- [ ] Ist `totalAnimals` immer die Summe der einzelnen Zähler?
- [ ] Haben Sie die `static`-Member außerhalb der Klasse definiert?
- [ ] Können Sie erklären, warum jede Klasse ihren eigenen `static`-Zähler benötigt?

---

*Viel Erfolg!*
