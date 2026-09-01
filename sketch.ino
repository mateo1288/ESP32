#include <DHT.h>

#define DHTPIN 4       // Pin de datos conectado al GPIO 4
#define DHTTYPE DHT22  // Tipo de sensor

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  Serial.println("Iniciando DHT22...");
}

void loop() {
  delay(2000); // El DHT22 necesita aproximadamente 2 segundos entre lecturas

  float humedad = dht.readHumidity();
  float temperatura = dht.readTemperature();

  // Comprobar si hubo un error
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error al leer el DHT22");
    return;
  }

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  Serial.print("Humedad: ");
  Serial.print(humedad);
  Serial.println(" %");

  Serial.println("--------------------");
}
