#01.01.2019
#S.w. (https://github.com/anilcanbulut)

#include "mbed.h"

Timer t;

DigitalOut seg1(D2);
DigitalOut seg2(D3);
DigitalOut seg3(D4);
DigitalOut seg4(D5);
DigitalOut seg5(D6);
DigitalOut seg6(D7);
DigitalOut seg7(D8);

DigitalOut led1(D13);
DigitalIn  button1(D10);

DigitalOut led2(D12);
DigitalIn  button2(D11);

DigitalOut buzzer(D9);

void reset();
void letter_A();
void letter_B();
void letter_C();
void letter_D();
void letter_E();
void letter_F();
void letter_G();
void letter_H();
void letter_I();

int main() {

int arr[4] = {0, 0, 0, 0};
int count = 0, count2 = 0, count3 = 0;
float duration = 0;

while(1) {
    do {
        if(button2 == 1) {
            led2 = 1;
            led1 = 0;
            buzzer = 0;
            break;
        }
        
        wait(0.2);
        if(button1 == 1) {
            led1=1;
            buzzer=1;
            if(count2 == 0) {
                t.start();
                count2 = 1;
                count3 = 1;
            }
                
        }else if(button1 == 0) {
            if(count3 == 1){    
                t.stop();
                duration = t.read();
                led1 = 0;
                buzzer = 0;
            
                if((duration < 1.0) && (duration > 0)) {
                    arr[count] = 1;
                    count++;
                }else if(duration > 3.0) {
                    arr[count] = 2;
                    count++;
                }else if((duration > 1.0) && (duration < 3.0)) {
                    letter_E();
                    wait(0.5);
                    reset();   
                }
                t.reset();  
                count2=0;
            }
            printf("%.2f      ", (duration));
              
        }
        
    }while(button2 == 0);
    
    led2 = 0;
    
    if((arr[0] == 1) && (arr[1] == 2) && (arr[2] == 0) && (arr[3] == 0)) {
        letter_A();
        wait(2);
        reset();
    }else if((arr[0] == 2) && (arr[1] == 1) && (arr[2] == 1) && (arr[3] == 1)) {
        letter_B();
        wait(2);
        reset();
    }else if((arr[0] == 2) && (arr[1] == 1) && (arr[2] == 2) && (arr[3] == 1)) {
        letter_C();
        wait(2);
        reset();
    }else if((arr[0] == 2) && (arr[1] == 1) && (arr[2] == 1) && (arr[3] == 0)) {
        letter_D();
        wait(2);
        reset();
    }else if((arr[0] == 1) && (arr[1] == 0) && (arr[2] == 0) && (arr[3] == 0)) {
        letter_E();
        wait(2);
        reset();
    }else if((arr[0] == 1) && (arr[1] == 1) && (arr[2] == 2) && (arr[3] == 1)) {
        letter_F();
        wait(2);
        reset();
    }else if((arr[0] == 2) && (arr[1] == 2) && (arr[2] == 1) && (arr[3] == 0)) {
        letter_G();
        wait(2);
        reset();
    }else if((arr[0] == 1) && (arr[1] == 1) && (arr[2] == 1) && (arr[3] == 1)) {
        letter_H();
        wait(2);
        reset();
    }else if((arr[0] == 1) && (arr[1] == 1) && (arr[2] == 0) && (arr[3] == 0)) {
        letter_I();
        wait(2);
        reset();
    }
    
    int i;
    for(i=0; i<4; i++) {
        arr[i] = 0;
    }
    count = 0;
    count2 = 0; 
    count3 = 0;
    duration = 0;
}

}

void letter_A() {
    
seg1=1;
seg2=0;
seg3=1;
seg4=1;
seg5=1;
seg6=1;
seg7=1;

}

void letter_B() {
    
seg1=1;
seg2=1;
seg3=1;
seg4=1;
seg5=1;
seg6=1;
seg7=1;

}

void letter_C() {
seg1=0;    
seg2=1;
seg3=1;
seg4=0;
seg5=1;
seg6=1;
seg7=0;
}

void letter_D() {
    
seg1=1;
seg2=1;
seg3=1;
seg4=1;
seg5=1;
seg6=1;
seg7=0;

}

void letter_E() {
seg1=0;
seg2=1;
seg3=1;
seg4=0;
seg5=1;
seg6=1;
seg7=1;

}

void letter_F() {
seg1=0;
seg2=0;
seg3=1;
seg4=0;
seg5=1;
seg6=1;
seg7=1;

}

void letter_G() {
    
seg1=1;
seg2=1;
seg3=1;
seg4=0;
seg5=1;
seg6=1;
seg7=1;

}

void letter_H() {
    
seg1=1;
seg2=0;
seg3=1;
seg4=1;
seg5=0;
seg6=1;
seg7=1;

}

void letter_I() {
    
seg1=1;
seg2=0;
seg3=0;
seg4=1;
seg5=0;
seg6=0;
seg7=0;
}  

void reset() {
    
seg1=0;
seg2=0;
seg3=0;
seg4=0;
seg5=0;
seg6=0;
seg7=0;
}  
