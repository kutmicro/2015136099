//날씨에 따른 led변화
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
날씨 type 1~3

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

