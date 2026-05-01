# ads-mckz-iot-iluminacao-inteligente

Protótipo de iluminação inteligente com ESP32, LDR e MQTT  

Este projeto apresenta um protótipo de sistema de iluminação pública inteligente utilizando ESP32, sensor LDR e comunicação via MQTT, desenvolvido como projeto da disciplina **Objetos Inteligentes Conectados**.


## Objetivo

Desenvolver um protótipo didático de iluminação inteligente utilizando IoT, com foco no aprendizado prático de sensores, atuadores e comunicação MQTT, alinhado ao **Objetivo de Desenvolvimento Sustentável 11**, que busca promover espaços urbanos mais seguros, acessíveis e sustentáveis por meio do uso eficiente da iluminação pública.


## Componentes utilizados

- ESP32  
- Sensor LDR (módulo)  
- LED (atuador)  
- Resistor 220Ω  


## Funcionamento

O sistema realiza a leitura da luminosidade por meio do sensor LDR.  
Quando o ambiente está escuro, o LED é acionado automaticamente.  

Os dados de luminosidade são enviados via protocolo MQTT para um broker público, permitindo o monitoramento em tempo real.


## Comunicação MQTT

- **Broker:** broker.hivemq.com  
- **Porta:** 1883  
- **Tópico:** `iluminacao/luminosidade` e  `iluminacao/status`
<img width="1461" height="872" alt="Screenshot 2026-05-01 at 18 50 11" src="https://github.com/user-attachments/assets/fdd35e1f-8610-482c-88eb-5e7dc3e5f43c" />


## Tecnologias utilizadas

- ESP32 (IoT)  
- Linguagem C/C++ (Arduino)  
- Wokwi (simulação)  
- MQTT (comunicação)  


## ▶️ Como executar

1. Acesse o projeto no Wokwi:  
 https://wokwi.com/projects/461937069472616449  

2. Execute a simulação  

3. Ajuste a luminosidade do sensor LDR  

4. Observe o comportamento do LED e os dados exibidos no Serial Monitor  

## Imagens do projeto

<img width="957" height="496" alt="baixa-iluminacao-off" src="https://github.com/user-attachments/assets/8982b32d-58f4-4cf5-b2fa-b04da16304c5" />


## Artigo

O artigo completo está disponível em:  https://github.com/GiovanaPalhares/ads-mckz-iot-iluminacao-inteligente/blob/main/Artigo%20projeto%20de%20IoT-final-v3.pdf
Vídeo de execução: https://youtu.be/hMxoeX_-jQQ 
