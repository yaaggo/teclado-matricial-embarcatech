<samp>
<h1 align="center"> Utilização de Teclado Matricial na Raspberry Pi Pico W </h1>
  
<h2 align="center"> Sobre :pencil: </h2>

<p> &emsp;&emsp;&emsp;&emsp; Repositório colaborativo com o objetivo de desenvolver habilidades práticas com a placa BitDogLab e seus pinos, como parte de uma tarefa desenvolvida no Capítulo 2 da Unidade 4 da Embarcatech, residência de Sistemas Embarcados. 

<p> &emsp;&emsp;&emsp;&emsp; Essa tarefa foi desenvolvida pelo subgrupo 1 do grupo 5 do estado da Bahia (CEPEDI), pelos residentes Bruno Silva, Camila Miranda, Isabela Madureira, Matheus Nascimento e Yago Guirra.

<h3> Descrição da tarefa </h3>

<p> &emsp;&emsp;&emsp;&emsp; A tarefa consiste em utilizar um teclado matricial 4x4, com o auxílio do simulador de eletrônica Wokwi, para controlar determinados pinos GPIO do microcontrolador RP2040, presente na placa de desenvolvimento Raspberry Pi Pico W, onde foi realizado o acionamento de 03 LEDs (tipo RGB), juntamente com o controle do sinal sonoro de um buzzer. Nela, foi necessário utilizar os seguintes componentes:

  1. Teclado matricial 4x4;
  2. 03 LEDs – tipo RGB;
  3. Componente Buzzer;
  4. Microcontrolador Raspberry Pi Pico W.

 &emsp;&emsp;&emsp;&emsp; Foi organizada uma equipe, dividida em 1 Líder (gerencia o repositório) e 4 desenvolvedores (cada um com tarefa específica). 

<p> &emsp;&emsp;&emsp;&emsp; O projeto é composto pelos arquivos comuns a um projeto Pico W, além de um READ.ME (descrição do projeto), diagram.json e wokwi.toml (para a simulação no Wokwi) e uma pasta chamada 'inc', que possui 3 arquivos na extensão .c, que são: buzzer.c (que organiza as funções relacionadas ao buzzer), keypad.c (que organiza as funções relacionadas ao teclado matricial) e led.c (que organiza as funções relacionadas ao leds), e 3 arquivos na extensão .h, que são: buzzer.h, keypad.h e led.h (em que ambos possuem o cabeçalho das funções).

<h2></h2>
<h2 align="center"> Vídeo :video_camera: </h2>
<p> &emsp;&emsp;&emsp;&emsp; Aqui está o link para o vídeo com uma prática de simulação associada a esta tarefa: </p>

<h2></h2>
<h2 align="center"> Como utilizar :computer_mouse: </h2>

<p> &emsp;&emsp;&emsp;&emsp; Para utilizar o programa, o usuário deve:

- Clonar o repositório em uma pasta separada para recebê-lo;
- Abrir o projeto no VS Code, importando-o pela extensão Raspberry Pi Pico;
- Abrir o arquivo diagram.json para usar o simulador Wokwi;
- Executar a simulação.
</samp>
