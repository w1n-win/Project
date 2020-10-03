//======================ARDUINO PROJECT======================
//PROJECT NAME : VOLTAGE DATA LOGGER
//START DATE   : 2020 Sep 28
//VERSION      : 0.1
//UPDATE DATE  : 2020 Sep 28
//TARGET BOARD : Arduino Uno
//                 Data Logging Shield V1.0 (Deek-Robot)
//                 2.4" TFT LCD Shield (MCUFriend), Mod. "LCD_RST" (Pull Up Vcc)
//AUTHOR       : Winata Panjaya
//=====================^ARDUINO PROJECT^=====================

//=======================PIN RESOURCE========================
//                             // 13[PB5/SCK] := SD_SCK
//                             // 12[PB4/MISO]:= SD_DO
//                             // 11[PB3/MOSI]:= SD_DI
//                             // 10[PB2/SS   := SD_CS
//                             // 9 [PB1]     := LCD_D0
//                             // 8 [PB0]     := LCD_D0
//                             //
//                             // 7 [PD7]     := LCD_D7
//                             // 6 [PD6]     := LCD_D6
// A0[PC0]    := LCD_RD        // 5 [PD5]     := LCD_D5
// A1[PC1]    := LCD_WR        // 4 [PD4]     := LCD_D4
// A2[PC2]    := LCD_RS        // 3 [PD3]     := LCD_D3
// A3[PC3]    := LCD_CD        // 2 [PD2]     := LCD_D2
// A4[PC4/SDA]:= RTC_SDA       // 1 [PD1/Tx]  := 
// A5[PC5/SCL]:= RTS_SCL       // 0 [PD0/Rx]  := 
//======================^PIN RESOURCE^=======================

//==========================LIBRARY==========================
#include "Adafruit_GFX.h"    // Core graphics library
#include "MCUFRIEND_kbv.h"   // Hardware specific library

#include "MonoIcon_Set_32x32.h"
//#include "Fonts/FreeSans9pt7b.h"
//#include "Fonts/FreeSans12pt7b.h"
//#include "Fonts/FreeSerif12pt7b.h"
//#include "FreeDefaultFonts.h"
//#include "FreeSevenSegNumFontPlusPlus.h"
//=========================^LIBRARY^=========================

//===========================CLASS===========================
MCUFRIEND_kbv tft;
//==========================^CLASS^==========================

//====================VARIABLE DECLARATION===================
//GRAYSCALE            RGB565      RGB                  HEX
#define C_BLACK        0x0000      //rgb(  0,  0,  0) 	#000000  
#define C_GREYDARK     0x528A      //rgb( 80, 80, 80)   #505050
#define C_GREY         0xAD55      //rgb(169,169,169) 	#A9A9A9 
#define C_SILVER       0xC618      //rgb(192,192,192) 	#C0C0C0   
#define C_GREYLIGHT    0xDEFB      //rgb(220,220,220) 	#DCDCDC
#define C_WHITESNOW    0xFFDF      //rgb(250,250,250)   #FAFAFA
#define C_WHITE        0xFFFF      //rgb(255,255,255) 	#FFFFFF 
//RED                  RGB565      RGB                  HEX
#define C_RED          0xF800      //rgb(255,  0,  0) 	#FF0000
#define C_MAROON       0x8800      //rgb(139,  0,  0)   #8B0000
#define C_CRIMSON      0xD8A7      //rgb(220, 20, 60)   #DC143C 
#define C_REDCORAL     0xF410      //rgb(240,128,128) 	#F08080
//PINK                 RGB565      RGB                  HEX
#define C_PINK         0xFDB8      //rgb(255,182,193) 	#FFB6C1 
#define C_MAGENTA      0xF81F      //rgb(255  ,0,255) 	#FF00FF 
#define C_PINKDEEP     0xF8B2      //rgb(255, 20,147) 	#FF1493 
#define C_PINKHOT      0xFB56      //rgb(255,105,180) 	#FF69B4
#define C_PINKLIGHT    0xFF3C      //rgb(255,228,225) 	#FFE4E1
//PURPLE               RGB565      RGB                  HEX
#define C_PURPLE       0x780F      //rgb(128,  0,128) 	#800080 
#define C_INDIGO       0x4810      //rgb( 75,  0,130) 	#4B0082 
#define C_PURPLEDARK   0x901A      //rgb(148,  0,211) 	#9400D3 
#define C_VIOLET       0xEC1D      //rgb(238,130,238) 	#EE82EE
#define C_PURPLELIGHT  0xDD1B      //rgb(221,160,221) 	#DDA0DD
//GREEN                RGB565      RGB                  HEX
#define C_GREEN        0x07E0      //rgb(  0,255,  0) 	#00FF00
#define C_GREENDARK    0x03E0      //rgb(  0,128,  0) 	#008000
#define C_OLIVE        0x7BE0      //rgb(128,128,  0) 	#808000 
#define C_GREENYELLOW  0xAFE5      //rgb(173,255, 47) 	#ADFF2F
#define C_GREENSPRING  0x07EF      //rgb(  0,255,127) 	#00FF7F
#define C_GREENPALE    0x9FD3      //rgb(152,251,152) 	#98FB98 
//CYAN                 RGB565      RGB                  HEX
#define C_CYAN         0x07FF      //rgb(  0,255,255) 	#00FFFF
#define C_CYANDARK     0x03EF      //rgb(  0,128,128) 	#008080 
#define C_TURQUOISE    0x471A      //rgb( 64,224,208) 	#40E0D0  
#define C_AQUAMARINE   0x7FFA      //rgb(127,255,212) 	#7FFFD4  
#define C_CYANLIGHT    0xE7FF      //rgb(224,255,255) 	#E0FFFF 
//BLUE                 RGB565      RGB                  HEX
#define C_BLUE         0x001F      //rgb(  0,  0,255) 	#0000FF 
#define C_BLUENIGHT    0x000A      //rgb(  0,  0, 82) 	#000052 
#define C_BLUENAVY     0x0010      //rgb(  0,  0,128) 	#000080 
#define C_BLUEROYAL    0x435C      //rgb( 65,105,225) 	#4169E1
#define C_BLUESKY      0x867D      //rgb(135,206,235) 	#87CEEB
#define C_BLUELIGHT    0xB71C      //rgb(176,224,230) 	#B0E0E6
//ORANGE                 RGB565      RGB                  HEX
#define C_ORANGE       0xFDA0      //rgb(255,180,  0)   #FFB400
#define C_ORANGERED    0xFA20      //rgb(255, 69,  0)  	#FF4500
#define C_ORANGESALMON 0xFD0F      //rgb(255,160,122) 	#FFA07A
//YELLOW                 RGB565      RGB                  HEX
#define C_YELLOW       0xFFE0      //rgb(255,255,  0) 	#FFFF00
#define C_GOLD         0xFEA0      //rgb(255,215,  0) 	#FFD700
#define C_YELLOWLIGHT  0xFFEC      //rgb(255,255,100) 	#FFFF64
//BROWN                RGB565      RGB                  HEX
#define C_BROWN        0xA145      //rgb(165, 42, 42) 	#A52A2A 
#define C_BROWNDARK    0x8A22      //rgb(139, 69, 19) 	#8B4513 
#define C_CHOCOLATE    0xD343      //rgb(210,105, 30) 	#D2691E
#define C_BROWNLIGHT   0xDDD0      //rgb(222,184,135) 	#DEB887
#define C_KHAKIDARK    0xF731      //rgb(240,230,140) 	#F0E68C
#define C_KHAKI        0xBDAD      //rgb(189,183,107) 	#BDB76B

//int a = 3000;
//int b = 4000;
//int j, j2;
//int i, i2;
int col[8];
//===================^VARIABLE DECLARATION^==================

void ShowMsgXY(int x, int y, int sz, uint16_t clor,const GFXfont *f, const char *msg)
{
  tft.setFont(f);
  tft.setCursor(x, y);
  tft.setTextColor(clor);
  tft.setTextSize(sz);
  tft.print(msg);
}

void setup()
{
  tft.reset();
  uint16_t TFTID = tft.readID();
  tft.begin(TFTID);
  tft.setRotation(1);         //0=landscape, 1=Portrait, 2=180 Landscape, 3=180 Portrait.
  tft.invertDisplay(false);   //Inverting Screen Colors
  tft.fillScreen(C_BLUENIGHT);
 
  col[0] = tft.color565(155,   0,  50);
  col[1] = tft.color565(170,  30,  80);
  col[2] = tft.color565(195,  60, 110);
  col[3] = tft.color565(215,  90, 140);
  col[4] = tft.color565(230, 120, 170);
  col[5] = tft.color565(250, 150, 200);
  col[6] = tft.color565(255, 180, 220);
  col[7] = tft.color565(255, 210, 240);
}

void loop(void)
{
//  tft.drawRGBBitmap(5, 75, test, 52, 38);          //Color Image
//  tft.drawBitmap(  5,  15, Line1, 45, 45, 0xffff);  //Monocrome Battery Icon
//  tft.drawBitmap( 60,  15, Line2, 45, 45, 0xffff);  //Monocrome Wifi Icon
//  tft.drawBitmap(130,  20, Line3, 45, 45, 0xffff);  //Monocrome Mail Icon
//  tft.drawBitmap(200,  20, Line4, 45, 45, 0xffff);  //Monocrome Instagram Icon
//  tft.drawBitmap(265,  20, Line6, 45, 45, 0xffff);  //Monocrome Twitter Icon
//  tft.drawBitmap(  5, 130, Line7, 45, 45, 0xffff);  //Monocrome Rain Icon
//  tft.drawBitmap(  5, 190, Line5, 45, 45, 0xffff);  //Monocrome Power Icon

//  ShowMsgXY(160, 180, 1, C_YELLOW, &FreeSevenSegNumFontPlusPlus, "20:42");
//  ShowMsgXY(160, 210, 1, C_WHITE, &FreeSans12pt7b, "Sunday");
//  ShowMsgXY(160, 235, 1, C_PINK, &FreeSerif12pt7b, "2020 Sep 27");
  tft.fillRoundRect(  2,199,60,40,5,C_BLUEROYAL); 
  tft.fillRoundRect(  4,204,56,36,4,C_BLUENAVY);  
  
  tft.fillRoundRect( 66,199,60,40,5,C_BLUEROYAL); 
  tft.fillRoundRect( 68,204,56,36,4,C_BLUENAVY);  
  
  tft.fillRoundRect(130,199,60,40,5,C_BLUEROYAL); 
  tft.fillRoundRect(132,204,56,36,4,C_BLUENAVY);  
  
  tft.fillRoundRect(194,199,60,40,5,C_BLUEROYAL); 
  tft.fillRoundRect(196,204,56,36,4,C_BLUENAVY);  
  
  tft.fillRoundRect(258,199,60,40,5,C_BLUEROYAL); 
  tft.fillRoundRect(260,204,56,36,4,C_BLUENAVY);    
  
  tft.fillRoundRect(  0,194,64,45,5,C_BLUEROYAL); 
  tft.fillRoundRect(  2,200,60,40,4,C_BLUE); 

  tft.drawBitmap( 16,205,MonoIcon_Home_32x32   ,32,32,C_YELLOW);  
  tft.drawBitmap( 80,205,MonoIcon_Graph_32x32  ,32,32,C_WHITE); 
  tft.drawBitmap(144,205,MonoIcon_Disket_32x32 ,32,32,C_WHITE); 
  tft.drawBitmap(208,205,MonoIcon_Setting_32x32,32,32,C_WHITE); 
  tft.drawBitmap(272,205,MonoIcon_Info_32x32   ,32,32,C_WHITE); 
  
  for (int i = 8; i > 0; i--) {
    tft.fillCircle(125 + 20 * (cos(-(i + 0)*3.1416 / 4)), 120 + 20 * (sin(-(i + 0)*3.1416 / 4)), 5, col[0]); delay(15);
    tft.fillCircle(125 + 20 * (cos(-(i + 1)*3.1416 / 4)), 120 + 20 * (sin(-(i + 1)*3.1416 / 4)), 5, col[1]); delay(15);
    tft.fillCircle(125 + 20 * (cos(-(i + 2)*3.1416 / 4)), 120 + 20 * (sin(-(i + 2)*3.1416 / 4)), 5, col[2]); delay(15);
    tft.fillCircle(125 + 20 * (cos(-(i + 3)*3.1416 / 4)), 120 + 20 * (sin(-(i + 3)*3.1416 / 4)), 5, col[3]); delay(15);
    tft.fillCircle(125 + 20 * (cos(-(i + 4)*3.1416 / 4)), 120 + 20 * (sin(-(i + 4)*3.1416 / 4)), 5, col[4]); delay(15);
    tft.fillCircle(125 + 20 * (cos(-(i + 5)*3.1416 / 4)), 120 + 20 * (sin(-(i + 5)*3.1416 / 4)), 5, col[5]); delay(15);
    tft.fillCircle(125 + 20 * (cos(-(i + 6)*3.1416 / 4)), 120 + 20 * (sin(-(i + 6)*3.1416 / 4)), 5, col[6]); delay(15);
    tft.fillCircle(125 + 20 * (cos(-(i + 7)*3.1416 / 4)), 120 + 20 * (sin(-(i + 7)*3.1416 / 4)), 5, col[7]); //delay(15);
  }

 
// while (1);    //HALT
} 
// END
