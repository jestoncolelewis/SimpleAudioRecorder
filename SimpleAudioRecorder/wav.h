//
//  wav.h
//  SimpleAudioRecorder
//
//  Created by Jeston Lewis on 8/18/23.
//

#ifndef wav_h
#define wav_h

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Wav {
private:
	string chunk_id;
	string chunk_size;
	string format;

	string subchunk1_id;
	int subchunk1_size;
	int audio_format;
	int num_channels;
	int sample_rate;
	int byte_rate;
	int block_align;
	int bits_per_sample;

	string subchunk2_id;
	string subchunk2_size;

public:
	Wav(string c_id, string c_s, string f, string sc1_id, int sc1_s, int a_f, int n_ch, int s_r, int b_r, int b_a, int b_p_s, string sc2_id, string sc2_s);
	Wav(const Wav &source);
	~Wav();
	void write_as_bytes(ofstream& file, int value, int byte_size);
};

#endif