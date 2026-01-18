#include <Servo.h>

Servo myservo;
// ★角度設定★
int angleA = 40;    // 閉じる角度
int angleB = 160;   // 開く角度

int speedDelay = 15;     // サーボの動く速さ
int waitTime = 2000;     // 開いたままの時間（ミリ秒）

void setup() {
  myservo.attach(9);
  myservo.write(angleA); // 初期位置は閉じる
}

void loop() {
  for (int pos = angleA; pos <= angleB; pos++) {
      myservo.write(pos);
      delay(speedDelay);
   }
  delay(waitTime);

  for (int pos = angleB; pos >= angleA; pos--) {
    myservo.write(pos);
    delay(speedDelay);
  }
  delay(waitTime); // チャタリング防止
}
