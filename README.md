Prowadzimy niewielkie przedsiębiorstwo. Nasi pracownicy mają konta bankowe w trzech bankach
internetowych: iPKO, mBank i AliorBank o numerach odpowiednio 1020, 1140 i 2490.
Dany jest plik tekstowy o nazwie podawanej przez użytkownika i nieznanej z góry liczbie wierszy.
Każdy wiersz zawiera wyłącznie numer rachunku bankowego jednego pracownika w formacie
IBAN (opisanym dokładnie niżej).

Księgowa oczekuje list zawierających numery IBAN pracowników (po jednym w każdym wierszu),
osobnych dla każdego banku. Numery kont powinny być posortowane alfanumerycznie. Pliki
wyjściowe (o ile trzeba je tworzyć) powinny się nazywać 1020.txt, 1140.txt i 2490.txt.
Niedozwolone jest korzystanie z kontenerów i algorytmów z biblioteki standardowej C++. Można
stworzyć bibliotekę z abstrakcyjnym typem danych, który pomoże w rozwiązaniu zadania. Można
w bibliotece (niekoniecznie tej samej) umieścić potrzebne struktury/funkcje działające na liczbach i
łańcuchach znaków. W bibliotekach nie wolno umieszczać żadnych operacji działających na
plikach. Zapisu do plików wynikowych nie wolno rozpocząć przed odczytaniem całości pliku
wejściowego.

Poprawne rozwiązanie będzie ocenione jako przynajmniej dostateczne. Rozwiązanie dobre
powinno zawierać obsługę wejścia odporną na błędy użytkownika, a na bardzo dobrą również
poprawne komentarze, w tym w bibliotekach pomocniczych: cel funkcji, warunki wstępne, warunki
końcowe, sytuacje wyjątkowe i ewentualnie zwracany wynik. Na ocenę dostateczną jako
poprawny traktowany jest numer IBAN będący ciągiem znaków złożonym z napisu „PL” i
następujących po nim 26 cyfr. Na ocenę dobrą należy zweryfikować dodatkowo poprawność
oddziału banku, a na bardzo dobrą - poprawność całego numeru IBAN. Programy na ocenę
przynajmniej dobrą powinny obsługiwać nieograniczoną liczbę numerów IBAN zapisanych w
pliku wejściowym.
