#define MotorA_sentido1 2
#define MotorA_sentido2 4
#define MotorB_sentido1 8
#define MotorB_sentido2 9
#define MotorA_PWM 3  
#define MotorB_PWM 10  
 
#define veloc0 0
#define veloc1 80
#define veloc2 180
#define veloc3 255
 
#define Sensor_direita 6
#define Sensor_esquerda 7
#define Sensor_centro 11
 
bool direita, esquerda, centro;
 
void setup() {
  Serial.begin(9600);
  pinMode(MotorA_sentido1, OUTPUT);
  pinMode(MotorA_sentido2, OUTPUT);
  pinMode(MotorB_sentido1, OUTPUT);
  pinMode(MotorB_sentido2, OUTPUT);
  pinMode(MotorA_PWM, OUTPUT);
  pinMode(MotorB_PWM, OUTPUT);
  pinMode(Sensor_direita, INPUT);
  pinMode(Sensor_esquerda, INPUT);
  pinMode(Sensor_centro, INPUT);
}
 
void loop() {
   //Define o sentido de rotação dos motores
  digitalWrite(MotorA_sentido1, LOW);
  digitalWrite(MotorA_sentido2, HIGH);
  digitalWrite(MotorB_sentido1, HIGH);
  digitalWrite(MotorB_sentido2, LOW);
  
  //Leituras dos Sensores
  direita = digitalRead(Sensor_direita);
  esquerda = digitalRead(Sensor_esquerda);
  centro = digitalRead(Sensor_centro);

 
  //Rodando os motores dependendo das leituras
 if(direita == false && esquerda == false && centro == true){
 analogWrite(MotorA_PWM, veloc3);
 analogWrite(MotorB_PWM, veloc3);
 } else if(direita == false && esquerda == false && centro == false){
 delay(420);
 analogWrite(MotorA_PWM, veloc0);
 analogWrite(MotorB_PWM, veloc0);
 delay(420);
 } else if(direita == false && esquerda == true && centro == false){
  delay(420);
  analogWrite(MotorA_PWM, veloc3);
  analogWrite(MotorB_PWM, veloc1);
  delay(420);
 } else if(direita == false && esquerda == true && centro == true){
  delay(420);
  analogWrite(MotorA_PWM, veloc3);
  analogWrite(MotorB_PWM, veloc2);
  delay(420);
 } else if(direita == true && esquerda == false && centro == false){
  delay(420);
  analogWrite(MotorA_PWM, veloc1);
  analogWrite(MotorB_PWM, veloc3);
  delay(420);
 } else if(direita == true && esquerda == false && centro == true){
  delay(420);
  analogWrite(MotorA_PWM, veloc2);
  analogWrite(MotorB_PWM, veloc3);
  delay(420);
 } else if(direita == true && esquerda == true && centro == false){
  delay(420);
  analogWrite(MotorA_PWM, veloc0);
  analogWrite(MotorB_PWM, veloc0);
  delay(420);    
 }else if(direita == true && esquerda == true && centro == true){
 analogWrite(MotorA_PWM, veloc0);
 analogWrite(MotorB_PWM, veloc0);
 }
}
