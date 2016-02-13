Vláčiky -- elektronika
----------------------

Vláčik je riadený procesorom priamo na vláčiku (s cieľom zvýšiť zábavu/flexibilitu). Napájanie a riadiaci signál dostáva po koľajniciach. Motor nie je pripojený priamo na napätie z koľajníc -- ovláda ho procesor.

Interakcia s okolitým svetom:

- input:
  - **riadiaci signál**: sériová linka, bity prenášané polaritou napätia na koľajniciach (momentálne veľmi jednoduchý protokol, ak bude treba, je možné prerobiť na USART; schéma navrhnutá tak, aby krátka strata kontaktu kvôli špinavým koľajniciam nerobila problém s napájaním ani so signálom)
  - **optický člen** zospodu: na koľajnice je možné umiestniť značky, ktoré vláčik môže čítať, a zachovať sa podľa nich.  
  Poznámky:
    - keďže vláčik sa hýbe, je možné prečítať viacbitovú značku
    - značky v pravidelných rozostupoch umožnia zisťovať rýchlosť (a dá sa kombinovať s predošlým)
    - značky môžu nie len kódovať polohu, ale aj ľubovoľne meniť správanie -- dá sa spraviť zhruba čokoľvek

- output:
  - motor ovládaný H-bridge driverom (pripojený na PWM output) -- umožňuje pohyb ľubovoľnou rýchlosťou obomi smermi
  - predné svetlo: pre efekt i úžitok (debugging 1 LEDkou je super!)

Použité súčiastky:

- **ATmega8 (DIP package)**: 8bit mikrokontroler, má timer (použijem na PWM) a ADC (použijem na vstup z optického člena)
- **Raspberry Pi controller**: polarita napätia na koľajniciach riadená cez jeho GPIO
- **zdroj**: adaptér z notebooku -- výstup 16V DC, zrazím na 12V pomocou lineárneho regulátora
- **L298N Multiwatt15 dual full-bridge driver**: IC obsahujúci 2 H-mostíky ([datasheet](http://www.gme.sk/img/cache/doc/332/005/l298n-datasheet-1.pdf)) *(na schéme ozn. `MW15`)*
- **CNY70 reflektívny optický senzor**: fototranzistor s integrovanou IR LED ([datasheet](http://www.vishay.com/docs/83751/cny70.pdf)) *(ozn. `CNY70`)*

![schéma](scheme.jpg)

Plán je v budúcnosti vymeniť ATmega8 za [NodeMCU](http://nodemcu.com/index_en.html) -- dá sa príjemne skriptovať (a má wifi!).

<!-- Poznámka: táto konkrétna lokomotíva potrebuje pre plynulý chod 14V (kvôli mechanickému poškodeniu podvozku sa pri 12V zadrháva). Vďaka tomu má vynikajúci zvuk! -->
