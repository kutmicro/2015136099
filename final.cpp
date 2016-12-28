#include <MSGEQ7.h>

#include <Adafruit_NeoPixel.h>

#define MIN_K_value 100
#define MAX_K_value 200

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(40, 6, NEO_GRB + NEO_KHZ800);
//맑음
uint32_t sunny[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00ffff24, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00ffff24, 0x00000000,
  0x00ffff24, 0x00000000, 0x00ffff24, 0x00000000, 0x00000000, 0x00ffff24, 0x00000000, 0x00ffff24,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00ffff24, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00ffff24, 0x00000000,
  0x00000000, 0x00000000, 0x00ffff24, 0x00ffff24, 0x00ffff24, 0x00ffff24, 0x00000000, 0x00000000
};
//흐림
uint32_t cloudy[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00000000, 0x00030066, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00030066, 0x00030066, 0x00030066, 0x00000000, 0x00030066, 0x00000000, 0x00000000,
  0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00000000,
  0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066,
  0x00000000, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00000000
};

//비

uint32_t rainy[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00000000, 0x00000000, 0x00993800, 0x00993800, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ff007f, 0x00ffbb00, 0x00faed7d, 0x00a566ff, 0x00000000, 0x00000000,
  0x00000000, 0x00ff007f, 0x00ffbb00, 0x00faed7d, 0x0086e57f, 0x005cd1e5, 0x00a566ff, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00993800, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00993800, 0x00993800, 0x00000000, 0x00000000, 0x00000000
};

//눈

uint32_t snowy[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff,
  0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff,
  0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff,
};

//번개

uint32_t thunder[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00000000, 0x00000000, 0x00ffe400, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00ffe400, 0x00ffe400, 0x00000000, 0x00ffe400, 0x00ffe400, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00ffe400, 0x00ffe400, 0x00ffe400, 0x00ffe400, 0x00ffe400, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffe400, 0x00ffe400, 0x00000000, 0x00ffe400, 0x00ffe400, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffe400, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};

//서울 S
uint32_t Seoul[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
};
//런던 L
uint32_t London[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
};
//파리 P
uint32_t Paris[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
//뉴욕 N
uint32_t NewYork[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
};
//도쿄 T
uint32_t Tokyo[40] =
{ //위치별 픽셀 색상설정. 마음에 드는 색조합을 맞추어보세요!
  0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

void on_pixel_weather(int index, int weather_type) {
  switch (weather_type) {
    case 0:
      pixels.setPixelColor(index, sunny[index]);//각위치에 맞는 색상을 선택합니다.
      break;
    case 1:
      pixels.setPixelColor(index, cloudy[index]);//각위치에 맞는 색상을 선택합니다.
      break;
    case 2:
      pixels.setPixelColor(index, rainy[index]);//각위치에 맞는 색상을 선택합니다.
      break;
    case 3:
      pixels.setPixelColor(index, snowy[index]);//각위치에 맞는 색상을 선택합니다.
      break;
    case 4:
      pixels.setPixelColor(index, thunder[index]);//각위치에 맞는 색상을 선택합니다.
      break;
  }
}

void on_pixel_local(int index, int local_type) {
  switch (local_type) {
    case 0:
      pixels.setPixelColor(index, Seoul[index]);//각위치에 맞는 색상을 선택합니다.
      break;
    case 1:
      pixels.setPixelColor(index, London[index]);//각위치에 맞는 색상을 선택합니다.
      break;
    case 2:
      pixels.setPixelColor(index, Paris[index]);//각위치에 맞는 색상을 선택합니다.
      break;
    case 3:
      pixels.setPixelColor(index, NewYork[index]);//각위치에 맞는 색상을 선택합니다.
      break;
    case 4:
      pixels.setPixelColor(index, Tokyo[index]);//각위치에 맞는 색상을 선택합니다.
      break;
  }
}
void setup() {
  pixels.begin();//네오픽셀을 사용하기 시작합니다.
  pixels.clear();//네오픽셀을 사용하기 시작합니다.
  

}

int cnt = 0;
int flag = 1;

void loop() {
  
  int local_type = get_local_type();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 5; j++) {
      on_pixel_local(i + (8 * j), local_type);
    }
  }
  pixels.show();

  delay(2000);

  if (flag == 1)
    pixels.clear();
  int weather_type = get_weather_type();
  for (int i = 0; i < 8; i++) { //입력받은 신호에 따라 네오픽셀을 제어합니다.
    for (int j = 0; j < 5; j++) {
      on_pixel_weather(i + (8 * j), weather_type);
    }
    pixels.show();

    switch (weather_type) {
   
      case 4:
        delay(100);
        flag = 1;
        break;
      default:
        delay(1000);
        flag = 0;
    }
   
  }

 
   
}
int get_weather_type() {
 //randomSeed(millis());
  //float rantime = random(20, 50);
  int weather = random(0,500);
  //날씨 코드가 0부터 100까지 범위 안에 있다면 type1 패턴으로 led를 제어한다.
  //맑음
  if (weather >= 0 && weather < 100) {
    return 0;
  }
  else ;
  //날씨 코드가 100부터 200까지 범위 안에 있다면 type2 패턴으로 led를 제어한다.
  //흐림
  if (weather >= 100 && weather < 200) {
    return 1;
  }

  else ;

  //날씨 코드가 200부터 300까지 범위 안에 있다면 type3 패턴으로 led를 제어한다. 
  //비
  if (weather >= 200 && weather < 300) {
    return 2;
  }
  else ;
  //날씨 코드가 300부터 400까지 범위 안에 있다면 type4 패턴으로 led를 제어한다.
  //눈
  if (weather >= 300 && weather < 400) {
    return 3;
  }
  else ;
  //날씨 코드가 400부터 500까지 범위 안에 있다면 type4 패턴으로 led를 제어한다.
  //천둥,번개
  if (weather >= 400 && weather <= 500) {
    return 4;
  }
  else;
}

int get_local_type() {
   int local =random(1,5);
  
//지역코드가 0이면 서울로 led를 제어한다. 
  if (local==0) {
    return 0;
  }
  else ;
  
//지역코드가 1이면 런던으로 led를 제어한다. 
  if (local==1) {
    return 1;
  }

  else ;

  
//지역코드가 2면 파리로 led를 제어한다. 
  if (local==2) {
    return 2;
  }
  else ;
  
//지역코드가 3면 뉴욕으로 led를 제어한다. 
  if (local==3) {
    return 3;
  }
  else ;
//지역코드가 4면 도쿄로 led를 제어한다. 
  if (local==4) {
    return 4;
  }
  else;
}