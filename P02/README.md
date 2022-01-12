<div align="justify" >
<p>
  O programa deve ler de um arquivo contendo os
CEPs de cidades brasileiras e criar uma árvore binária ordenada e balanceada baseada no código do
CEP. O arquivo contém os dados do CEP inicial (numérico), CEP final (numérico), Cidade (Texto
sem acentos e sem espaços no nome da cidade) e Estado (sigla – texto), em um arquivo texto,
terminado por 0 0 0 0. Exemplo do arquivo “cepdata.txt”.
  </p>
  <p>
  <strong>Detalhamento sobre o Arquivo:</strong></br>
  <li>Linhas com dados do “intervalo” do CEP de cada cidade, 2 números (início e final do CEP), nome
da cidade e sigla do estado, SEPARADOS por espaço (textos sem acentos ou caracteres especiais,
apenas letras e “_”, com no máximo 30 caracteres no nome da cidade). O nome da cidade é apenas
uma palavra pois não possui espaços.
  <li>O arquivo termina por “0 0 0 0” (quatro zeros), estes dados NÃO DEVEM ser incluídos na árvore.
  <li>IMPORTANTE: não devem existir dados de CEP duplicados ou sobrepostos (números). Note que
estamos definindo INTERVALOS de CEP, ou seja, por exemplo, em São Carlos são válidos os
CEPs entre 13560001 e 13579999. Logo, o CEP 13566590 é um CEP válido para fins de consulta
(CEP da USP São Carlos!).
</p>
  <p>
  <strong>Detalhamento da Implementação:</strong></br>
  <ol>
  <li>Ler o arquivo com dados “cepdata.txt” e criar uma representação adequada na forma de uma
árvore binária ORDENADA e BALANCEADA dos dados (por exemplo, uma ABO AVL);
  <li>A ordem usada é considerando o INTERVALO numérico do CEP de cada cidade. Note que
não vai haver sobreposição ou duplicidade destes intervalos. IMPORTANTE: se for tentada a
inserção de um intervalo de CEP com duplicidade ou sobreposto, o programa deve terminar e
exibir a mensagem na tela: “ERROR”;
  <li>Uma vez criada a ABO Balanceada, vamos ler comandos da console (teclado) e fazer as
seguintes operações, cujo resultado é um “print” com a saída na tela: (o usuário digita um
número e a operação correspondente é executada, sendo executada apenas UMA operação e o
programa é então encerrado).
  </ol>
  </p>
  <p>
  <strong>Opções digitadas pelo usuário: (digita um valor numérico entre 1 e 5)</strong></br>
  <ol>
  <li>Exibe o total de nodos inseridos na árvore ABO Balanceada. No caso do exemplo acima,
deve exibir o valor 28 na tela e terminar o programa (são 28 linhas de CEPs).
  <li>Exibe o número de níveis da árvore – altura (depende do tipo de algoritmos de balancea-
mento que foi usado).
   <li>Consulta um determinado CEP. O usuário vai digitar um segundo número, ou seja, digita 2
indicando que quer consultar os CEPs, e depois digita um outro número que é o CEP procurado
na consulta aos dados da ABO Balanceada.</br>
       IMPORTANTE: se o usuário digitar um CEP que não existe, deve exibir na tela a mensagem "FAIL".  
  <li>Exibe TODA a árvore ABO Balanceada percorrendo em modo de “pré-ordem”.
Os nodos devem ser exibidos no mesmo formato que foram lidos, ou seja, um intervalo de CEP (inicio e final) mais cidade e sigla do estado, separados por espaço
em branco e um conjunto destes dados em cada linha (mesma forma como aparecem no
arquivo).
  <li>Exibe TODA a árvore ABO Balanceada percorrendo em modo de “em-ordem”.
Os nodos devem ser exibidos no mesmo formato que foram lidos, como no comando 4.
  </ol>
  </p>
 </center
