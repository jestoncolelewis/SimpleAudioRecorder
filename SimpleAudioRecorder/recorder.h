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
    // int channels;
    // int sampleRate;
    // int bitDepth;
    // ChunkOptions chunkSize;
    bool recording_status;

public:
    // constructors & destructors
    Recorder();
    // Recorder(int c, int s, int b, ChunkOptions chunk);
    Recorder(const Recorder& source);
    ~Recorder();

    // methods
    void start();
    void stop();

    // setters & getters
    // void setChannels(int in);
    // void setSampleRate(int in);
    // void setBitDepth(int in);
    // void setChunkSize(ChunkOptions in);
    void set_recording_status(bool in);

    // int getChannels();
    // int getSampleRate();
    // int getBitDepth();
    // ChunkOptions getChunkSize();
    bool get_recording_status();
};

#endif
