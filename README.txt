# perfEG

Felipe Quaresma Vieira - grr20215516
Marcelo Augusto Rissette Schreiber - grr20220063

# Como executar
Só isso já vai funcionar (não é obrigatório o make antes):

```bash
python src/likwid.py
```

# Arquivos e diretórios
- src: diretório com os códigos fonte
- src/likwid.py: código execução do teste com likwid
- src/objects/*: diretório com os objetos compilados no trabalho (temporário)
- src/data/sistemas.dat: arquivo com os sistemas de equações lineares
- src/data/results.log: resultados dos testes com likwid
- perfEG: executável do trabalho
- Makefile: arquivo de compilação
- README.md: este arquivo

# Observações

Foram observados dois comportamentos durante as testagens do trabalho. Estas são:

Para a grande maioria dos sistemas testados, se não todos, foi apresentado um resíduo nulo. Isso nos gerou uma certa estranheza, pois para outros exemplos que não fazem parte daqueles sistemas dados para testagem, o resíduo foi acertivo. Sendo assim, acreditamos que a conta feita para o cálculo do resíduo está certa e que somente foi uma estranheza, não um erro, que notamos.

O outro comportamento foi com os métodos que não utilizam o pivoteamento e o que não utiliza os multiplicadores. Dos exemplos citados no arquivo "sistemas.dat", há erro na resolução final dos dois modelos para os sistemas a seguir:


3
2 1 3 9
0 -1 1 1
1 0 3 3

3
1 0 3 3
0 -1 1 1
2 1 3 9

3
20 2 6 38
1 -20 9 23
2 -7 -20 -57

3
10 2 6 38
1 -100 9 7
2 -7 -10 -17

4
2 -1 3 5 -7
4 -1 10 8 4
6 -3 12 11 4
0 -2 -5 10 -51

3
1 4 52 57
27 110 -3 134
22 2 14 38

17
-3  0  0  1  3  0  0  0  0  0  0  0  0  0  0  0  0  0
-3  0 -1  0 -3  0  0  0  0  0  0  0  0  0  0  0  0  0
 0 -1  0  0  0  1  0  0  0  0  0  0  0  0  0  0  0  0
 0  0  1  0  0  0  0  0  0  0  0  0  0  0  0  0  0  10
 0  0  0 -1  0  0  0  1  0  0  0  0  0  0  0  0  0  0
 0  0  0  0  0  0 -1  0  0  0  0  0  0  0  0  0  0  0
 0  0  0  0 -3 -1  0  0  3  1  0  0  0  0  0  0  0  0
 0  0  0  0  3  0  1  0  3  0  0  0  0  0  0  0  0  15
 0  0  0  0  0  0  0 -1 -3  0  0  1  3  0  0  0  0  0
 0  0  0  0  0  0  0  0 -3  0 -1  0 -3  0  0  0  0  0
 0  0  0  0  0  0  0  0  0 -1  0  0  0  1  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  1  0  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  0 -1  0  0  0  0  0  0
 0  0  0  0  0  0  0  0  0  0  0  0  0  0 -1 -3  0  0
 0  0  0  0  0  0  0  0  0  0  0  0 -3 -1  0  0  1  0
 0  0  0  0  0  0  0  0  0  0  0  0  3  0  1  0  0  10
 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 -3 -1  0

(inclusive, esse não é solucionado por nenhum dos métodos).

4
2 -1  3 5 2
4 -1 10 8 3
6 -3 12 11 4
0 -2 -5 10 5

