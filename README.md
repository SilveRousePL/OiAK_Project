# OiAK_Project

<pre>Wyrażenia arytmetyczne
+ - operator dodawania / alternatywy
- - operator odejmowania
* - operator mnożenia / koniunkcji
/ - operator dzielenia
% - operator modulo
= - operator przypisania
? - operator czy równe
! - operator czy nierówne
() - nawiasy

Słowa kluczowe:
skip - pominięcie / pusta instrukcja
cwrite *tekst* - wypisanie tekstu lub liczby
vwrite *zmienna* - wypisanie zawartości zmiennej
read *zmienna* - odczyt z klawiatury do zmiennej

if *wyrażenie* 
	*instrukcja lub blok* 
else 
	*instrukcja lub blok*
		- jeśli wyrażenie jest prawdziwe to wykonuje instrukcję lub blok instrukcji po słowie "if", jeśli wyrażenie jest fałszywe, wykonuje instrukcję lub blok instrukcji po słowie "else"

while *wyrażenie*
	*instrukcja lub blok*
		- wykonuje instrukcję lub blok instrukcji tak długo dopóki wyrażenie jest prawdziwe

Operator przypisania oraz zmienne:
*nazwa zmiennej* = *wartość*. Zmienne wykorzystywane przez interpreter to są 64-bitowe liczby całkowite ze znakiem (int64_t).

Funkcja "cwrite":
Wypisuje ciąg znaków alfanumerycznych znajdujących się po tej instrukcji. Możliwe jest wypisanie znaków specjalnych tj:
	- spacja "\s"
	- tabulacja "\t"
	- znak nowej linii "\n"

Funkcja "vwrite":
Wypisuje zawartość zmiennej o nazwie podanej po tej instrukcji

Funkcja "read":
Prosi użytkownika o wpisanie liczby. Wpisana liczba jest nastepnie zapisywana do zmiennej o nazwie podanej po tej instrukcji

Bloki instrukcji:
Instrukcje można grupować w bloki {}. Dzięki temu można wykonywać wiele instrukcji w ramach jednego warunku lub pętli.

</pre>

http://informatyka.wroc.pl/node/391
