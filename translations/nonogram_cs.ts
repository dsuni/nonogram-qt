<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.0" language="cs_CZ">
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../mainwindow.cpp" line="6"/>
        <source>&amp;File</source>
        <translation>&amp;Soubor</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="7"/>
        <location filename="../mainwindow.cpp" line="12"/>
        <source>&amp;Help</source>
        <translation>&amp;Nápověda</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="10"/>
        <source>E&amp;xit</source>
        <translation>&amp;Ukončit</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="14"/>
        <source>&amp;About</source>
        <translation>&amp;O programu</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="32"/>
        <source>Columns:</source>
        <translation>Sloupce:</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="33"/>
        <source>Rows:</source>
        <translation>Řádky:</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="34"/>
        <source>Generate puzzle</source>
        <translation>Vytvořit hlavolam</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="36"/>
        <source>Give up</source>
        <translation>Vzdát se</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="272"/>
        <source>Well done</source>
        <translation>Dobrá práce. Výborně</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="273"/>
        <source>You have solved the puzzle!</source>
        <translation>Rozluštil jste hlavolam!</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="283"/>
        <source>About</source>
        <translation>O programu</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="284"/>
        <source>&lt;p&gt;&lt;h3&gt;Nonogram-qt 1.1.1&lt;/h3&gt;&lt;/p&gt;&lt;p&gt;Copyright: Daniel Suni, 2012, 2013, 2018&lt;/p&gt;&lt;p&gt;Distributed under the GNU GPL v3&lt;/p&gt;</source>
        <translation>&lt;p&gt;&lt;h3&gt;Nonogram-qt 1.1.1&lt;/h3&gt;&lt;/p&gt;&lt;p&gt;Autorské právo: Daniel Suni, 2012, 2013, 2018&lt;/p&gt;&lt;p&gt;Šířeno pod licencí GNU GPL v3&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="290"/>
        <source>Help</source>
        <translation>Nápověda</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="292"/>
        <source>&lt;h2&gt;What are nonograms?&lt;/h2&gt;&lt;p&gt;Nonograms are logic puzzles consisting of a rectangular grid divided into cells. These cells can be either&lt;br&gt;colored (solids) or blank (dots). At the start of the game all cells are blank, and the purpose of the game is&lt;br&gt;to figure out which ones should be colored.&lt;/p&gt;&lt;p&gt;Each row and column in the grid is fitted with a clue consisting of a series of numbers. These numbers reveal&lt;br&gt;how many solids there are on the row/column as well as something about their grouping. If e.g. the clue is&lt;br&gt;(3 1 2) we know that from left to right there is first a series of 3 consequtive solids, then X number of blanks,&lt;br&gt;where X &gt;= 1, then a single solid, then another unspecified number of blanks, and finally 2 consequtive solids.&lt;br&gt;If the row was 10 cells long, one possible arrangement would be (-###-#--##), another one would be (###-#-##--).&lt;br&gt;Since there are rules for both rows and columns, only one arrangement is actually correct, though. The puzzle is&lt;br&gt;to find the arrangement that conforms to all the given clues.&lt;/p&gt;&lt;h2&gt;How to play&lt;/h2&gt;&lt;p&gt;In order to start a new game, please select the size of the desired playing field, and click the &amp;quot;Generate puzzle&amp;quot;&lt;br&gt;button. Generating the puzzle can take a few seconds - especially if it&apos;s a big one, so please be patient.&lt;/p&gt;&lt;p&gt;When starting all cells are blank. You can mark a cell as a solid by clicking on it. You can also mark larger areas&lt;br&gt;by dragging the mouse with the button pressed. If you&apos;ve made a mistake, just click the cell again to revert it to a&lt;br&gt;dot. You can also mark known dots by right clicking (and dragging). This will be shown by an &apos;X&apos; appearing in that&lt;br&gt;cell. Notice that you don&apos;t need to explicitly mark the dots in order to solve the puzzle. That functionality only&lt;br&gt;exists for your own convenience.&lt;/p&gt;&lt;p&gt;Every time you make a move the computer will automatically check whether you&apos;ve successfully solved the puzzle&lt;br&gt; or not. Once the puzzle is solved, you will immediately be informed. If the puzzle turns out to be too hard, you can&lt;br&gt;end it, and look at the solution by pressing the &amp;quot;Give up&amp;quot; button. Remaining solids will be displayed in&lt;br&gt;grey, and possible mistakes (i.e. dots marked as solids) will be displayed in red.&lt;/p&gt;</source>
        <translation>&lt;h2&gt;Co jsou malované křížovky (zakódované obrázky)?&lt;/h2&gt;&lt;p&gt;Malované křížovky jsou logický hlavolam (sestávající z obdélníkové mřížky rozdělené do buněk), při kterém je okolo mřížky umístěná legenda s čísly a pomocí nich lze získat obrázek. Každé číslo v legendě určuje počet za sebou následujících čtverečků stejné barvy. Buňky mohou být buď&lt;br&gt;obarvené (jednobarevné - čtverečky stejné barvy) nebo prázdné (tečky). Na začátku hry jsou všechny buňky prázdné, a účelem hry je &lt;br&gt;přijít na to, které čtverečky mají být barevné.&lt;/p&gt;&lt;p&gt;Každý řádek a sloupec v mřížce je opatřen nápovědou skládající se z řady čísel. Tato čísla odhalují &lt;br&gt;kolik čtverečků stejné barvy je v řádku/sloupci a také něco o jejich seskupování. Pokud je nápověda např. &lt;br&gt;(3 1 2), víme, že zleva doprava je nejprve řada 3 následných čtverečků stejné barvy, potom počet X prázdných,&lt;br&gt;kde X &gt;= 1, pak jeden čtvereček stejné barvy, potom další neurčitý počet prázdných čtverečků, a nakonec 2 následné čtverečky stejné barvy.&lt;br&gt;Pokud byl řádek dlouhý 10 buněk, jedno možné uspořádání je (-###-#--##), jiné by bylo (###-#-##--).&lt;br&gt;Protože jsou přítomna pravidla jak pro řádky tak pro sloupce, ve skutečnosti je správné jen jedno uspořádání. Hlavolam je o&lt;br&gt;nalezení uspořádání, jež vyhovuje všem daným nápovědám.&lt;/p&gt;&lt;h2&gt;Jak hrát&lt;/h2&gt;&lt;p&gt;Pro započetí nové hry, prosím, vyberte požadovanou velikost herního pole, a klepněte na tlačítko &amp;quot;Vytvořit hlavolam&amp;quot;&lt;br&gt;. Vytváření hlavolamu může trvat několik sekund - zvláště, kdy je to velký hlavolam, takže buďte, prosím, trpělivý.&lt;/p&gt;&lt;p&gt;Na začátku jsou všechny buňky prázdné. Buňku označíte jako jednobarevný čtvereček, tím že na ni klepnete. Rovněž můžete označit větší oblasti&lt;br&gt;, tím že táhnete myší za současného stisknutí a držení tlačítka. Pokud jste se zmýlil, jednoduše na buňku klepněte znovu, čímž ji vrátíte na&lt;br&gt;tečku. Také můžete označit známé tečky klepnutím pravým tlačítkem m (a tažením). To se ukáže jako &apos;X, které se objeví v té&lt;br&gt;buňce. Všimněte si, že nemusíte přímo označit tečky, abyste hlavolam vyluštil. Tato funkčnost&lt;br&gt;existuje jen pro vaše vlastní pohodlí.&lt;/p&gt;&lt;p&gt;Pokaždé, když provedete tah, počítač automaticky ověří, zda jste hlavolam řešil úspěšně&lt;br&gt; či ne. Jakmile je hlavolam rozluštěn, dostanete o tom okamžitě zprávu. Pokud se stane, že pro vás havolam bude příliš těžký, můžete jej&lt;br&gt;ukončit a podívat se na řešení, tím že stisknete tlačítko&amp;quot;Vzdát se&amp;quot;. Zbývající čtverečky budou zobrazeny&lt;br&gt;šedě, a možné omyly (to znamená tečky označené jako čtverečky o stejné barvě) budou zobrazeny červeně.&lt;/p&gt;</translation>
    </message>
</context>
</TS>
