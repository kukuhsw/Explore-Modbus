#include <ModbusMaster.h>
ModbusMaster node(RS232_COM, 1);
#define address 1
#define byteData 0

void setup()
{
  USB.ON();
  node.begin(9600, SOCKET0);
  USB.println(F("Komunikasi RS232"));
  delay(100);
}

void loop()
{
  int result =  node.writeSingleRegister(address,byteData);

  if (result != 0) {
    USB.println(F("Komunikasi serial berhasil"));
    delay(100);
  } 
  else 
  { 
    USB.print(F("Komunikasi serial gagal"));
    delay(100);
  }
  USB.print("\n");
  delay(1000);
  node.clearResponseBuffer();
}
