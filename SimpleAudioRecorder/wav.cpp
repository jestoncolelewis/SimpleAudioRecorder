//
//  wav.cpp
//  SimpleAudioRecorder
//
//  Created by Jeston Lewis on 8/19/23.
//

#include "wav.h"

Wav::Wav() {
	chunk_id = "RIFF";
	chunk_size = "----";
	format = "WAVE";

	subchunk1_id = "fmt ";
	subchunk1_size = 16;
	audio_format = 1;
	num_channels = 2;
	sample_rate = 44100;
	byte_rate = sample_rate * num_channels * (subchunk1_size / 8);
	block_align = num_channels * (subchunk1_size / 8);
	bits_per_sample = 16;

	subchunk2_id = "data";
	subchunk2_size = "----";
}

Wav::Wav(string c_id, string c_s, string f, string sc1_id, int sc1_s, int a_f, int n_ch, int s_r, int b_r, int b_a, int b_p_s, string sc2_id, string sc2_s)
	:chunk_id{ c_id }, chunk_size{ c_s }, format{ f }, subchunk1_id{ sc1_id }, subchunk1_size{ sc1_s }, audio_format{ a_f }, num_channels{ n_ch }, sample_rate{ s_r }, byte_rate{ b_r }, block_align{ b_a }, bits_per_sample{ b_p_s }, subchunk2_id{ sc2_id }, subchunk2_size{ sc2_s } {}

Wav::Wav(const Wav &source)
	:chunk_id{ source.chunk_id }, chunk_size{ source.chunk_size }, format{ source.format }, subchunk1_id{ source.subchunk1_id }, subchunk1_size{ source.subchunk1_size }, audio_format{ source.audio_format }, num_channels{ source.num_channels }, sample_rate{ source.sample_rate }, byte_rate{ source.byte_rate }, block_align{ source.block_align }, bits_per_sample{ source.bits_per_sample }, subchunk2_id{ source.subchunk2_id }, subchunk2_size{ source.subchunk2_size } {}

Wav::~Wav() {}

void Wav::write_as_bytes(ofstream& file, int value, int byte_size) {
	file.write(reinterpret_cast<const char*>(&value), byte_size);
}

// setters
void Wav::set_chunk_id(string in) {
	chunk_id = in;
}
void Wav::set_chunk_size(string in) {
	chunk_size = in;
}
void Wav::set_format(string in) {
	format = in;
}
void Wav::set_subchunk1_id(string in) {
	subchunk1_id = in;
}
void Wav::set_subchunk1_size(int in) {
	subchunk1_size = in;
}
void Wav::set_audio_format(int in) {
	audio_format = in;
}
void Wav::set_num_channels(int in) {
	num_channels = in;
}
void Wav::set_sample_rate(int in) {
	sample_rate = in;
}
void Wav::set_byte_rate(int in) {
	byte_rate = in;
}
void Wav::set_block_align(int in) {
	block_align = in;
}
void Wav::set_bits_per_sample(int in) {
	bits_per_sample = in;
}
void Wav::set_subchunk2_id(string in) {
	subchunk2_id = in;
}
void Wav::set_subchunk2_size(string in) {
	subchunk2_size = in;
}

// getters
string Wav::get_chunk_id() {
	return chunk_id;
}
string Wav::get_chunk_size() {
	return chunk_size;
}
string Wav::get_format() {
	return format;
}
string Wav::get_subchunk1_id() {
	return subchunk1_id;
}
int Wav::get_subchunk1_size() {
	return subchunk1_size;
}
int Wav::get_audio_format() {
	return audio_format;
}
int Wav::get_num_channels() {
	return num_channels;
}
int Wav::get_sample_rate() {
	return sample_rate;
}
int Wav::get_byte_rate() {
	return byte_rate;
}
int Wav::get_block_align() {
	return block_align;
}
int Wav::get_bits_per_sample() {
	return bits_per_sample;
}
string Wav::get_subchunk2_id() {
	return subchunk2_id;
}
string Wav::get_subchunk2_size() {
	return subchunk2_size;
}