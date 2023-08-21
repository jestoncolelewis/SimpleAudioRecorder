//
//  recorder.cpp
//  SimpleAudioRecorder
//
//  Created by Jeston Lewis on 8/13/23.
//

#include "recorder.h"
#include "wav.h"

// constructors & destructors
Recorder::Recorder() {
    recording_status = false;
}

// Recorder::Recorder(int c, int s, int b, ChunkOptions chunk) : channels(c), sampleRate(s), bitDepth(b), chunkSize(chunk) {}

Recorder::Recorder(const Recorder& source) /* : channels(source.channels), sampleRate(source.sampleRate), bitDepth(source.bitDepth), chunkSize(source.chunkSize) */ {
    recording_status = source.recording_status;
}

Recorder::~Recorder() {}

// methods
void Recorder::start() {
    set_recording_status(true);
    Wav wav_data;
    ofstream wav;
    wav.open("test.wav", ios::binary);

    if (wav.is_open()) {
        std::cout << "Recording started" << std::endl;

        wav << wav_data.get_chunk_id();
        wav << wav_data.get_chunk_size();
        wav << wav_data.get_format();

        wav << wav_data.get_subchunk1_id();
        wav_data.write_as_bytes(wav, wav_data.get_subchunk1_size(), 4);
        wav_data.write_as_bytes(wav, wav_data.get_audio_format(), 2);
        wav_data.write_as_bytes(wav, wav_data.get_num_channels(), 2);
        wav_data.write_as_bytes(wav, wav_data.get_sample_rate(), 4);
        wav_data.write_as_bytes(wav, wav_data.get_byte_rate(), 4);
        wav_data.write_as_bytes(wav, wav_data.get_block_align(), 2);
        wav_data.write_as_bytes(wav, wav_data.get_bits_per_sample(), 2);

        wav << wav_data.get_subchunk2_id();
        wav << wav_data.get_subchunk2_size();

        int start_audio = wav.tellp();

        int i = 0;
        while (get_recording_status()) { // convert to while loop for continuos recording?
            double amplitude = (double)i / wav_data.get_sample_rate() * 32767; // replace 32767
            double value = sin((2 * 3.14 * i * 250) / wav_data.get_sample_rate()); // replace 250

            double channel1 = (amplitude * value) / 2;
            double channel2 = (32767 - amplitude) * value; // replace 32767

            wav_data.write_as_bytes(wav, channel1, 2);
            wav_data.write_as_bytes(wav, channel2, 2);
            ++i;
            if (i == wav_data.get_sample_rate() * 2) // remove for production
                this->stop();
        }

        int end_audio = wav.tellp();
        wav.seekp(start_audio - 4);
        wav_data.write_as_bytes(wav, end_audio - start_audio, 4);

        wav.seekp(4, ios::beg);
        wav_data.write_as_bytes(wav, end_audio - 8, 4);
    }
    wav.close();

    std::cout << "Recording stopped" << std::endl;
}

void Recorder::stop() {
    set_recording_status(false);
}

// setters & getters
/* void Recorder::setChannels(int in) {
    channels = in;
}
void Recorder::setSampleRate(int in) {
    sampleRate = in;
}
void Recorder::setBitDepth(int in) {
    bitDepth = in;
}
void Recorder::setChunkSize(ChunkOptions in) {
    chunkSize = in;
} */
void Recorder::set_recording_status(bool in) {
    recording_status = in;
}

/* int Recorder::getChannels() {
    return channels;
}
int Recorder::getSampleRate() {
    return sampleRate;
}
int Recorder::getBitDepth() {
    return bitDepth;
}
ChunkOptions Recorder::getChunkSize() {
    int chunk_int;
    switch (chunkSize) {
    case ONETWOEIGHT:
        chunk_int = 128;
        break;
    case TWOFIVESIX:
        chunk_int = 256;
        break;
    case FIVEONETWO:
        chunk_int = 512;
        break;
    case TENTWOFOUR:
        chunk_int = 1024;
        break;
    case TWENTYFOUREIGHT:
        chunk_int = 2048;
        break;
    }
    return chunkSize;
} */
bool Recorder::get_recording_status() {
    return recording_status;
}
