void clearDisplay() {
  display.clearDisplay();
  display.display();
}

void text(int x, int y, String msg){
  display.setCursor(x, y);
  // display.println("Received Message:");
  display.println(msg);
  display.display();
}