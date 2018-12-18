 

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <MHZ19_uart.h>

// You can use any (4 or) 5 pins 
#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8


// Color definitions
#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF
#define DBLUE           0x0005

const int rx_pin = 3;  //Serial rx pin no
const int tx_pin = 4; //Serial tx pin no

float x;
float co =310;
int co2a;
int blnk = 0;
float zw;
int alert;
int alert2;
int hell ;
int hel;
int phot;
int held;
int hella;
int z;
unsigned long time1;
unsigned long time2;
int sec;
int timestop;
int za;
int durch;
float sen;
int zwi;
int blnkz;
int t;
int secco;
int temp =20;
int tempa;
int to;


Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, rst);
MHZ19_uart mhz19;




void setup() {
  Serial.begin(9600);
  Serial.print("hello!");
  display.begin();
  mhz19.begin(rx_pin, tx_pin);
 mhz19.setAutoCalibration(true);
 //mhz19.calibrateZero();
 //mhz19.calibrateSpan(700);
  
 pinMode(2, OUTPUT); //Ton
 

  lcdTestPattern();
  delay(1500);
    

display.fillScreen(DBLUE);
display.drawRect(0, 0, 96, 64,GREEN);
//helligkeit();
  

  tone(2, 2000,100);
  display.setTextColor(CYAN);
  display.setCursor(23,15);
  display.setTextSize(1);
  display.println("CO2 Meter");
  display.setCursor(12, 29);
  display.println("Joerg Krause");
  display.setCursor(34,44);
  display.println("2018");
 
 delay(4000);

display.fillScreen(DBLUE);
display.drawRect(0, 0, 96, 64,GREEN);
helligkeit();



     tone(2, 800,500);
     delay(400);
     tone(2, 1300,200);
 
 //mhz19.calibrateZero(); //0 Kalibrierung an frischer Luft


}

void loop() {







if (((sec/3.0)!=(sec/3) && (co==310))){ 

 
  
  
  
  display.setTextColor(CYAN);
  display.setCursor(38, 3);
  display.setTextSize(1);
  display.println("warmup");

}

if (((sec/3.0)==(sec/3) && (co==310))){
  
  
  display.setTextColor(DBLUE);
  display.setTextSize(1);
  display.setCursor(38, 3);
  display.println("warmup");
}






 


if (sec>10){   // CO Einlesen alle 5 sec

co = mhz19.getPPM();

if (co<0){
  co=310;
}



temp = mhz19.getTemperature();

// co=co-100; //Korrekturfaktor
temp=temp-2;

sec=0;
}
 
//co=840;

//Serial.println(temp);
Serial.println(co);


 

//Serial.println(co);


 
 
 time1=millis();

  if (time1>(time2+500)) {
    time2=time1;
    sec=sec+1;
  //Serial.println(sec);
  }

 if (sec>600){
  sec=0; 
 }

 if (co>310 & to==0) {    //Löscht die Platzhalter vom Warmup
   to=1;
   display.setTextColor(DBLUE);
   display.setTextSize(2);
   display.setCursor(10, 17);
   display.println("----");
   tone(2, 2000,30);
   delay(100);
   tone(2, 2000,30);
} 
  
 

  
for (int i=0; i<10;i++) {
phot = analogRead(A0); //Helligkeits-Sensor abfragen
durch=durch+phot;
}
phot=durch/10;
durch=0;

//Serial.println(phot);
 
 
   hell=10-(phot/70);

   if (hell<0){
       hell=0;
    
   }

 // if (timestop==0){
    
  
 if (held!=hell) {
    held=hell;
    
    helligkeit();

  display.setTextColor(DBLUE);
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hella);
  display.setTextColor(CYAN);
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hell);
  hella=hell;
  
 }

//  }


  x=100*69*co/1600/100;

//Serial.println(x);
 
 if (co>1600) {
  x=74;
 }


  
 // Serial.println(x);
 // Serial.println(co);
  

 
 
 
 if (co<800) {                  //Begin Grün
  
  if (alert==1){
  
  display.fillScreen(DBLUE);
  display.drawRect(0, 0, 96, 64,GREEN);
  tone(2, 2000,100);
  alert=0;
 } 
 
 if (alert2==1){
 alert2=0;
 }

 if (zw!=co){

  display.setTextColor(DBLUE);
  display.setTextSize(1);
  display.setCursor(38, 3);
  display.println("warmup");

  display.fillRect(10, 40, 85, 10, DBLUE);
  display.drawRect(9, 39, 80, 12,WHITE);
  display.fillRect(10, 40, x-1, 10, GREEN); //Start, Position, Länge, Dicke
  display.drawRect(24, 40, 2, 10,BLUE);
  //display.drawRect(24, 40, 1, 10,GREEN);

   if (co>310){
  
  display.setTextColor(DBLUE);
  display.setCursor(62, 55);
  display.setTextSize(1);
  display.println("1500");
  
  display.setTextColor(DBLUE);
  display.setCursor(33, 55);
  display.setTextSize(1);
  display.println("800");

  display.setTextColor(CYAN);
  display.setCursor(18, 55);
  display.setTextSize(1);
  display.println("400");
  
  
  


  display.setTextColor(DBLUE);
  display.setTextSize(2);
  display.setCursor(10, 17);
  display.println(zwi);

  display.setTextColor(GREEN);
  display.setTextSize(2);
  display.setCursor(10, 17);
  co2a=int(co);
  display.println(co2a);

   }
  

  else {
  display.setTextColor(GREEN);
  display.setTextSize(2);
  display.setCursor(10, 17);
 
  display.println("----");

 }

  display.setCursor(65, 22);
  display.setTextSize(1);
  display.println("ppm");
  



  
  display.setTextColor(DBLUE);   //Ausgabe Temperatur und Helligkeit
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hella);
  display.setTextColor(CYAN);
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hell);
  hella=hell;

  display.setTextColor(DBLUE);
  display.setCursor(11, 3);
  display.setTextSize(1);
  display.println(tempa);
  display.setTextColor(CYAN);
  display.setCursor(11, 3);
  display.setTextSize(1);
  display.println(temp);
  display.setCursor(25, 3);
  display.println("C");
  tempa=temp;
  
  
  
  
  
  
  
  
  
  
  
  zwi=co2a;
 zw=co;

 }
 }

 if ((co>799) & (co<1500)){

if (blnk==1) {
  
  if (zw!=co){
  display.setTextColor(DBLUE);
  display.setTextSize(2);
  display.setCursor(10, 17);
  display.println(co2a);
  

  display.setTextColor(YELLOW);
  display.setTextSize(2);
  display.setCursor(10, 17);
  co2a=int(co);
  display.println(co2a);

display.setTextColor(DBLUE);   //Ausgabe Temperatur und Helligkeit
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hella);
  display.setTextColor(CYAN);
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hell);
  hella=hell;

  display.setTextColor(DBLUE);
  display.setCursor(11, 3);
  display.setTextSize(1);
  display.println(tempa);
  display.setTextColor(CYAN);
  display.setCursor(11, 3);
  display.setTextSize(1);
  display.println(temp);
  display.setCursor(25, 3);
  display.println("C");
  
  
  tempa=temp;


}
}





  
   
   
   if (alert2==1){
    alert2=0;
    }

  if (alert==0){              //Alarm Klick
  display.fillScreen(DBLUE);
  display.drawRect(0, 0, 96, 64,GREEN);
  tone(2, 2000,100);
  alert=1;
  blnk=0;
  blnkz=0;
  blnkz=sec;
 }
  

  
 if (zw!=co){
  display.setTextColor(DBLUE);
  display.setCursor(18, 55);
  display.setTextSize(1);
  display.println("400");
  
  
  display.setTextColor(CYAN);
  display.setCursor(33, 55);
  display.setTextSize(1);
  display.println("800");

   
  
  display.fillRect(10, 40, 85, 10, DBLUE);
  display.drawRect(9, 39, 80, 12,WHITE);
  display.fillRect(10, 40, 34, 10, GREEN);
  display.fillRect(44, 40, x-34, 10, YELLOW); //Start, Position, Länge, Dicke
 
  zw=co;
  }
  
  //Serial.println(blnk);
  
  if (blnk==0) {

    
    
    if (sec>(blnkz+9)){
        blnkz=0;
        blnk=1;      
    }
  
  if (((sec/3.0)==(sec/3) && (t==0))){
  
  t=1;
  display.setTextColor(DBLUE);
  display.setTextSize(2);
  display.setCursor(10, 17);
  display.println(zwi);
 
  display.setTextColor(DBLUE);   //Ausgabe Temperatur und Helligkeit
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hella);
  display.setTextColor(CYAN);
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hell);
  hella=hell;

  display.setTextColor(DBLUE);
  display.setCursor(11, 3);
  display.setTextSize(1);
  display.println(tempa);
  display.setTextColor(CYAN);
  display.setCursor(11, 3);
  display.setTextSize(1);
  display.println(temp);
  display.setCursor(25, 3);
  display.println("C");
  tempa=temp;
  
  
  
  
  
  
  }


 if (((sec/3.0)!=(sec/3) && (t==1))){
   //tone(2, 3000,10);
  t=0;
  display.setTextColor(DBLUE);
  display.setTextSize(2);
  display.setCursor(10, 17);
  display.println(zwi);
    
  display.setTextColor(YELLOW);
  display.setTextSize(2);
  display.setCursor(10, 17);
  co2a= int (co);
  display.println(co2a);
 
  display.setCursor(65, 22);
  display.setTextSize(1);
  display.println("ppm");
  zwi=co2a;

 }
   
  }

   }

 if (co>1499) {

  if (alert==1){
    alert=0;
  }

  if (alert2==0){     //Roter Alarm
  display.fillScreen(DBLUE);
  display.drawRect(0, 0, 96, 64,GREEN);
  tone(2, 2000,400);
  alert2=1;
   }
  display.setTextColor(DBLUE);   //Ausgabe Temperatur und Helligkeit
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hella);
  display.setTextColor(CYAN);
  display.setCursor(81, 3);
  display.setTextSize(1);
  display.println(hell);
  hella=hell;

  display.setTextColor(DBLUE);
  display.setCursor(11, 3);
  display.setTextSize(1);
  display.println(tempa);
  display.setTextColor(CYAN);
  display.setCursor(11, 3);
  display.setTextSize(1);
  display.println(temp);
  display.setCursor(25, 3);
  display.println("C");
  tempa=temp;
  
   
  
  
  if (blnk==0) {
  display.setTextColor(RED);
  display.setTextSize(2);
  display.setCursor(10, 17);
  co2a=int(co);
  display.println(co2a);
 
  display.setCursor(65, 22);
  display.setTextSize(1);
  display.println("ppm");
   blnk=1;
  delay(500);
  }
  
  if (blnk==1) {
  display.setTextColor(DBLUE);
  display.setTextSize(2);
  display.setCursor(10, 17);
  co2a=int(co);
  display.println(co2a);
 
  blnk=0;
  delay(500);
  }

  if (zw!=co) {
  display.fillRect(10, 40, 85, 10, DBLUE);  
  display.drawRect(9, 39, 80, 12,WHITE);
  display.fillRect(10, 40, 43, 10, GREEN);
  display.fillRect(44, 40, 30, 10, YELLOW);  
  display.fillRect(74, 40, x-60, 10, RED); //Start, Position, Länge, Dicke
  zw=co; 
  

  
  display.setTextColor(CYAN);
  display.setCursor(35, 55);
  display.setTextSize(1);
  display.println("800");
 
  display.setCursor(62, 55);
  display.setTextSize(1);
  display.println("1500");
  
  
  
  
  }

  
}

}

void helligkeit() {


 //SSD1331_CMD_MASTERCURRENT
 
   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x87);
   digitalWrite(cs, HIGH);

   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(hell);
   digitalWrite(cs, HIGH);


if (hell==0){



  //SSD1331_CMD_CONTRASTA
   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x081);
   digitalWrite(cs, HIGH);

   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x0);      //91
   digitalWrite(cs, HIGH);  

// SSD1331_CMD_CONTRASTB
   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x82);
   digitalWrite(cs, HIGH);

   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x0);      //50
   digitalWrite(cs, HIGH);

   // SSD1331_CMD_CONTRASTC
   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x83);
   digitalWrite(cs, HIGH);

   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x0);      //50
   digitalWrite(cs, HIGH);


  
}

if (hell>0){



  //SSD1331_CMD_CONTRASTA
   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x081);
   digitalWrite(cs, HIGH);

   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x91);      //91
   digitalWrite(cs, HIGH);  

// SSD1331_CMD_CONTRASTB
   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x82);
   digitalWrite(cs, HIGH);

   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x50);      //50
   digitalWrite(cs, HIGH);

   // SSD1331_CMD_CONTRASTC
   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x83);
   digitalWrite(cs, HIGH);

   digitalWrite(dc, LOW);
   digitalWrite(cs, LOW);
   SPI.transfer(0x50);      //50
   digitalWrite(cs, HIGH);


  
}




}





/* 
    @brief  Renders a simple test pattern on the LCD
*/

void lcdTestPattern(void)
{
 

  uint8_t w,h;
  display.setAddrWindow(0, 0, 96, 64);
  
  for(h=0; h<64; h++)
  {
    for(w=0; w<96; w++)
    {
      if(w>83){display.writePixel(WHITE);}
      else if(w>71){display.writePixel(BLUE);}
      else if(w>59){display.writePixel(GREEN);}
      else if(w>47){display.writePixel(CYAN);}
      else if(w>35){display.writePixel(RED);}
      else if(w>23){display.writePixel(MAGENTA);}
      else if(w>11){display.writePixel(YELLOW);}
      else {display.writePixel(BLACK);}
    }
  }
  display.endWrite();
  

}
