# Clutch 🪖🔫💥

## Projeto da disciplina de Linguagem de Programação 1 (IMD0030), implementado em C++ com a biblioteca SFML.

Clutch é um jogo 2D do subgênero Shoot 'em up e com estética inspirada no CS 1.6. 
No jogo o  usuário controla um atirador que esta encuralado em uma area de guerra por seus inimigos e seu unico objetivo é proteger a base e permanencer o maximo possivel vivo. Os inimigos aparecem aleatoriamente e caminham em direção ao jogador, disparando projéteis. A base é localizada no centro do mapa quando dentro dela se torna uma barrereira contra os ataques inimigos, mas acabar sua proteção a missão falha e o jogo acaba.

# Para a Compilação do programa no terminal
Para compilar digite:
`make` ou `mingw32-make`   

Para executar digite:
`.\bin\app`

## Requisitos
Estar em um ambiente Windows.
Possuir o GCC 13.1.0 ou versão superior.
De preferência, estar utilizando o Visual Studio Code.

## Link do Vídeo
https://youtu.be/88oO7P5FYQw?si=RN3_CH8hthVEL2zL

## Classes Principais
1. **Atirador**
A classe Atirador é responsável por gerenciar o jogador. Ela controla o movimento, a rotação, a vida, o número de projéteis disponíveis e a interação com o cenário, como a coleta de recargas. A classe também lida com a renderização do jogador na tela e a detecção de colisões com outros objetos.

2. **Inimigo**
A classe Inimigo gerencia os oponentes que perseguem o jogador. Cada inimigo se movimenta em direção ao atirador, podendo disparar projéteis e causar dano. A classe controla a lógica de ataque, movimento e vida dos inimigos.

3. **Projetil**
A classe Projetil gerencia o comportamento dos projéteis disparados tanto pelo jogador quanto pelos inimigos. Ela lida com a trajetória dos projéteis, a detecção de colisões e a remoção de projéteis que saem da tela ou atingem seus alvos.

4. **Base**
A classe Base representa a área central do mapa onde o jogador pode se proteger temporariamente dos ataques inimigos. A base oferece uma barreira até que sua proteção acabe, momento em que o jogador deve sair e continuar se defendendo por conta própria.

5. **Jogo**
A classe Jogo é responsável por gerenciar o loop principal do jogo. Ela inicializa todas as entidades, processa as entradas do jogador, atualiza o estado do jogo, verifica condições de vitória ou derrota, e renderiza os elementos na tela. A classe Jogo conecta todas as outras classes, permitindo a interação e o funcionamento harmonioso do jogo.
