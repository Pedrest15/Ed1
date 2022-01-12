<h1>TP03 - Circuitos Lógicos em Árvores Binárias NÃO ordenadas</h1>

<div align="justify" >
<p>
  Este trabalho é relacionado ao uso de Árvores Binárias, usadas para representar circuitos como
o do diagrama abaixo: (a Raiz é a Saída “OUTPUT” e as folhas são as Entradas “INP” do Circuito
Lógico – O esquema abaixo é como se a árvore estivesse “deitada” de lado).
  </p>
  
 <p>
   Observe que cada nodo da árvore é identificado por um IDENTIFICADOR ÚNICO e não
DUPLICADO, do tipo “string”. Os nodos folhas são nodos sem filhos e especiais, pois são as
entradas do circuito. O nodo raiz é um nodo especial pois representa o sinal de saída do circuito. 
  </p>
  
 <p>
   Os nodos podem ser, portanto, dos seguintes tipos – Entradas (INPxxx), Portas Lógicas
de 2 entradas (ANDxx, OR-xxx, XORxxx), Portas Lógicas de 1 entrada (NOTxxx com apenas 1 nodo
filho) e a Saída do Circuito (OUTPUT). Podemos ter até 999 portas e nodos de cada tipo (xxx
pode assumir valores de 000 a 999, não sendo obrigatório que sejam valores sequenciais ou que
comece em zero, só não podem ter dois nodos com o mesmo identificador). 
  </p>
  
  <p>
  A árvore será construída de cima para baixo, onde a inserção será sempre feita com uma
busca, do nodo pai e pelo seu identificador, seguido de uma inserção a direita ou a esquerda, de
seu nodo filho, conforme indicado na descrição do circuito, ou seja, acha nodo pai e insere filho.
  </p>
  
  <p>
  Sempre é inserido ANTES o pai de um nodo, que pode
ser encontrado para que seja inserido seu filho no lado Esquerdo (L –
Left) ou no lado Direito (R – Right). Quando o nodo só tem um filho, ele
é identificado como Único (U – Unique). Nodos folhas tem um Identificador
que começa com “INP” ou “I”, uma vez que os outros nodos tem
identificadores que são bem diferentes. 
  </p>
  
  <p>
  Cada linha do arquivo, contém sempre um nodo a indicação de onde ele se
liga em seu pai, e o identificador do nodo pai (deve buscar pelo pai e
inserir o nodo como seu filho, de acordo com “U”, “L” ou “R”. Isso vale
exceto para a primeira linha do arquivo, que cria o nodo raiz (Root) e
que é a saída (Output) do circuito. O arquivo termina ao encontrar um
nodo “$END” (Linha: “$END00 X XXXXXX” (se começa com “$” já é um sinal
de que não tem mais nodos para inserir na árvore).
  </p>
  
  <p>
  <strong>ATENÇÃO:</strong> A descrição do circuito sempre deverá ser completa e correta
para que a simulação do circuito possa ser realizada, ou seja, todos
nodos terão filhos até chegar nas folhas (todas folhas são nodos INP),
e a árvore deve poder ser construída corretamente. Se houver algum erro
na construção (pai não encontrado, inserção de mais de um filho no mesmo
lado de um determinado nodo pai, falta de um nodo folha em algum dos
nodos intermediários da árvore, o programa deve ser encerrado e exibida
a mensagem na tela de “CIRCUIT ERROR” (em maiúsculas). Portanto, a rotina
que lê o circuito deve realizar estas verificações de erro: (1) inserção
indevida de nodo filho – tentativa de inserir um nodo onde já existe um
nodo inserido; (2) nodo pai não encontrado – e portanto não tem com
inserir o nodo atual; (3) arvore incompleta, quando falta um nodo do
tipo INP em alguma folha da árvore – verificação final ao terminar a
construção da árvore.
  </p>
  
  <p>
  Uma vez lido o arquivo de entrada (“circuit.txt”) e criada a árvore,
serão realizadas consultas da saída simulada do circuito, para um dado
conjunto de entradas (valores dos nodos folhas).
  </p>
  
  <p>
  <strong>Entrada no Circuito: (teclado)</strong> </br>
INP001 1</br>
INP002 0</br>
INP003 1</br>
INP004 0</br></br>
<strong>Saída do Circuito: (tela)</strong></br>
1
  </p>
  
  <p>
  Nota: os valores indicados na entrada são colocados nos nodos folhas e
“propagados” para a raiz, seguindo o funcionamento da simulação das
portas lógicas (simulação do circuito). O valor obtido na raiz é a saída.
  </p>
</center>
