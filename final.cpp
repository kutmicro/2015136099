#include <MSGEQ7.h>

#include <Adafruit_NeoPixel.h>

#define MIN_K_value 100
#define MAX_K_value 200

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(40, 6, NEO_GRB + NEO_KHZ800);
//����
uint32_t sunny[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00ffff24, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00ffff24, 0x00000000,
  0x00ffff24, 0x00000000, 0x00ffff24, 0x00000000, 0x00000000, 0x00ffff24, 0x00000000, 0x00ffff24,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00ffff24, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00ffff24, 0x00000000,
  0x00000000, 0x00000000, 0x00ffff24, 0x00ffff24, 0x00ffff24, 0x00ffff24, 0x00000000, 0x00000000
};
//�帲
uint32_t cloudy[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00000000, 0x00030066, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00030066, 0x00030066, 0x00030066, 0x00000000, 0x00030066, 0x00000000, 0x00000000,
  0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00000000,
  0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066,
  0x00000000, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00030066, 0x00000000
};

//��

uint32_t rainy[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00000000, 0x00000000, 0x00993800, 0x00993800, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ff007f, 0x00ffbb00, 0x00faed7d, 0x00a566ff, 0x00000000, 0x00000000,
  0x00000000, 0x00ff007f, 0x00ffbb00, 0x00faed7d, 0x0086e57f, 0x005cd1e5, 0x00a566ff, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00993800, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00993800, 0x00993800, 0x00000000, 0x00000000, 0x00000000
};

//��

uint32_t snowy[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff,
  0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff,
  0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff,
};

//����

uint32_t thunder[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00000000, 0x00000000, 0x00ffe400, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00ffe400, 0x00ffe400, 0x00000000, 0x00ffe400, 0x00ffe400, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00ffe400, 0x00ffe400, 0x00ffe400, 0x00ffe400, 0x00ffe400, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffe400, 0x00ffe400, 0x00000000, 0x00ffe400, 0x00ffe400, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffe400, 0x00000000, 0x00000000, 0x00000000, 0x00000000
};

//���� S
uint32_t Seoul[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
};
//���� L
uint32_t London[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
};
//�ĸ� P
uint32_t Paris[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};
//���� N
uint32_t NewYork[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000,
};
//���� T
uint32_t Tokyo[40] =
{ //��ġ�� �ȼ� ������. ������ ��� �������� ���߾����!
  0x00000000, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00ffffff, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
  0x00000000, 0x00000000, 0x00000000, 0x00ffffff, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

void on_pixel_weather(int index, int weather_type) {
  switch (weather_type) {
    case 0:
      pixels.setPixelColor(index, sunny[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
    case 1:
      pixels.setPixelColor(index, cloudy[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
    case 2:
      pixels.setPixelColor(index, rainy[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
    case 3:
      pixels.setPixelColor(index, snowy[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
    case 4:
      pixels.setPixelColor(index, thunder[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
  }
}

void on_pixel_local(int index, int local_type) {
  switch (local_type) {
    case 0:
      pixels.setPixelColor(index, Seoul[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
    case 1:
      pixels.setPixelColor(index, London[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
    case 2:
      pixels.setPixelColor(index, Paris[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
    case 3:
      pixels.setPixelColor(index, NewYork[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
    case 4:
      pixels.setPixelColor(index, Tokyo[index]);//����ġ�� �´� ������ �����մϴ�.
      break;
  }
}
void setup() {
  pixels.begin();//�׿��ȼ��� ����ϱ� �����մϴ�.
  pixels.clear();//�׿��ȼ��� ����ϱ� �����մϴ�.
  

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
  for (int i = 0; i < 8; i++) { //�Է¹��� ��ȣ�� ���� �׿��ȼ��� �����մϴ�.
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
  //���� �ڵ尡 0���� 100���� ���� �ȿ� �ִٸ� type1 �������� led�� �����Ѵ�.
  //����
  if (weather >= 0 && weather < 100) {
    return 0;
  }
  else ;
  //���� �ڵ尡 100���� 200���� ���� �ȿ� �ִٸ� type2 �������� led�� �����Ѵ�.
  //�帲
  if (weather >= 100 && weather < 200) {
    return 1;
  }

  else ;

  //���� �ڵ尡 200���� 300���� ���� �ȿ� �ִٸ� type3 �������� led�� �����Ѵ�. 
  //��
  if (weather >= 200 && weather < 300) {
    return 2;
  }
  else ;
  //���� �ڵ尡 300���� 400���� ���� �ȿ� �ִٸ� type4 �������� led�� �����Ѵ�.
  //��
  if (weather >= 300 && weather < 400) {
    return 3;
  }
  else ;
  //���� �ڵ尡 400���� 500���� ���� �ȿ� �ִٸ� type4 �������� led�� �����Ѵ�.
  //õ��,����
  if (weather >= 400 && weather <= 500) {
    return 4;
  }
  else;
}

int get_local_type() {
   int local =random(1,5);
  
//�����ڵ尡 0�̸� ����� led�� �����Ѵ�. 
  if (local==0) {
    return 0;
  }
  else ;
  
//�����ڵ尡 1�̸� �������� led�� �����Ѵ�. 
  if (local==1) {
    return 1;
  }

  else ;

  
//�����ڵ尡 2�� �ĸ��� led�� �����Ѵ�. 
  if (local==2) {
    return 2;
  }
  else ;
  
//�����ڵ尡 3�� �������� led�� �����Ѵ�. 
  if (local==3) {
    return 3;
  }
  else ;
//�����ڵ尡 4�� ����� led�� �����Ѵ�. 
  if (local==4) {
    return 4;
  }
  else;
}