# Configurando um Servidor BLE no ESP32

Este guia explica como criar um servidor BLE no ESP32 e estabelecer comunicação com o aplicativo **nRF Connect** para dispositivos móveis.

---

## **Pré-requisitos**
- Arduino IDE instalado.  
- Drivers necessários para o ESP32.  
- Aplicativo nRF Connect (Nordic Semiconductor).  

---

OBS: *Drivers utilizados para o projeto:* https://github.com/espressif/esp-idf
Instale a lib em preferencias: https://espressif.github.io/arduino-esp32/package_esp32_index.json
Pode utilizar as placa ESP32 Wrover Module/ESP32 Dev Module/ESP32vn IoT Uno (placas testadas no projeto)
Caso, apresente erros de ou precise alterar a opção PSRAM ou Partition Scheme, utilize ESP32 Dev Module.

---


### Passo 1: Compilar o Código

- Compile o código da pasta `src/ESP32ServerBLECommunication` e faça o upload para o seu ESP32.

### Passo 2: Instalar o nRF Connect

- Baixe e instale o aplicativo **nRF Connect** no seu celular (disponível para Android e iOS).

### Passo 3: Configurar os UUIDs

- No aplicativo **nRF Connect**, configure os UUIDs do cliente conforme abaixo:

```cpp
#define SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"  // UUID para o serviço
#define CHARACTERISTIC_UUID "abcdef01-1234-5678-1234-56789abcdef0"  // UUID para a característica
```

### Passo 4: Conectar ao Servidor ESP32

- No **nRF Connect**, busque pelo servidor BLE que você compilou no ESP32 e conecte-se a ele.

### Passo 5: Baixar Informações do Servidor

- Após a conexão, baixe as informações que o servidor deseja enviar, com base na comunicação configurada.

### Passo 6: Enviar Resposta para o Servidor

- Envie uma resposta ao servidor ESP32, completando a comunicação bidirecional.

### Passo 7: Receber Resposta no Servidor ESP32

- O servidor ESP32 irá receber a resposta do cliente, e a comunicação será finalizada.

---
