[6week]Cygwin 설치
===
> intstall from internet -> Direct Connection -> https://ftp.kaist.ac.kr
>> Vim, Git, Gcc를 이용
1) vim (editors)
2) git (devel)
3) gcc (devel)

#### Cygwin Terminal ( ~ = /home)   
> FTPS(windows) != exfat(linux)    
    
```bash
# basic command
$  pwd # /home/admin
$  ls -al
$  mkdir 202444057 # /home/admin
$  cd 202444057 # /home/admin/202444057
$  cd .. # /home/admin
$  cd home/admin/202444057
```
#### Vim ( i : insert |  first(or esc): command )   
> /home/admin/202444057   
```bash
$  vim test.c # vim editors
$  gcc -o test test.c # test.exe(Compile)
$  ./test.exe # output(Hello, World!)
```
#### Tiny OS()
> 
```bash
$  mkdir Blink
$  vim BlinkAppC.nc
$  vim BlinkC.nc
$  vim Makefile
```
- - - 

TinyOS 실습
===

#### BlinkAppC.nc
```c
// NesC
configuration BlinkAppC
{
}
implementation
{
    components MainC, BlinkC, LedsC;
    components new TimerMilliC() as Timer0;

    BlinkC -> MainC.Boot;

    BlinkC.Timer0 -> Timer0;
    BlinkC.Leds -> LedsC;
}
```
#### BlickC.nc
```c
// NesC
#include "Timer.h"

module BlinkC @safe()
{
    uses interface Timer<TMilli> as Timer();
    uses interface Leds;
    uses interface Boot;
}
implementation
{
    event void Boot.booted()
    {
        call Timer0.startPeriodic(250);
    }
    event void Timer0.fired()
    {
        call Leds.led0Toggle();
    }
}
```
#### Makefile
```makefile
  COMPONENT=BlinkAppC
  include $(MAKERULES)
```
- - -
이론
===
[[6주차] - 이론](https://github.com/Jeong8537/IOT/wiki/6week)