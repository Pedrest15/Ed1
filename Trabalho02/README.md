<h1>TP02 - Dados3D em Listas</h1>

<p> Este trabalho é relacionado ao uso de listas encadeadas dinâmicas (simples ou duplamente encadeadas) e que irão ser usadas para armazenar 
os dados 3D em matrizes esparsas com dados ordenados e com consulta “rápida” priorizando alguma das coordenadas. 
O programa também irá apresentar o desempenho na consulta aos dados destas diferentes listas com dados 3D esparsos. 
Serão criadas 5 listas encadeadas com os MESMOS dados nas 5 listas, o que vai permitir depois comparar o “custo” de acessar os dados: </p> 

<li>Lista ordenada em X, depois em Y, e depois em Z   (em caso de empate: X -> Y -> Z)
<li>Lista ordenada em Y, depois em X, e depois em Z   (em caso de empate: Y -> X -> Z)
<li>Lista ordenada em Z, depois em X, e depois em Y   (em caso de empate: Z -> X -> Y)
<li>Lista não ordenada com inserção no início
<li>Lista não ordenada com inserção no final
  
<p>
  Os dados estão armazenados em um arquivo (“dados3d.txt”) que será lido e então esses dados serão colocados nas listas, são inseridos os mesmos dados nas 5 listas, ou seja, haverão 5 cópias dos dados espalhados nestas listas. Os dados manipulados são chamados de point-clouds 3D (XYZ+CorRGB+ID). Os dados armazenados devem guardar informações sobre:
  </p>
<li>XYZ: A coordenada do ponto X,Y,Z  (3 valores do tipo float)
<li>RGB: A cor do ponto com valores de cor em R, G, B (Red, Green, Blue) com valores inteiros. Os valores de cor variam de 0 a 255 cada um deles (R,G,B são 3 valores inteiros positivos)
<li>ID: Um valor que identifica o “objeto”, ou seja, um identificador, que é um valor entre 0 e 1024. Os pontos 3D podem fazer parte de diferentes objetos, e cada objeto possui um identificador próprio (um valor inteiro entre 0 e 1024).

  <p>
    Note que o arquivo termina pela linha “0 0 0 0 0 0 -1” que não deve ser inserida nas listas.
O valor do identificador possui um valor inválido ( -1 ), indicando que não tem mais dados.
O programa começa lendo os dados e inserindo os dados do arquivo nas 5 listas, conforme descrito acima. Lembrando: cada uma das 5 listas deve conter todos os dados, ou seja, são 5 listas contendo cada uma delas todos dados lidos do arquivo (sim, os dados são replicados). Após lidos os dados o programa entra em modo “consulta”, recebendo comandos do teclado que permitem obter respostas exibidas na tela. Por exemplo: se o usuário digital o comando “lx”, então devem ser exibidos os dados da lista ordenada por X (ordem de prioridade X, depois Y, depois Z). 
  </p>
<p>
  Os comandos digitados pelo teclado e que devem ser aceitos pelo programa são: 
(sempre digitados em maísculas)
  </p>
<li>LX – Listar todos dados da lista ordenada por X (X depois Y depois Z)
        Formato:  X, Y, Z, R, G, B, ID    [dados separados por vírgula e espaço, float com 5 casas]  
        Exemplo:  1.00000, 1.00000, 1.00000, 255, 0, 0, 1   [XYZ=(1.0;1.0;1.0); RGB=(255,0,0), ID=1]
<li>LY - Listar todos dados da lista ordenada por Y (Y depois X depois Z)
<li>LZ - Listar todos dados da lista ordenada por Z (Z depois X depois Y)
<li>LI - Listar todos dados da lista com inserção NÃO ordenada, inserindo dados no início da lista
<li>LF - Listar todos dados da lista com inserção NÃO ordenada, inserindo dados no final da lista
<li>TOT – Exibir o total de nodos acessados nas inserções nas listas LX,LI,LF. Considerando o exemplo
           “dados3d.txt” citado acima seria exibido:     LX:15 LI:6 LF:21
<li>PZ – Listar o dado mais próximo em Z contido na lista ordenada por Z, ou seja, mostrar o dado 
         com o menor valor de Z e o total de nodos visitados para achar este dado.    
<li>PI - Listar o dado mais próximo em Z, contido na lista não ordenada com inserção no Início, ou 
       seja, mostrar o dado com o menor valor de Z e o total de nodos visitados para achar este 
       dado.    
<li>ID – Ler do teclado um número inteiro representando o ID procurado e exibir apenas os dados 
         que possuem o ID informado. Exibir no formato igual ao das opões LX,LY,LZ,LI e LF, porém
         aplicando um filtro que exibe apenas os dados com o ID solicitado. Consultar a lista 
         ordenada por X (LX – X depois Y depois Z) para exibir os dados. Exemplo:   ID 5
        
<li>CUT – Ler do teclado 3 números com as coordenadas X,Y,Z mínimas e 3 números com as coor-
           denadas X,Y,Z máximas, definindo um “bounding box” (retângulo de recorte) dos dados 
           3D. Considerando a lista LX (ordem em X depois Y e depois Z, exibir na tela apenas os 
           dados que ficam dentro do retângulo definido (incluindo os limites max e min). Exemplo: 
           Entrada de dados pelo teclado:    CUT 0.0 0.0 0.0 10.0 10.0 10.0
           
