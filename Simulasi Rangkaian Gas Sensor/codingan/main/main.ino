#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,20,4);

const int sensor_gas = A0;
int keluar_gas = 11;
const int merah = 13;
const int hijau = 8;
const int buzzer = 12;


void setup() {

     Serial.begin(9600);
     lcd.begin(16,1);
     lcd.init();
     lcd.backlight();
     lcd.print("selamat datang");
     lcd.clear();
     pinMode(sensor_gas, INPUT);
     pinMode(merah, OUTPUT);
     pinMode(hijau, OUTPUT);
     pinMode(buzzer, OUTPUT);
     
}



void loop() {


    int nilai = analogRead(sensor_gas);
    Serial.println(nilai);

    if(nilai >= 500){

      lcd.setCursor(4,0);
      lcd.print("GAS NYALA");
      digitalWrite(merah, HIGH);
      digitalWrite(hijau, LOW);
      digitalWrite(buzzer, HIGH);   
      lcd.setCursor(3,1);
      lcd.print("Kelompok 9");  
      delay(2000);
      lcd.clear();
      
    } else if ( nilai <= 500) {

      lcd.setCursor(4,0);
      lcd.print("GAS MATI");
      digitalWrite(merah, LOW);
      digitalWrite(hijau, HIGH);
      digitalWrite(buzzer, LOW); 
      lcd.setCursor(3,1);
      lcd.print("Kelompok 9");
      delay(2000);
      lcd.clear();
      
    }


}
