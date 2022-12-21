#include <Servo.h>
 
//نام گذاری سرو موتورها
Servo S1;
//مقادیر دیجیتال شده ولوم
int Pot1;


void setup() {
	    Serial.begin(115200); // Ignored by Maple. But needed by boards using hardware serial via a USB to Serial adaptor
      pinMode(PA0, INPUT_ANALOG);
      //تعیین پایه های سرو
      S1.attach(PA1,1000,2000);
}

void loop() {

  Pot1 = analogRead(PA0);                                //خواندن مقدار آنالوگ ولوم
  Pot1 = map (Pot1, 0, 4050, 0, 180);                   //مقیاس دهی در بازه های مورد نظر دیجیتال و زاویه
  S1.write(Pot1);                                       //بارگذاری مقدار دیجیتال روی پایه سرو مورد نظر
//  delay (9);
  Serial.println(Pot1);

}
