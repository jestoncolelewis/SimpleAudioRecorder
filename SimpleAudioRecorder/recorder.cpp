//
//  recorder.cpp
//  SimpleAudioRecorder
//
//  Created by Jeston Lewis on 8/13/23.
//

#include "recorder.h"

// MARK: constructors & destructors
Recorder::Recorder(int c, int s, int b, ChunkOptions chunk) : channels(c), sampleRate(s), bitDepth(b), chunkSize(chunk) {}

Recorder::Recorder(const Recorder& source) : channels(source.channels), sampleRate(source.sampleRate), bitDepth(source.bitDepth), chunkSize(source.chunkSize) {}

Recorder::~Recorder() {}

// MARK: methods
void Recorder::start() {
    std::cout << "Recording started" << std::endl;
}

void Recorder::stop() {
    std::cout << "Recording stopped" << std::endl;
}

// MARK: setters & getters
void Recorder::setChannels(int in) {
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
}

int Recorder::getChannels() {
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
}
