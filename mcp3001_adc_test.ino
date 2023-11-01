
//MCP_ADC.h LIBRARY AUTHOR: Rob Tillaart da installare 
//L'ADC MCP3001 ha un solo canale ossia può acquisire un solo segnale da un solo sensore 
//Piedino 10 Chip select (attivo basso) 
//Piedino 13 SCL Clock
//Piedino 12 MISO Master In Slave Out
//Non esiste un piedino MOSI Master Out Slave In

#include "MCP_ADC.h"

MCP3001 mcp1;        // Si crea un oggetto di tipo MCP3001. Tutti i moduli sul bus SPI sono inattivi se non 
                    // non si utilizza il chip select

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("MCP_ADC_LIB_VERSION: ");
  Serial.println(MCP_ADC_LIB_VERSION);

  mcp1.begin(10);
 

  Serial.println();
  Serial.println("ADC\tCHAN\tMAXVALUE");
  Serial.print("mcp1\t");
  Serial.print(mcp1.channels()); //Stampa il numero di canali del convertitore
  Serial.print("\t");
  Serial.println(mcp1.maxValue()); //Per capire quanti bit possiede il convertitore ADC mcp3001
  
  Serial.println();
}


void loop()
{
  Serial.print("mcp1:\t");
  for (int channel = 0 ; channel < mcp1.channels(); channel++)
  {
    uint16_t val = mcp1.analogRead(channel);
    Serial.print(val);
    Serial.print("\t\n");
  }
  

  delay(1000);
}



