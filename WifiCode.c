void printWifiData() {
  // Wifi������ IP�ּҸ� ���
  Serial.println();
  Serial.println("IP Address Information:");  
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  //MAC address���
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
  //����� ����ũ ���
  IPAddress subnet = WiFi.subnetMask();
  Serial.print("NetMask: ");
  Serial.println(subnet);
  //����Ʈ���� �ּ� ���
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