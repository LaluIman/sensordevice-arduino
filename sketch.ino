#define Led_Merah 21
#define trig 15
#define echo 2

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  pinMode(Led_Merah, OUTPUT);

  pinMode(trig, OUTPUT);

  pinMode(echo, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  int durasi = pulseIn(echo, HIGH);
  int jarak = durasi * 0.034 / 2;

  indikator (jarak);
  Serial.println(jarak);
}

void indikator(float jarak)
{
  if (jarak < 100){
    digitalWrite(Led_Merah, LOW);
  }else{
    digitalWrite(Led_Merah, HIGH);
  }
}
