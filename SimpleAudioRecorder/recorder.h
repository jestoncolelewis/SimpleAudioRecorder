//
//  recorder.h
//  SimpleAudioRecorder
//
//  Created by Jeston Lewis on 8/13/23.
//

#ifndef recorder_h
#define recorder_h

#include <iostream>
#include "chunkOptions.h"

class Recorder {
    // channels
    int channels;
    // sample rate
    int sampleRate;
    // bit depth
    int bitDepth;
    // chunk size
    ChunkOptions chunkSize;

public:
    // MARK: constructors & destructors
    Recorder(int c, int s, int b, ChunkOptions chunk);
    Recorder(const Recorder& source);
    ~Recorder();

    // MARK: methods
    // start record
    void start();
    // stop record
    void stop();

    // MARK: setters & getters
    // set channels
    void setChannels(int in);
    // set sample rate
    void setSampleRate(int in);
    // set bit depth
    void setBitDepth(int in);
    // set chunk
    void setChunkSize(ChunkOptions in);

    // get channels
    int getChannels();
    // get sample rate
    int getSampleRate();
    // get bit depth
    int getBitDepth();
    // get chunk
    ChunkOptions getChunkSize();
};

#endif
