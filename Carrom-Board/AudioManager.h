#ifndef __AUDIO_MANAGER__
#define __AUDIO_MANAGER__
#include <irrKlang.h>
using namespace irrklang;
class AudioManager{	
	static ISoundEngine *soundEngine;
public:
public:
	AudioManager();
	~AudioManager();
	static void play(const char*,bool=false);
	static void stopAll();
};
#endif
