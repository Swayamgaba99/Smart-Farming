#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4  
#define DHTTYPE DHT11   
#define WATER_PIN A0
#define SOIL_PIN A1

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); 
  Serial.println("Start!");
 
  dht.begin();
}

void Temp_DHT(){
    // Wait a few seconds between measurements.
  delay(2000);
  // Read humidity
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.print("  C ");
  Serial.print(f);
  Serial.print("  F\t");
  Serial.println("");
  }
  
  void Water_level(){

  int value = 0; // variable to store the sensor value

  value = analogRead(WATER_PIN); // read the analog value from sensor

  Serial.print("Water Level value: ");
  Serial.println(value);
  if (value > 300) {
    Serial.println("Full");
    }
  else if ((value > 150) && (value <= 300)) {
    Serial.println("Average ");
    }
  else{
    Serial.println("Dry ");
    }

  delay(1000);
}


void Soil_moisture(){
  int value = analogRead(SOIL_PIN);
  Serial.print("Analog output: ");
  Serial.println(value);
  if (value < 500) {
    Serial.println("Soil is WET");
    }
  else {
    Serial.println("Soil is DRY ");
    }
  }


void loop() {
 Temp_DHT();
 Water_level();
 Soil_moisture();
 Serial.println("  ");
}
