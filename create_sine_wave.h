#pragma once

#include <iostream>
#include <cmath> // Needed for M_PI, etc.

using namespace std;

const int sampleRate = 48000;

struct SineWave
{
    float FREQ;
    float AMP;
    float ANGLE = 0.0f;
    float OFFSET = 0.0f;

    SineWave(float frequency, float amplitude) : FREQ(frequency), AMP(amplitude)
    {
        OFFSET = 2 * M_PI * FREQ / sampleRate;
    }

    float create()
    {
        auto sine = AMP * sin(ANGLE);
        ANGLE += OFFSET;
        return sine;
    }
};