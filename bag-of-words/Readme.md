<h1>Bag of Words</h1>

<div align="justify" >
<p>
  <strong>1 - </strong>Esse programa foi feito com o intuito de estudar o conceito de árvores do tipo AVL.
  </p>
 <p>
  <strong>2 - </strong>O programa deve ler um arquivo texto em disco, com nome “texto.txt”, contendo um conjunto de
  várias palavras (separadas por espaços, com acentos removidos, sem caracteres especiais e a pon-
 tuação aparece sempre separada por espaços das palavras). Para facilitar na prova serão fornecidos 2
 exemplos de arquivos texto (texto1.txt e texto2.tx) que podem ser copiados sobre o arquivo texto.txt
 para serem considerados e testados na prova.
  </p>
  <p>
 <strong>3 - </strong>O arquivo deve ser lido para a memória onde é criada uma Arvore Binária Ordenada Balanceada
(ABO) com os dados deste arquivo (por exemplo, uma AVL), sendo que esta ABO Balanceada deve
ser criada da seguinte forma:
<ul>
- A ordenação deve ser feita pelas palavras (ordem alfabética das palavras e conforme as rotinas da
biblioteca <string.h> que já ordenam estas palavras ao serem comparadas; </br>
- Os nodos da Árvore ABO Balanceada devem conter os seguintes campos, pelo menos:
<ul>
  <li>Palavra (até 20 caracteres no máximo por palavra); </br>
  <li>Contador do Número de Ocorrências da Palavra (inteiro). </br>
 </ul>
- Podemos notar que uma palavra pode ocorrer mais de uma vez no texto, por isso teremos um contador
que serve para ir contando quantas vezes a palavra ocorre no texto. </br>
- Na inserção de palavras na ABO Balanceada devemos proceder desta forma: 
<ul>
  <li> Se a palavra não existe ainda na Árvore, então deve ser inserida com um nro. de ocorrências = 1; </br>
  <li> Se a palavra já existe na Árvore, então deve ser apenas incrementado o nro. de ocorrências. </br>
</ul>
Não devemos ter palavras duplicadas na árvore! 
</ul>
  </p>
 <p>
  <strong>4 - </strong>Criar uma nova estrutura de dados ordenada, com alocação dinâmica, que pode ser do tipo Árvore
Ordenada ou uma Lista Encadeada Ordenada, você pode escolher o tipo de estrutura de dados que vai
adotar. Esta estrutura terá as seguintes características:
<ul>
- Deve ser ordenada pelo número de ocorrências (permitir que depois possa se obter as
palavras na ordem da maior ocorrência para a menor ocorrência); </br>
- ATENÇÃO: Como existem números de ocorrências iguais para diferentes palavras, inserir
um nodo para cada palavra (podem ter números de ocorrências duplicados), mesmo que
ocorram dados com um número de ocorrência igual nesta estrutura de dados, inserir todas as
palavras.
</ul>
  </p>
  <p>
  <strong>5 - </strong>Solicitar ao usuário para indicar um valor referente ao número mínimo de ocorrências que ele
deseja listar (valor inteiro entre 0 e 9999). Considerando este valor, listar todas palavras que tenham
pelo menos este número de ocorrências (p.ex. se for 2, considerar incluindo de 2 para cima). A lista
deve ser em ordem do número de ocorrências, do maior para o menor número de ocorrências.
  </p>
</center>
