# Configurando um Servidor BLE no ESP32

Este guia detalha como configurar o ESP32 para se conectar a um controle PS4 via Bluetooth. O processo envolve adquirir o endereço MAC do ESP32, emparelhar o controle e gerenciar conexões. Utilizaremos o Arduino IDE para todas as etapas.

---

## **Pré-requisitos**
- Arduino IDE instalado.  
- Drivers necessários para o ESP32.  
- Controle PS4.  

---

OBS: *Drivers utilizados para o projeto:* https://github.com/espressif/esp-idf
Instale a lib em preferencias: https://espressif.github.io/arduino-esp32/package_esp32_index.json
Pode utilizar as placa ESP32 Wrover Module/ESP32 Dev Module/ESP32vn IoT Uno (placas testadas no projeto)
Caso, apresente erros de ou precise alterar a opção PSRAM ou Partition Scheme, utilize ESP32 Dev Module.
