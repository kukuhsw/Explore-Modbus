#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>
modbusDevice regBank;
modbusSlave slave;

#define RS485TxEnablePin 2
#define RS485Baud 9600
#define RS485Format SERIAL_8E1


#define LED1 11
#define LED2 12

void setup()
{   
//Tentukan ID modbus  
  regBank.setId(1);

//Tambahkan Analog Input
  regBank.add(30001);  
  regBank.add(30002);  
 

//Tambahkan Analog Output
  regBank.add(40001);  
  regBank.add(40002);


  slave._device = &regBank;  

  slave.setBaud(&Serial,RS485Baud,RS485Format,RS485TxEnablePin);   
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT); 
}
