//include DHT sensor and LCD libraries
#include <DHT.h> 
#include <LiquidCrystal.h>

// DHT sensor configuration
#define DHTPIN 2      
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);

// LCD configuration (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // Initialize the LCD
  lcd.begin(16, 2);
  lcd.print("Initializing...");

  // Initialize the DHT sensor
  dht.begin();
  delay(2000); // Wait for the sensor to stabilize
  lcd.clear();
}

void loop() {
  float temp = dht.readTemperature(); // Read temperature (Celsius)
  float hum = dht.readHumidity();     // Read humidity (%)

  // Check if readings are valid
  if (isnan(temp) || isnan(hum)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!");
    return;
  }

  // Display temperature and humidity on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(hum);
  lcd.print(" %");

  delay(2000); // Update every 2 seconds
}
