//������ ���� led��ȭ
void weatherpixel(){
   float rantime = random(20,50);
   //���� �ڵ尡 200���� 531���� ���� �ȿ� �ִٸ� type3 �������� led�� �����Ѵ�.
   //��, ��, ���
  if(weather>199 && weather<532){   
    type3();
  }
  else ;
   //���� �ڵ尡 701���� 781, �Ǵ� 802����  804���� ���� �ȿ� �ִٸ� type2 �������� led�� �����Ѵ�.
   //�帲
  if(weather>700 && weather <782){
    type2();
  }
  else ;
  if(weather>801 && weather<805){
    type2();
  }
  else ;
  
  //���� �ڵ尡 800���� 801
  //�帲
  if(weather>799 && weather<802){   
     type1();
   }
   else ;
}
���� type 1~3

void type1(){
  
  rainbow(60);
  }
void type2(){
   uint16_t i, j;
  for(j=0; j<256; j+=1) {
    for(i=0; i       int sum = i+j;
      map(sum,0,300,120,190);
     strip.setPixelColor(i, Wheel(sum),Wheel(sum),Wheel(sum));
//led�� ������ �����Ѵ�.(n,����,���,û��)
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
    theaterChase(strip.Color(255, 255, 0), 60); //��� ��� 
}

���� �����͸� ���� ���� �κ�. 

   if ( currentLine.endsWith("         readingWeather = true; 
        weatherString = " ";       }      
      if (readingWeather) {
        if (inChar != 'v') { //���� ���۵� ���ڰ� 'v'�� �ƴ϶�� ��� ���� ������(�ڵ�)�� �޴´�.
          weatherString += inChar;
        } 
        else { //���� ���۵� ���ڰ� 'v'��� ���� ������(�ڵ�)�� ����Ѵ�.
          readingWeather = false;
          weather = getInt(weatherString);
          weatherpixel();
          Serial.print("weather code: ");
          Serial.println(weather);
        }
      }

