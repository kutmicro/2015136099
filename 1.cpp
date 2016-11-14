#include "SPI.h"
#include "WiFi.h"
#include "Adafruit_WS2801.h"
//////인스턴스 및 변수를 정의하는 부분(위 부분은 Wifi통신 및 데이터 출력을 위해 필요한 변수들을 선언하는 부분이다. 통신을 위해서는 WiFi의 SSID와 Password가 필요하며, 80포트를 사용하는 서버와 Client가 필요하다. 데이터를 출력하기 위해서는 서버에서 전송된 Character값을 모아서 문자열을 생성하는 currentLine과 날씨. 시간값의 존재여부를 판단하는 boolean변수와 저장하는 String변수, 문자열값을 숫자데이터로 바꾼 값을 저장하는 temp변수가 필요하다.)
#ifdef __AVR_ATtiny85__
 #include
#endif
char ssid[] = "yeony";       //와이파이 SSID
char pass[] = "04020402";   //와이파이 password 

//인스턴스 변수 초기화
WiFiServer server(80);
WiFiClient client;

const unsigned long requestInterval = 60000;  // 요구 시간 딜레이(1 min)
IPAddress hostIp;
uint8_t ret;
unsigned long lastAttemptTime = 0;
// 마지막으로 서버에서 데이터를 전송받은 시간
String weatherString = "";    // 날씨 정보 변수
String timeString = "";       // 시간 정보 변수
String location = "kiev";
boolean readingWeather = false; // 날씨 데이터가 있는지 여부 판단
boolean readingTime = false;    // 시간 데이터가 있는지 여부 판단
boolean stringComplete = false;
int weather;
int temp = 0;
uint8_t dataPin  = 2;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 3;    // Green wire on Adafruit Pixels
int lednum = 30;
Adafruit_WS2801 strip = Adafruit_WS2801(25, dataPin, clockPin);
// 네오픽셀을 사용하기위해 객체를 생성하고 첫 번째 인자는 LED개수 두 번째 인자는 아두이노 핀번호 , 세 번째 인자는 [네오픽셀에 다라 바뀌는 flag]
void setup() {
  //각 변수에 정해진 공간 할당
  Serial.begin(115200);    
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); //clock을 16Mhz로 사용
#endif
  strip.begin();
//LEDstrip loop를 실행시키기 위해 모든 LED를 off시키며 초기화

  strip.show(); //역할은 코드에서 작성한 명령을 NeoPixel로 넘겨 실제로 LED를 켜고 끄는 명령을 하게 하는 함수
  delay(10);
  //WiFi연결 시도(Setup()에서는 WiFi쉴드를 통해 웹에 연결을 시도하게 된다. WiFi.begin(ssid,pass)를 통해 WiFi에 연결을 시도하고 server.begin()을 통해 서버를 초기화 한다. 연결에 성공했다면 "Connect success!"메시지를 출력하게 되며 Wifi정보를 출력하게 되고 connectToServer()를 통해 클라이언트는 서버에 연결을 시도하게 된다.)
  Serial.println("Connecting to WiFi....");  
  WiFi.begin(ssid, pass);  //WiFi가 패스워드를 사용한다면 매개변수에 password도 작성
  server.begin();
  Serial.println("Connect success!");
  Serial.print("Waiting for DHCP address");
  //DHCP주소를 기다린다
  while(WiFi.localIP() == INADDR_NONE) {
    Serial.print(".");
    delay(300);
  }
  Serial.println("\n");
  printWifiData();
  connectToServer();
}
void loop()
{
  
 if (client.connected()) {
    while (client.available()) {
      //전송된 데이터가 있을 경우 데이터를 읽어들인다.
      char inChar = client.read();
      // 읽어온 데이터를 inChar에 저장한다.
      currentLine += inChar; 
      //inChar에 저장된 Char변수는 currentLine이라는 String변수에 쌓이게 된다.
      
      //라인피드(줄바꿈)문자열이 전송되면 데이터를 보내지 않는다.
      if (inChar == '\n') {
        //Serial.print("clientReadLine = ");
        //Serial.println(currentLine);
        currentLine = "";
      } 
        // 온도 데이터가 전송되었는지 확인
   if ( currentLine.endsWith("<weather number=")) 
 // 현재 스트링이 "< weather number="로 끝났다면 날씨 데이터를 받을 준비를 한다.
        readingWeather = true; 
        weatherString = "";
      }      
      //<weater number= 뒤에 오는 문자열을 weatherString에 저장한다.
     if ( currentLine.endsWith("readingWeather = true weatherString = " "; }      
      if (readingWeather) {
        if (inChar != 'v') { //다음 전송될 문자가 'v'가 아니라면 계속 날씨 데이터(코드)를 받는다.
          weatherString += inChar;
        } 
        else { //다음 전송된 문자가 'v'라면 날씨 데이터(코드)를 출력한다.
          readingWeather = false;
          weather = getInt(weatherString);
          weatherpixel();
          Serial.print("weather code: ");
          Serial.println(weather);
        }
      }
      
         if ( currentLine.endsWith("<lastupdate value=")) {
        // 현재 스트링이 "<lastupdata value="로 끝났다면 마지막 업데이트 시간 데이터를 받을 준비를 한다.
        readingTime = true; 
        timeString = "";
      }
      if (readingTime) {
        if (inChar != '/') { //다음 전송될 문자가 '/'가 아니라면 계속적으로 시간데이터를 받는다
          timeString += inChar;
        } 
        else {
          readingTime = false;
          Serial.print("last update: ");
          Serial.println(timeString.substring(2,timeString.length()-1));
        }
      }
        
             
      if ( currentLine.endsWith("")) { //현재 스트링이 로 끝났다면 연결을 끊고 다시 서버와 연결을 준비한다.
       
        delay(100); //10초뒤에 서버와 연결을 끊고 재연결을 시도한다.
        client.stop(); 
//         serialEvent();
//         if (stringComplete) {
//          Serial.println(location); 
//    // clear the string:
//          stringComplete = false;
//          }
        connectToServer();
        //Serial.println("Disconnected from Server.\n");
      }
    }   
  }
  else if (millis() - lastAttemptTime > requestInterval) {
    //연결을 실패했다면 requestInterval(60초)이후에 다시 연결을 시도한다.
    connectToServer();
  }  
}
//서버와 연결
void connectToServer() {
  Serial.println("");
  Serial.println("connecting to server...");
  String content = "";
  if (client.connect(hostIp, 80)) {
    Serial.println("Connected! Making HTTP request to api.openweathermap.org for "+location+"...");
    //Serial.println("GET /data/2.5/weather?q="+location+"&mode=xml");
    client.println("GET /data/2.5/weather?q="+location+"&mode=xml"); 
    //위에 지정된 주소와 연결한다.
    client.print("HOST: api.openweathermap.org\n");
    client.println("User-Agent: launchpad-wifi");
    client.println("Connection: close");
    client.println();
    Serial.println("Weather information for "+location);
  }
  //마지막으로 연결에 성공한 시간을 기록
  lastAttemptTime = millis();
}

void printHex(int num, int precision) {
  char tmp[16];
  char format[128];
  sprintf(format, "%%.%dX", precision);
  sprintf(tmp, format, num);
  Serial.print(tmp);
}
void printWifiData() {
  // Wifi쉴드의 IP주소를 출력
  Serial.println();
  Serial.println("IP Address Information:");  
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  //MAC address출력
  byte mac[6];  
  WiFi.macAddress(mac);
  Serial.print("MAC address: ");
  printHex(mac[5], 2);
  Serial.print(":");
  printHex(mac[4], 2);
  Serial.print(":");
  printHex(mac[3], 2);
  Serial.print(":");
  printHex(mac[2], 2);
  Serial.print(":");
  printHex(mac[1], 2);
  Serial.print(":");
  printHex(mac[0], 2);
  Serial.println();
  //서브넷 마스크 출력
  IPAddress subnet = WiFi.subnetMask();
  Serial.print("NetMask: ");
  Serial.println(subnet);
  //게이트웨이 주소 출력
  IPAddress gateway = WiFi.gatewayIP();
  Serial.print("Gateway: ");
  Serial.println(gateway);
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  ret = WiFi.hostByName("api.openweathermap.org", hostIp);
  Serial.print("ret: ");
  Serial.println(ret);
  Serial.print("Host IP: ");
  Serial.println(hostIp);
  Serial.println("");
}
int getInt(String input){  //String데이터를 intger형으로 변환하는 함수
  int i = 2;
  while(input[i] != '"'){
    i++;
  }
  input = input.substring(2,i);
  char carray[20];
  //Serial.println(input);
  input.toCharArray(carray, sizeof(carray));
  //Serial.println(carray);
  temp = atoi(carray);
  //Serial.println(temp);
  return temp;
}
void weatherpixel(){
   float rantime = random(20,50);
   //날씨 코드가 200부터 531까지 범위 안에 있다면 type3 패턴으로 led를 제어한다.
   //비, 눈, 우박
  if(weather>199 && weather<532){   
    type3();
  }
  else ;
   //날씨 코드가 701부터 781, 또는 802부터  804까지 범위 안에 있다면 type2 패턴으로 led를 제어한다.
   //흐림
  if(weather>700 && weather <782){
    type2();
  }
  else ;
  if(weather>801 && weather<805){
    type2();
  }
  else ;
  
  //날씨 코드가 800부터 801
  //흐림
  if(weather>799 && weather<802){   
     type1();
   }
   else ;
}

void type1(){
  
  rainbow(60);
  }
void type2(){
   uint16_t i, j;
  for(j=0; j<256; j+=1) {
    for(i=0; i       int sum = i+j;
      map(sum,0,300,120,190);
     strip.setPixelColor(i, Wheel(sum),Wheel(sum),Wheel(sum));
//led의 색상을 설정한다.(n,적색,녹색,청색)
    }
    strip.show();
    delay(10);
  }
}
void type3(){
   uint16_t i, j,q;
 for(q=0; q   for(j=0; j<256; j+=1) {
    for(i=0; i       int sum = i+j;
      map(sum,0,300,120,190);
     strip.setPixelColor(i, Wheel(sum),Wheel(sum),0);
    }
    strip.show();
    delay(10);
  }
 }
    theaterChase(strip.Color(255, 255, 0), 60); //흰색 출력 
}

//모든 LED를 출력가능한 모든색으로 한번씩 보여주는 동작을 한번하는 함수
void rainbow(uint8_t wait) {
  uint16_t i, j;
  for(j=0; j<256; j++) {
    for(i=0; i       strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//입력한 색으로 LED를 깜빡거리며 표현한다
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) { 
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c); 
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0); 
      }
    }
  }
}
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//255가지의 색을 나타내는 함수
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
 
 

날씨 데이터를 가져 오는 부분. 

 
   if ( currentLine.endsWith("         readingWeather = true; 
        weatherString = " ";       }      
      if (readingWeather) {
        if (inChar != 'v') { //다음 전송될 문자가 'v'가 아니라면 계속 날씨 데이터(코드)를 받는다.
          weatherString += inChar;
        } 
        else { //다음 전송된 문자가 'v'라면 날씨 데이터(코드)를 출력한다.
          readingWeather = false;
          weather = getInt(weatherString);
          weatherpixel();
          Serial.print("weather code: ");
          Serial.println(weather);
        }
      }

