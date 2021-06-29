void RGBLed_init()
{
  ledcAttachPin(LEDR, R_channel);
  ledcAttachPin(LEDG, G_channel);
  ledcAttachPin(LEDB, B_channel);

  ledcSetup(R_channel, pwm_Frecuency, pwm_resolution);
  ledcSetup(G_channel, pwm_Frecuency, pwm_resolution);
  ledcSetup(B_channel, pwm_Frecuency, pwm_resolution);
  RGBLed_progress();
}

void RGBLed_color(int i, int j, int k)
{
  ledcWrite(R_channel, i);
  ledcWrite(G_channel, j);
  ledcWrite(B_channel, k);
}

void RGBLed_error(){
   RGBLed_color(255,0,0);
}

void RGBLed_success(){
  RGBLed_color(0,255,0);
}

void RGBLed_progress(){
  RGBLed_color(0,0,255);
}
