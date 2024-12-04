#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

// Definindo o UUID do Serviço e da Característica
#define SERVICE_UUID        "12345678-1234-5678-1234-56789abcdef0"  // UUID para o serviço
#define CHARACTERISTIC_UUID "abcdef01-1234-5678-1234-56789abcdef0"  // UUID para a característica

BLECharacteristic *pCharacteristic;

// Classe de callback do servidor BLE
class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    Serial.println("Cliente conectado!");
  }

  void onDisconnect(BLEServer* pServer) {
    Serial.println("Cliente desconectado!");
  }
};

// Classe de callback para a característica
class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    // Lendo os dados enviados pelo cliente como String do Arduino
    String value = pCharacteristic->getValue().c_str();  // Converte para String

    // Mostrando os dados recebidos no monitor serial
    if (value.length() > 0) {
      Serial.println("Valor recebido:");
      for (int i = 0; i < value.length(); i++) {
        Serial.print("0x");
        Serial.print((uint8_t)value[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
    }
  }
};

void setup() {
  // Inicializando a comunicação serial
  Serial.begin(115200);
  Serial.println("Iniciando o servidor BLE...");

  // Inicializando o dispositivo BLE
  BLEDevice::init("ESP32-Server");

  // Criando o servidor BLE
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Criando o serviço BLE
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Criando a característica com propriedade de escrita
  pCharacteristic = pService->createCharacteristic(
                        CHARACTERISTIC_UUID,
                        BLECharacteristic::PROPERTY_READ |
                        BLECharacteristic::PROPERTY_WRITE
                      );

  // Adicionando callbacks à característica
  pCharacteristic->setCallbacks(new MyCharacteristicCallbacks());

  // Configurando um valor inicial (opcional)
  uint8_t hexData[] = {0x48, 0x65, 0x6C, 0x6C, 0x6F};  // "Hello"
  pCharacteristic->setValue(hexData, sizeof(hexData));

  // Adicionando descritores (opcional)
  pCharacteristic->addDescriptor(new BLE2902());

  // Iniciando o serviço
  pService->start();
  Serial.println("Serviço iniciado");

  // Começando a publicidade do dispositivo BLE
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Serial.println("Aguardando conexão de um cliente...");
}

void loop() {
  // O servidor BLE aguarda conexões e processa interações
  delay(1000);
}
