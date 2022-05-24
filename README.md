# Clapper

### Projeto Senior Light: Sistema de Iluminação inteligente para Idosos

## Funcionamento e Uso do Projeto
Este projeto consiste na criação de um circuito para acender e apagar um led ao bater seguidamente um número específico de palmas. O led se acenderá e se apagará, dependendo de seu estado inicial, ao batermos 2 palmas consecutivas. Para isso, vamos utilizar um módulo sensor de som capaz de captar ruídos e transformá-los em sinais. Ao receber esses sinais, o Arduíno, em conjunto com outros componentes, poderá acionar o led, modificando seu estado de aceso para apagado e vice-versa. No projeto utilizamos protocolo de rede MQTT, que transmite o acionamento do sensor de som pela internet, ao atuador. O protocolo MQTT confere ao projeto flexibilidade e leveza, suportando a comunicação assíncrona entre as partes, utilizando um modelo de publicação de assinatura. Por ser um padrão aberto OASIS, o protocolo suporta linguagens populares de programação, usando diversas implementações de software livre.

## Material Necessario
- Protoboard
- Arduino Uno R3
- Sensor de Som KY-037
- Jumpers Macho-Macho e Macho-Fêmea
- Resistor
- Led 5mm
- Cabo USB para conectar o Arduino ao computador

## Pré-Requisitos
- IDE do Arduino
- Node.js
- Node-Red

## Montagem Circuito
1. Realizar a montagem do circuito conforme a imagem: [Circuito - Fritzing](img/clapper_fritzing.png)

## Instruções para execução
1. Abrir o arquivo clapper.ino pela IDE do Arduino em sua máquina
2. Conectar o Arduino ao computador e conferir na IDE a placa e porta conectados
3. Realizar o deploy do código no Arduino através da IDE
4. Através do terminal abrir a conexão com o Node-Red digitando `node-red`
5. Com a porta do node-red aberta, acessar através do browser `localhost:1880`
6. Configurar o fluxo conforme a imagem: [Fluxo Node-Red](img/Fluxo-Node-Red.png)
7. Realizar a subscrição no Tópico criando no HiveMQ ou qualquer outro Broker de sua preferência.
