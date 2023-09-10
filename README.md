# perfEG

- Felipe Quaresma Vieira - grr20215516
- Marcelo Augusto Rissette Schreiber - grr20220063

## Como executar

Só isso já vai funcionar (não é obrigatório o make antes):

```bash
python src/likwid.py
```

ou

```bash
python3 src/likwid.py
```

O arquivo de saída será gerado em `src/data/results.log`.

## Arquivos e diretórios

- src: diretório com os códigos fonte
- src/likwid.py: código execução do teste com likwid
- src/objects/*: diretório com os objetos compilados no trabalho (temporário)
- src/data/sistemas.dat: arquivo com os sistemas de equações lineares
- src/data/results.log: resultados dos testes com likwid
- perfEG: executável do trabalho
- Makefile: arquivo de compilação
- README.md: este arquivo

## Observações

Foram observados dois comportamentos durante as testagens do trabalho. Estes são:

Para a grande maioria dos sistemas testados, se não todos, foi apresentado um resíduo nulo. Isso nos gerou uma certa estranheza, pois para outros exemplos com o próposito de alterar o resíduo e testar sua eficiência, o resíduo foi acertivo. Sendo assim, acreditamos que a conta feita para o seu cálculo está certa e que somente foi uma estranheza, não um erro, que notamos.

O outro comportamento notado acontece com o sistema abaixo. Dos exemplos citados no arquivo "sistemas.dat", há erro na resolução final apenas para o sistema a seguir:

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
