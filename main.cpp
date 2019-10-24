#include "gpioaregisters.hpp" //for GPIOA
#include "gpiocregisters.hpp" //for GPIOC
#include "rccregisters.hpp" //for RCC
int i;
int main()
{
  using namespace std; 
  RCC::AHB1ENR::GPIOAEN::Enable::Set();
  RCC::AHB1ENR::GPIOCEN::Enable::Set();
  GPIOC::MODER::MODER5::Output::Set();
  GPIOC::MODER::MODER8::Output::Set();
  GPIOC::MODER::MODER9::Output::Set();
  
  constexpr uint32_t AdressModer=0x40020000;
  uint32_t* PointerOnModer=reinterpret_cast<uint32_t*>(AdressModer); 
 *PointerOnModer |=1024;
 
 constexpr uint32_t AdressODR5 =0x40020014;
 uint32_t* PointerOnODR5=reinterpret_cast<uint32_t*>(0x40020014); 
 
 constexpr uint32_t AdressODR8 =0x40020814;
 uint32_t* PointerOnODR8=reinterpret_cast<uint32_t*>(0x40020814); 
 
  constexpr uint32_t AdressODR9 =0x40020814;
 uint32_t* PointerOnODR9=reinterpret_cast<uint32_t*>(0x40020814); 


 for( ; ; )
  {
   *PointerOnODR8 |=256; 
   *PointerOnODR9 |=512; 
   *PointerOnODR5 |=32; 
   *PointerOnODR8 &= ~(1<<8); 
   *PointerOnODR9 &= ~(1<<9); 
   *PointerOnODR5 &= ~(1<<5); 
      for(i=0; i<=0; i++)
    {
    i=i;
    }
  }
  return 0;
}
