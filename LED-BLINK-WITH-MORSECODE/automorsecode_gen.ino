int pin = 13;
int delaygap = 250;
int dot = 500;
int dash = 1000;
int completion = 2250;

/* max 10 letters
type " " for a space
eg; "-.- .-- ... .... .- .-.."
*/

String morsecode = "-.- .-- ... .... .- .-..";

void dash_(){
    digitalWrite(pin, HIGH);
    delay(dash);
    digitalWrite(pin, LOW);
    delay(delaygap);
}

void dot_(){
    digitalWrite(pin, HIGH);
    delay(dot);
    digitalWrite(pin, LOW);
    delay(delaygap);
}

void stringchecker(){
    int length = morsecode.length();
    Serial.begin(9600);
    Serial.print(length);
    for(int i=0; i<length; i++){
        char morse = morsecode.charAt(i);
        
        if (morse == '-'){
            dash_();
        }
        else if (morse == '.'){
            dot_();
        }
        else if (morse == ' '){
            delay(completion);
        }
    }
}

void setup(){
    pinMode(pin, OUTPUT);
    stringchecker();
}

void loop(){
    
}