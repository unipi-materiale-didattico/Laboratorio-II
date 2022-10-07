# Test Tool

lo script *test.sh* permette di scrivere "Unit Test" in modo da automatizzare il testing in locale degli esercizi della piattaforma Evo.

## Argomenti del comando

```shell
# $1 Nome del test
# $2 Programma da testare
# $3 Numero di test case
# Input dei test case [Con Escape dei caratteri]
# Expected output dei test case [Con Escape dei caratteri]

# Esempio
. ./test "Somma" ./add.out 1 "3 5" "8"
```

## Output del comando

Il comando eseguirà il programma da testare per ogni test instance
e stamperà il risultato delle test instance
````shell
Somma:
Test 1
- ✅ Pass
Test 2
- ❌ Fail
Real Output:
10
Expected Output:
13
Test 3
- ❌ Fail
Exit Status: 139
````

## MakeFile

è possibile usare un makefile per automatizzare molteplici test suite
nel seguente modo:

````makefile
SHELL::=/bin/zsh #Oppure /bin/bash
test:
	@. ./test.sh "Somme Cumulative (Es.1)" ./es1 4 "7 5 8 2 -3 9 4 -2" "tutu\\n7 5 8 2\\nche bello\\n -3 9 4 -2" "0" "1 6" "5\\n13\\n15\\n12\\n21\\n25\\n23" "Errore in input, inserisci un intero valido\nErrore in input, inserisci un intero valido\\n5\\n13\\n15\\n12\\n21\\n25\\n23" "" "6"
	@. ./test.sh "Matrix Column Swapper (Es.2)" ./es2 3 "2 3 1 2 3 4 5 6" "0 0" "4 1 5 6 7 8" "3 2 1 \\n6 5 4 " "" "5 \\n6 \\n7 \\n8 "
	@. ./test.sh "Queue (Es.3)" ./es3 4 "2 -7 8 0 -5 8 3 0 2 5 0 0" "0 0" "6 0 0" "4 0 0" "Lista con 5 elementi\\n-5\\n4\\n3\\n1\\n5" "Lista con 0 elementi" "Lista con 1 elementi\\n3" "Lista con 0 elementi"
	@. ./test.sh "Binary search Tree (Es.4)" ./es4 2 "7 8 -2 9 -5 4 6 0 6" "1 4 4" "-5 -2 0 4 6 8 9\\nTrue" "4 \\nTrue"
````

e eseguire i test con il comando
````shell
make test -f MAKEFILE
````