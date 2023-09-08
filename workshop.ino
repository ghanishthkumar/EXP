#define BLYNK_TEMPLATE_ID "TMPL392KPqVsR"
#define BLYNK_TEMPLATE_NAME "Ghanishth kumar"
#define BLYNK_AUTH_TOKEN "WTEf7yeeeumgINVt747vPni7Fqn4esjQ"

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>

#define DHTPIN 4 // Data pin is connected to D2 on ESP
#define DHTTYPE DHT11 //Name the sensor as an object

char auth[] = "WTEf7yeeeumgINVt747vPni7Fqn4esjQ";
char ssid[] = "iPhone (4)";
char pass[] = "12345678";

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHT Test Successful!");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Blynk Connected Successfully");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Something is not working as intended.");
    return;
  }
Serial.println("Humidity: ");
Serial.print(h);
Serial.print("%");
Serial.println("Temperature");
Serial.print(t);
Serial.print("degrees celsius.");
Blynk.virtualWrite(V0, t);
Blynk.virtualWrite(V1, h);
delay(1000);
}
