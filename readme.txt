# Assignement 2 - PG3400
Programmet starter, tar så ett mappenavn som input, scanner mappen og merger filene i mappen til ett ascii-art. 
Programmets main ligger i artMerger.c, det er denne filen som kontrollerer programmet og kaller andre filer. 

Programmets flyt: 
Først tas input fra bruker inn, dette er mappen bruker ønsker skal merges. Så opprettes ett array for filer og man blir sent til fileFinder.c sin metode findTxtFiles. Den leter igjennom mappen etter filer som slutter på .txt, finner den ingen avsluttes programmet her, viss ikke returneres antall filer funnet.
Når det er gjort, tar programmet og kjører sortWords() metoden i wordSorter.c. Denne metoden sorterer filnavnene så de blir lest i riktig rekkefølge senere. 
Til slutt kjøres mergeFiles() i fileMerger.c. Dette er hvor hovedarbeidet blir gjort med å åpne for lesing av alle txt filene og skriving til output fil. Når alt er åpnet kjøres 3 for-løkker inne i hverandre, en for høyde, en for antall linjer og en for bredde. For vær bredde skrives det fra input fil til output fil og for vær linje skrives en new line. 
Til slutt skrives det ut til konsoll hvor output er sendt og alt minne frigjøres.

Jeg prøvde å dele de forskjellige delene av programmet ut i flere filer for å gjøre koden enklere å forstå og mere logisk. Føler jeg har oppnådd et godt oversiktlig program som gjør sin oppgave godt. 
