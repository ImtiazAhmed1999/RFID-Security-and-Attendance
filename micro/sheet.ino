bool sendDataToIFTTT(String a, String b, String c) {
  WiFiClient client;
  if (client.connect("maker.ifttt.com", 80)) {
    String postData = "value1=" + String(a) +"&value2=" + String(b) +"&value3=" + String(c);
    String url = "/trigger/request/with/key/" + iftttWebhookKey;

    client.print("POST " + url + " HTTP/1.1\n");
    client.print("Host: maker.ifttt.com\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postData.length());
    client.print("\n\n");
    client.print(postData);

    delay(10);

    while (client.available()) {
      char c = client.read();
      Serial.print(c);
    }

    client.stop();
    return true;
  }
  return false;
}