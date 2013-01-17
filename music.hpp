#ifndef DEF_MUSIC
#define DEF_MUSIC

enum Notes{DO,RE,MI,FA,SOL,LA,SI,NO};
extern const unsigned int tempo;
struct Note { Notes note; unsigned int duration; float repeat; };
extern Note music[];
extern unsigned int sizeMus;

#endif
