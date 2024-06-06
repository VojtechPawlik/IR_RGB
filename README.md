# IR_RGB

Tento projekt umožňuje ovládat intenzitu tří LED diod (červené, zelené a modré) pomocí IR dálkového ovladače. 
Každá LED dioda se nastavuje pomocí sekvence čísel zadaných na dálkovém ovladači, přičemž každé stisknutí klávesy ENTER (EQ) přepíná na další LED diodu.
Použití:

Zapněte Serial Monitor pro sledování výstupů.
Pomocí dálkového ovládání zadejte hodnoty (0-255) pro jednotlivé LED diody v následujícím pořadí:
První hodnota nastaví jas červené LED.
Druhá hodnota nastaví jas zelené LED.
Třetí hodnota nastaví jas modré LED.
Pro zadání hodnot:
Stiskněte tlačítka na dálkovém ovládání odpovídající číslům (0-9).
Každý stisk tlačítka zobrazí aktuální stav zadávaného čísla v Serial Monitoru.
Po zadání čísla stiskněte tlačítko ENTER (EQ) na dálkovém ovládání, aby se hodnota nastavila na aktuální LED.
Po nastavení modré LED (třetí hodnoty) se cyklus opakuje a můžete zadávat hodnoty znovu od červené LED.
Příklad:

Chcete nastavit červenou LED na hodnotu 150, zelenou LED na hodnotu 100 a modrou LED na hodnotu 200.
Stiskněte tlačítka: 1, 5, 0 (červená LED), ENTER (EQ).
Stiskněte tlačítka: 1, 0, 0 (zelená LED), ENTER (EQ).
Stiskněte tlačítka: 2, 0, 0 (modrá LED), ENTER (EQ).
