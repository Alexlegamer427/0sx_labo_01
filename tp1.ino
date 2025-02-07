//code de Alexis Grenier
const int LED_PIN = 13;
const String NUM_DA = "6308958";
int compteur = 0;
const int ETEINT_ALUMME_DELAY = 2000;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:


  switch (compteur) {
    case 0:
      allumer();
      break;
    case 1:
      clignotement();
      break;
    case 2:
      variation();
      break;
    case 3:
      fermer();
      break;
  }


  compteur = (compteur + 1) % 4;
}

void print(String text) {
  Serial.print(text);
  Serial.print(" - ");
  Serial.println(NUM_DA);
}
void allumer() {

  digitalWrite(LED_PIN, HIGH);
  delay(ETEINT_ALUMME_DELAY);
  print("allumer");
}
     
void clignotement() {
  int delay_du_clignotement = 250;
  int RESULTAT_CHIFFRE = 4;  //6308958   donc la formule donne 4 pour moi car 5/2 = 2.5 donc 3 et +1  donc= 4
  for (int i = 0; i < RESULTAT_CHIFFRE; i++) {
    digitalWrite(LED_PIN, LOW);
    delay(delay_du_clignotement);
    digitalWrite(LED_PIN, HIGH);
    delay(delay_du_clignotement);
  }
  print("clignotement");
}

void variation() {
  digitalWrite(LED_PIN, LOW);


  for (int i = 0; i < 255; i++) {

    analogWrite(LED_PIN, i);
    delay(8);
  }
  print("variation");
}

void fermer() {

  digitalWrite(LED_PIN, LOW);
  delay(ETEINT_ALUMME_DELAY);
  print("fermer");
}
