// khai báo đinh nghĩa chân
const int anhsang = A0; // cam bien anh sáng
const int Trigger = 9; // 2 chan cua cam bien sieu am
const int Echo = 10;
const int chuyendong = 3; // cam bien chuyen dong
const int okhoa = 7;
const int led1 = 8;
const int led2 = 6;

// khai bao bien
int gtanhsang ; // doc gia trị cam biem anh sang
int gtchuyendong; // doc gia tri cam bien chuyen dong
int khoangcach; // doc gia tri cam bien sieu am
unsigned long time1; // dem thoi gian sang den
unsigned long time2; // dem thoi gian khoa cua



void setup() {
  pinMode(anhsang, INPUT);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(chuyendong, INPUT);
  pinMode(okhoa, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
// phat thu tinh hieu cam bien sieu am
int sieuam () {
  digitalWrite(Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigger, LOW);
  int gt = pulseIn(Echo, HIGH);
  int gthc = (gt/2/29.412); // giá trị sau khi tính được
  return gthc;
}

void loop() {
  // docgia tri cam bien anh sang
  gtanhsang = analogRead(anhsang); 
  if (gtanhsang > 500) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
// doc gia tri cam bien chuyen dong
   gtchuyendong = digitalRead(chuyendong); 
  if (gtchuyendong == HIGH) {
    digitalWrite(led2, HIGH);
    time1 = millis();
  } else {
    if ( millis() - time1 > 10000) {
      digitalWrite(led2,LOW); 
    }
  }
  
// khoang cach nguoi dem gan
  khoangcach = sieuam();  
  Serial.println(khoangcach);
  if (khoangcach < 50) {
    digitalWrite(okhoa, HIGH);
    time2 = 0;
  } else { 
    if (time2 == 0) {
      time2 = millis();
    }
    if (millis() - time2 > 20000) {
      digitalWrite(okhoa,LOW);
    }
  }
}
