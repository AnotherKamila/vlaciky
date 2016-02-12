Vláčiky -- elektronika
----------------------

Vláčik je riadený procesorom priamo na vláčiku (s cieľom zvýšiť zábavu/flexibilitu). Napájanie a riadiaci signál dostáva po koľajniciach, motor ovláda procesor (nie je pripojený priamo na napätie z koľajníc)

Interakcia s okolitým svetom:

- input:
  - **riadiaci signál**: sériová linka, bity prenášané polaritou napätia na koľajniciach (momentálne veľmi jednoduchý protokol, ak bude treba, je možné prerobiť na USART; schéma navrhnutá tak, aby krátka strata kontaktu kvôli špinavým koľajniciam nerobila problém s napájaním ani so signálom)
  - **optický člen** zo spodu: na koľajnice je možné umiestniť značky, ktoré vláčik môže čítať, a zachovať sa podľa nich  
  možné využitie:
    - keďže vláčik sa hýbe, je možné prečítať viacbitovú značku
    - značky v pravidelných rozostupoch umožnia zisťovať rýchlosť (a dá sa kombinovať s predošlým)
    - značky môžu nie len kódovať polohu, ale aj ľubovoľne meniť správanie -- dá sa spraviť zhruba čokoľvek

- output: motor ovládaný H-bridge driverom (pripojený na PWM output) -- umožňuje pohyb ľubovoľnou rýchlosťou obomi smermi

Použité súčiastky:

ATmega8 (DIP package)
: 8bit mikrokontroler, má timer (použijem na PWM) a ADC (použijem na vstup z optického člena)

Raspberry Pi controller
: polarita napätia na koľajniciach riadená cez jeho GPIO

zdroj
: adaptér z notebooku -- výstup 16V DC, zrazím na 12V pomocou lineárneho regulátora

L298N Multiwatt15 dual full-bridge driver
: IC obsahujúci 2 H-mostíky ([datasheet](http://www.gme.sk/img/cache/doc/332/005/l298n-datasheet-1.pdf)) *(na schéme ozn. `MW15`)*

CNY70 reflektívny optický senzor
: fototranzistor s integrovanou IR LED ([datasheet](http://www.vishay.com/docs/83751/cny70.pdf))

![schéma](scheme.jpg)
