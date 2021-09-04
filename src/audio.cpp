#include <festival/festival.h>
#include <SFML/Audio/Music.hpp>

void InitFestival() {
    // EST_Wave wave;
    int heap_size = 2100000;  // default scheme heap size
    int load_init_files = 1; // we want the festival init files loaded

    // initialize festival
    festival_initialize(load_init_files,heap_size);
}

// Text to Speech - gives Dalek a voice
void SaySomething(char const  *sentence) {
    // select a voice
    festival_eval_command("(voice_rab_diphone)");
    // say some text;
    festival_say_text(sentence);
} 

// Play ogg music - uses smfl 
// Simple and Fast Multimedia Library
int PlaySong(char const *song) {
    sf::Music music;
    if (!music.openFromFile(song))
        return 1; // error
    music.play();
    // loop while still playing
    while(music.getStatus() == sf::Music::Playing) {
        // Leave some CPU time for other processes
        usleep(100000);
    }
    return 0;
}
