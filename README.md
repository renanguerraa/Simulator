# Simulator
 A cannon simulator made in C
 
 O objetivo da atividade é elaborar um programa para fazer uma simulação de lançamento de projéteis, com o objetivo de atingir um determinado alvo. Essa aplicação pode ser observada em um lançamento de uma bala de canhão, na qual para acertar o alvo é necessário definir o ângulo de inclinação do canhão (α) e a velocidade inicial (V0) que a bala foi lançada.
 Espera-se com esse programa obter o alcance horizontal, o tempo do trajeto e a altura máxima atingida por cada disparo, além de se um determinado alvo foi ou não atingido

## Funcionamento

- Mostrar o seguinte menu para o usuário:
 1. Simular disparo
 2. Mostrar estatísticas
 3. Mostrar resumo de todos os disparos realizados
 4. Sair

- Caso o usuário tente usar uma opção inválida, deve ser comunicado por uma mensagem, e o programa deve pedir a opção desejada novamente.
- A opção sair é a única forma de finalizar o programa.
- A seguir, é detalhado o comportamento esperado de cada item do menu.

## Simular disparo

- Deve ser pedido ao usuário para que digite as seguintes informações sobre o disparo: Velocidade Inicial (V0), que deve ser positiva e diferente de 0;
- Ângulo de inclinação do canhão (α), que será inserido pelo usuário em graus e deve estar na faixa de valores (intervalo aberto);
- Distância do alvo (d), em metros, que deverá ser maior do que zero;
- Tamanho do alvo (t), em metros, que deve estar na faixa de valores [20, 50] (intervalo fechado).

 Validação: Cada uma das entradas de dados deve ser validada. Caso o valor inserido não seja válido, deverá ser solicitado ao usuário que digite novamente aquele dado. Se o dado for válido, o programa pode prosseguir a execução, perguntando a próxima informação ao
usuário.
 Em seguida, essa tela deve apresentar o alcance horizontal, o tempo do trajeto e a altura máxima atingida por este disparo, bem como se o disparo atingiu o alvo, ou se caiu antes ou depois dele.
 Depois disso, o programa deve retornar ao menu e aguardar a escolha do usuário.
 
## Mostrar estatísticas

 Essa tela deve mostrar os seguintes dados:
 
- Média do alcance horizontal dos disparos;
- Qual foi a maior altura atingida dentre todos os disparos;
- A porcentagem de disparos que atingiram o alvo.

 Depois disso, o programa deve retornar ao menu e aguardar a escolha do usuário.
 
## Mostrar resumo

 Esta tela deve mostrar uma listagem de todos os disparos feitos até agora, e se foi bemsucedido ou não (i.e, atingiu o alvo).
 
 Exemplo:
- O disparo 1 atingiu o alvo.
- O disparo 2 nao atingiu o alvo.
- O disparo 3 atingiu o alvo.
