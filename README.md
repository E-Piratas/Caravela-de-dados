
![E-Piratas-Logo](https://github.com/E-Piratas/Caravela-De-Dados/blob/master/documentos/Imagens/E-Piratas-Logo.png)
---
#  **CARAVELA DE DADOS**
## **Projeto de comunicação MQTT e IOT**                   

**Versão** **0.4**

E-Piratas é uma equipe de Acadêmicos da disciplina de Engenharia de Software e este é um projeto de comunicação MQTT entre uma ESP 32 que envia dados de temperatura Para (o servidor boladao da ibm) que Salva no Banco de dados e cria um gráfico interativo.  
Recursos 
* [Requisitos de Projeto](https://github.com/E-Piratas/Caravela-de-dados/wiki)
	* [INTRODUÇÃO](https://github.com/E-Piratas/Caravela-De-Dados/wiki#1-introdu%C3%87%C3%83o)
	* [DESCRIÇÃO](https://github.com/E-Piratas/Caravela-De-Dados/wiki#2-descri%C3%87%C3%83o-geral)
	* [INTRODUÇÃO](https://github.com/E-Piratas/Caravela-De-Dados/wiki#3-recursos-do-sistema)
* Referencias
	* [Tutorial MQTT]()
	* [Biblioteca Json]()
	* [Biblioteca Pubsub]()
---
## **ESP32**

![Esp32Logo](https://github.com/E-Piratas/Caravela-De-Dados/blob/master/documentos/Imagens/Espressif_ESP32.jpg)

Para o desenvolvimento dessa aplicação, foi utilizado uma placa de prototipagem ESP32 devkit V1. Essa placa possui um chip ESP-WROOM-32 produzido pela empresa espressif, que para nosso projeto apresenta uma característica muito importante que é a capacidade de se conectar a uma rede Wi-Fi, permitindo comunicar com um servidor utilizando MQTT.

Essa placa permite adicionar diversos sensores, podendo receber sinais analogicos ou digitais em suas entradas. Além disso também possui a capacidade de gerar sinais de saída em seus pinos, permitindo assim diversas aplicações para essa placa.

Para mais informações acesse o site da fabricante do chip:

https://www.espressif.com/en/products/socs/esp32

## **MQTT**

A prioridade de nosso sistema é a aquisição de dados dos dispositivos ESP 32 através de comunicação TCP/IP, por esse motivos usamos o protocolo MQTT.
Esse protocolo tem como características ser leve e para pequenos dispositivos sendo assim ideal para nossa aplicação.

O artigo a seguir dispõe de mais informações [Clique Aqui](https://developer.ibm.com/br/articles/iot-mqtt-why-good-for-iot/#:~:text=O%20protocolo%20MQTT%20define%20dois,message%20broker%20e%20in%C3%BAmeros%20clientes.&text=O%20cliente%20conecta%2Dse%20ao,TLS%20criptografada%20para%20mensagens%20sens%C3%ADveis.)




## **IBM watson**

Para visualizar as aquisições, foi construído um dashboard na plataforma IBM watson com a ferramenta de desenvolvimento Node RED,  que permite o desenvolvimento da interface gráfica por meio de programação visual e javascript.

Além da interface visual essa aplicação permite a integração com um banco de dados em MySQL, onde ficam armazenados todas as aquisições de nossos dados.

O IBM watson  ainda possibilita diversas aplicações  descritas em seu site:
![Clique Aqui](https://www.ibm.com)

## MYSQL - AWS

Como desejamos salvar os dados, optamos por utilizar um bando de dados, em nossa aplicação usamos o MySQL. O motivo de utilizar é devido a sua agilidade, segurança , gratuito e que suporta diversas linguagens de programação. 

Para hospedar o banco de dados usamos o serviço da amazon AWS. Esse serviço possui diversas aplicações que vão desde nossa utilização com a criação de banco de dados em MySQL até mesmo a criação de máquinas virtuais.

Devido a sua alta capacidade, a empresa amazon disponibiliza diversos tutoriais, em nosso projeto utilizamos o seguinte tutorial para instanciar o banco de dados.
 
![Clique Aqui](https://aws.amazon.com/pt/getting-started/hands-on/create-mysql-db/)

## Funcionamento do programa

Em nosso programa o ESP 32 lê os dados e transforma essas informações em uma arquivo json, utilizando o protocolo Mqtt, o arquivo json envia os dados até o IBM watson, onde é apresentado na tela e gravado no banco de dados MySQL instanciado na AWS.

https://github.com/E-Piratas/Caravela-De-Dados/blob/master/documentos/Imagens/diagrama_comunica%C3%A7%C3%A3o.png


