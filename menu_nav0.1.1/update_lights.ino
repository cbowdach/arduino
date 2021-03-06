
void update_lights(){

  
  
  float temp_intensity = (float)current_intensity / 255;
  float temp_red = (float)current_red * temp_intensity;
  float temp_green = (float)current_green * temp_intensity;
  float temp_blue = (float)current_blue * temp_intensity;
  
  
//  Serial.print(current_intensity);
//  Serial.print("\t");
//  Serial.print(current_red);
//  Serial.print("\t");
//  Serial.print(current_green);
//  Serial.print("\t");
//  Serial.print(current_blue);
//  Serial.print("\t");
//  Serial.print((int)temp_intensity);
//  Serial.print("\t");
//  Serial.print((int)temp_red);
//  Serial.print("\t");
//  Serial.print((int)temp_green);
//  Serial.print("\t");
//  Serial.println((int)temp_blue);
  
  
  update_button_color((int)temp_red, (int)temp_green, (int)temp_blue);
  
  color_update(driver_side_strip.Color((int)temp_red, (int)temp_green, (int)temp_blue));
  Serial.print((float)temp_intensity);
  Serial.print("\t");
  Serial.print((int)temp_red);
  Serial.print("\t");
  Serial.print((int)temp_green);
  Serial.print("\t");
  Serial.println((int)temp_blue);

  
  driver_side_strip.show();
  passenger_side_strip.show();
  cover_strip.show();
}


void update_button_color(int red, int green, int  blue){
  //the parameters are fed in with 255 being full insensity and 0 being off
  analogWrite(red_led_pin, 255-red);
  analogWrite(green_led_pin, 255-green);
  analogWrite(blue_led_pin, 255-blue);
  
}

void color_update(uint32_t c) {
  for(uint16_t i=0; i<driver_side_strip.numPixels(); i++) {
    driver_side_strip.setPixelColor(i, c);
  }
  for(uint16_t i=0; i<passenger_side_strip.numPixels(); i++) {
    passenger_side_strip.setPixelColor(i, c);
  }
  for(uint16_t i=0; i<cover_strip.numPixels(); i++) {
    cover_strip.setPixelColor(i, c);
  }
  
}
