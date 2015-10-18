Vláčiky!
========

Layout plan, electronics and such for the model railroad in KSP room at our university.

Big decisions to make
---------------------

- passive or active trains?
  - passive (no CPU, motor powered straight from the rails): simpler, kinda cooler
  - active (motor controlled by an on-board CPU): more possibilities

Notes
-----

- pay attention to the physical & electrical connections when laying down the tracks!
  - esp. at turnouts/crossings
    - do we have turnouts, and how do they work electrically anyway?
  - do we have flexible tracks?
  - note: stick to <= 2% climb
- power
  - how much current?
  - auxiliary stuff (think about what auxiliary stuff we'll need)
  - trains: variable DC (voltage => speed), or pulse (half of an AC wave)
    - pulse helps overcome friction and such, but heat => only for low speeds (but we don't want high speeds anyway)
  - running multiple (passive) trains => separate segments
    - common rail for ground, separate segments for Vcc, if possible
  - note: standard is + on the right :D

Random bullshit:
----------------

- CPU on each train => just power (+ signal?) on tracks, trains could control their motors themselves and move independently
  - encode control signal on tracks by modulating onto power?
  - if this, then no segments => always the same + and - rail => running in both directions on the same track will need some thinking
    - and collision avoidance :D
- NFC reader on each train, NFC tags to let the trains know where they are and do stuff with that info :D
