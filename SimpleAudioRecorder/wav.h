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
	Wav();
	Wav(string c_id, string c_s, string f, string sc1_id, int sc1_s, int a_f, int n_ch, int s_r, int b_r, int b_a, int b_p_s, string sc2_id, string sc2_s);
	Wav(const Wav &source);
	~Wav();
	
	void write_as_bytes(ofstream& file, int value, int byte_size);

	// setters
	void set_chunk_id(string in);
	void set_chunk_size(string in);
	void set_format(string in);
	void set_subchunk1_id(string in);
	void set_subchunk1_size(int in);
	void set_audio_format(int in);
	void set_num_channels(int in);
	void set_sample_rate(int in);
	void set_byte_rate(int in);
	void set_block_align(int in);
	void set_bits_per_sample(int in);
	void set_subchunk2_id(string in);
	void set_subchunk2_size(string in);

	// getters
	string get_chunk_id();
	string get_chunk_size();
	string get_format();
	string get_subchunk1_id();
	int get_subchunk1_size();
	int get_audio_format();
	int get_num_channels();
	int get_sample_rate();
	int get_byte_rate();
	int get_block_align();
	int get_bits_per_sample();
	string get_subchunk2_id();
	string get_subchunk2_size();
};

#endif