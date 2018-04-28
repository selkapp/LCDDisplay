/*
 
 
  PROGRAMLAMA LABORATUVARI II
  PROJE 3

  Programın Amacı:
  4 adet farklı renkte LEDi rastgele bir biçimde yakıp, LCD ekranda istenilen yazıları,istenilen sırayla,istenilen şekilde yazdırmak. 
  
  Kullanılan Malzemeler:
  * TM4C123GXL Tiva C Lanchpad. 
  * LCD Display.
  * 10-kilohm Potentiometer   (2 adet). 
  * 330 ohm'luk Direnç        (4 adet).
  * Jumper                    (22 adet)

  Kod editörü  : Energia 1.6.10E18
  
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,13,12,11);

const int LEDpin_red = 31;
const int LEDpin_white = 32;
const int LEDpin_green = 33;
const int LEDpin_blue = 34;

int my_random(int a ,int b){        //Ayni degeri tekrar etmeden Rastgele bir değer döndüren fonksiyon (a ve b arasında)

  int x = random(a,b);    
  int y = random(a,b);

  if (x == y){
    int z = random(a,b);
    if (z != x && z != y)
      return z;
  }else{
    return x;
  }
}

void lcd_red(LiquidCrystal lcd){    // Kırmızı led yandığında ekrana yazan fonkisyon
      lcd.clear();
      lcd.setCursor(0,0);            
      lcd.print("Kocaeli uni");
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("Test Test");
      delay(3000);
}

void lcd_white(LiquidCrystal lcd){  // Beyaz led yandığında ekrana yazan fonkisyon
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Test Test");
      delay(2000);
      lcd.setCursor(0,1);
      lcd.print("Kocaeli uni");
      delay(3000);
}

void lcd_green(LiquidCrystal lcd){  // Yeşil led yandığında ekrana yazan fonkisyon
    int i;
   
    lcd.setCursor(0,0);             //Ekrandaki yazma pointerinin konumunu değiştirir, (0,0)= sifirinci sutun , sifirinci satir.
    lcd.print("Kocaeli uni");
    delay(1000);
    for (i=0;i<16;i++){
     lcd.scrollDisplayRight();      //sağa kaydır.
     delay(500);
    }
    
    delay(2000);
    lcd.clear();
    
    lcd.setCursor(0,1);
    lcd.print("Test Test");
    delay(1000);
    
    for (i=0;i<16;i++){
     lcd.scrollDisplayRight();
     delay(500);
    }
    
    delay(3000);
    lcd.clear();
    
}

void lcd_blue(LiquidCrystal lcd){   // Mavi led yandığında ekrana yazan fonksiyon.
    int i;
    
    lcd.setCursor(16,0);            //Ekrandaki yazma pointerinin yerini koordinatlara gore değiştir.
    lcd.print("Kocaeli uni");
    for (i=0;i<29;i++){             // metinin kayarak kaybolmasını sağlar
     lcd.scrollDisplayLeft();       //Sola kaydırma
     delay(500);
    }
    
    delay(2000);
    lcd.clear();
    
    lcd.setCursor(16,1);
    lcd.print("Test Test");
    for (i=0;i<29;i++){
     lcd.scrollDisplayLeft();
     delay(500);
    }
    
    delay(3000);
    lcd.clear();
   
}
/*--------------------------------END OF LCD FUNCTIONS -------------------------*/
void setup() {

  pinMode(LEDpin_red,OUTPUT);
  pinMode(LEDpin_white,OUTPUT);
  pinMode(LEDpin_green,OUTPUT);
  pinMode(LEDpin_blue,OUTPUT);

  lcd.begin(16,2);  
  Serial.begin(9600);
  
}

void loop() {

  lcd.clear();
  int x = my_random(31,35);                       //LED Pinleri arasında rastgele seç 
  
  digitalWrite(x,HIGH);                           //Rastgele LED'i Yak

  switch(x){                                      // LED'in rengine gore farklı işlemler yap
      case LEDpin_red   :lcd_red(lcd);break;
      case LEDpin_white :lcd_white(lcd);break;
      case LEDpin_green :lcd_green(lcd);break;
      case LEDpin_blue  :lcd_blue(lcd);break;
      default:break;
    }
  
  //işlem bittiğinde tüm LEDleri söndür
  digitalWrite(LEDpin_red,LOW);
  digitalWrite(LEDpin_white,LOW);
  digitalWrite(LEDpin_green,LOW);
  digitalWrite(LEDpin_blue,LOW);

}
