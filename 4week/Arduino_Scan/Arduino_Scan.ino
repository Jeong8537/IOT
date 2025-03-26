#include <LiquidCrystal_I2C.h>


#include <Wire.h> // I2C 통신 라이브러리

void setup() {
  Serial.begin(9600); // Serial Moniter start
  Wire.begin(); // I2C 통신 시작
  Serial.println("I2C Scanner Running..."); // 시작 메시지
}

void loop() {
  Serial.println("Scanning..."); // 검색 시작 메시지 

  for(byte address = 1; address < 127; address++){ // I2C 주소 범위 (0x01 ~ 0x7F(1 ~ 127))
    Wire.beginTransmission(address); // 특정 주소로 통신 시작
    if(Wire.endTransmission() == 0){ // 읃답이 0이면, I2C장치가 존재함
      Serial.print("I2C 장치 발견: 0x"); // 발견된 장치의 주소 출력
      Serial.println(address, HEX); // 10진수 형식 출력
      delay(500); // 0.5초 대기
    }
  }
  Serial.println("Scan Complete! Retrying in 5 seconds ...\n");
  delay(5000); // 5초 후 다시 검색
}
