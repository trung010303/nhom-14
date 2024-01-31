// Chân kết nối cảm biến MQ2
nt MQ2_AOUT = A0;

// Chân kết nối buzzeri
int buzzerPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(MQ2_AOUT, INPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void loop() {
  int sensorValue = analogRead(MQ2_AOUT);
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  // Kiểm tra giá trị cảm biến để quyết định khi nào kích hoạt buzzer
  if (sensorValue >350 ) { // Điều chỉnh ngưỡng cảm biến ở đây
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);
}



